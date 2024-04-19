#include"httplib.h"
#include"MD5.h"
#include<iostream>
#include"json.hpp"
#include<string.h>
std::string translate(std::string str) {
	std::srand(time(0));
	std::string from = "en", to = "zh", appid = "20240419002029316", salt = std::to_string(rand()), key = "wV4UyQo7nPAYd1YMUled";
	std::string temURL = "http://api.fanyi.baidu.com";
	std::string sign = appid + str + salt + key;
	sign = MD5(sign).toStr();
	std::string URL = "/api/trans/vip/translate?q=" + str + "&from=" + from + "&to=" + to + "&appid=" + appid + "&salt=" + salt + "&sign=" + sign;
	httplib::Client cli(temURL);
	auto res = cli.Get(URL);
	if (res->status != 200)return "internet error:" + std::to_string(res->status);
	std::string ret = res->body;
	nlohmann::json js = nlohmann::json::parse(ret);
	if (js.find("error_code") != js.end())return "error_code:" + js["error_code"].get<std::string>() + ",error_msg:" + js["error_msg"].get<std::string>();
	ret = js["trans_result"][0]["dst"].get<std::string>();
	return ret;
}