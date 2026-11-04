#include <iostream>
#include <string>
#include <fstream>


int checker(std::string file, std::string s1, std::string s2)
{
	if(s1.empty())
	{
		std::cerr << "Do not enter an empty string. Enter a string that value argument." << std::endl;
		return (1);
	}

	if(s1 == s2)
	{
		std::cerr << "Do not enter the same string. Enter a string that value arguments." << std::endl;
		return (1);
	}

	if(file.empty())
	{
		std::cerr << "Do not enter an empty file. Enter a file that value arguments." << std::endl;
		return (1);
	}

	return (0);
}

std::string replacer(std::string line, std::string s1, std::string s2)
{
	size_t pos = 0;

    while ((pos = line.find(s1)) != std::string::npos)
    {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
		pos += s2.length();
    }
    return line;
}

int searchAndReplace(std::string file, std::string s1, std::string s2)
{
	std::string line;
	std::ifstream streamFile(file.c_str());
	if (!streamFile.is_open())
    {
		std::cerr << "Error: Unable to open file." << std::endl;
		return (1);
	}
	std::ofstream outputFile((file + ".replace").c_str());
	if (!outputFile.is_open())
    {
		std::cerr << "Error: Unable to create output file." << std::endl;
		return (1);
	}
	while(std::getline(streamFile, line))
	{
		line = replacer(line, s1, s2);
        outputFile << line;
	}
	outputFile.close();
	return (0);
}

int main(int ac, char **arg)
{
	if(ac != 4)
	{
		std::cerr << "Enter a just three arguments" << std::endl;
		return (1);
	}
	std::string file = arg[1];
	std::string s1 = arg[2];
	std::string s2 = arg[3];
	if(checker(file, s1, s2) == 1)
		return (1);
	if(searchAndReplace(file, s1, s2) == 1)
		return (1);
	return (0);
}