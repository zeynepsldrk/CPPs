#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int ac, char **av) 
{
    PhoneBook phoneBook;
    std::string input;

    (void)av;
    if(ac != 1)
    {
        std::cout << "Usage: ./phonebook" << std::endl;
        return 1;
    }
    while (1) {
        std::cout << "SELECT AN ACTION -> ADD, SEARCH, EXIT: ";
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
        else
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
    }
    return 0;
}