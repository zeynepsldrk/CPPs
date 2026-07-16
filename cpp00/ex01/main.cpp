#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() 
{
    PhoneBook phoneBook;
    std::string input;

    while (1) {
        std::cout << "SELECT AN ACTİON -> ADD, SEARCH, EXIT: ";
        std::getline(std::cin, input);

        if (std::cin.eof())
			break ;
        if (input == "ADD")
            phoneBook.addContact();
        else if (input == "SEARCH")
            phoneBook.searchContact();
        else if (input == "EXIT")
        {
            std::cout << "See you later! Alligator (._.)" << std::endl;
            break;
        }
    }
    return 0;
}