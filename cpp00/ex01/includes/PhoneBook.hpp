#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <sstream>
#include <cctype>

class PhoneBook
{
    private:
        Contact contacts[8];
        int totalContacts;
        int index;

    public:
        PhoneBook();
        ~PhoneBook();
        void addContact();
        void searchContact() const;
        int takeField(std::string &field, const std::string output);
};

#endif