#include <string>
#include <iostream>

int main(void)
{
	std::string note = "HI THIS IS BRAIN";
	std::string *stringPTR;
	std::string &stringREF = note; //refernası tanımladın mı bağlayacaksın. ref oluşturdun gari başka nesneye bağlayamazsın

	stringPTR = &note;

	std::cout << &note << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << note << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return 0;
}
