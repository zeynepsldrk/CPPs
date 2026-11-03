#include <iostream>
#include <string.h>

int main(int ac, char **arg)
{
	//argüman 1: dosya olmalı dolayısıyla açılabilmeli, var olmalı, içeriği okunabilmelidir.
	// diğer iki argüman string olacak dosya içeriğinden ilk argüman aranıp ikinci argümanla yer 
	//değiştirecek ve yeni kopya argüman bir.replace in içine yazılacak.

	if(ac != 4)
	{
		std::cout << "Enter a just three arguments" << std::endl;
		return (1);
	}
	std::string file = arg[1];
	std::string s1 = arg[2];
	std::string s2 = arg[3];
	if(s1.empty() || s2.empty())
	{
		std::cout << "Do not enter an empty string. Enter a string that value arguments." << std::endl;
	}
	
}