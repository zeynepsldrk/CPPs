#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <sstream>
#include <iostream>

class PhoneBook
{
    private:
        Contact contacts[8];
        int totalContacts;
        int takeField(std::string &field, const std::string output);

    public:
        PhoneBook();
        ~PhoneBook();
        void addContact();
        void searchContact() const;
        
};

#endif