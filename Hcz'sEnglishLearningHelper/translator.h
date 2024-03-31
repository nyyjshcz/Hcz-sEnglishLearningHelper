#include<iostream>
#include"translate.h"
void start_hczs_translator()
{
	system("cls");
	std::cout<<"Welcome to Hcz's translator\nEnter the word or sentence you want to translate and press enter\nEnter esc to exit the Hcz's translator\n";
	while (1) {
		std::string s;
		std::getline(std::cin, s);
		if (s == "")continue;
		if (s == "esc")return;
		std::cout << translate(s) << '\n';
	}
}