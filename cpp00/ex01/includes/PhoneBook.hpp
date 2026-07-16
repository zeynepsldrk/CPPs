#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
    private:
        Contact contacts[8];
        int totalContacts;
        int index;

    public:
        PhoneBook();
        ~PhoneBook();
        void setTotalContacts(int totalContacts);
        int getTotalContacts() const;
        void setIndex(int index);
        int getIndex() const;
        void addContact();
        void searchContact() const;
        int takeField(std::string &field, const std::string output);
};

#endif