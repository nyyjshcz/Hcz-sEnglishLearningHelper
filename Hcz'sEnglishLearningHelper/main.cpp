#include<iostream>
#include"translator.h"
#include"WordManager.h"
#include <locale.h>
#include"conversion_wstring_string.h"
#include <nlohmann/json.hpp>
void main_page()
{
	while (1)
	{
		system("cls");
		std::cout << "1：单词翻译 2：单词管理器\n";
		std::string op;
		std::cin >> op;
		if (op == "1")
		{
			start_hczs_translator();
		}
		else if(op=="q"||op=="esc")
		{
			exit(0);
		}
		else if (op == "2")
		{
			hcz_start_word_manager();
		}
	}
}
std::string readchinese()
{
	std::wstring s;
	std::wcin >> s;
	std::string ret=to_byte_string(s);
	return ret;
}
int main()
{
	SetConsoleOutputCP(CP_UTF8);
	main_page();
	return 0;
}