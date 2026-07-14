#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
    private:
        Contact contacts[8];
        int totalContacts;

    public:
        PhoneBook();
        ~PhoneBook();
        void setTotalContacts(int totalContacts);
        int getTotalContacts() const;
        void addContact();
        void searchContact() const;
};

#endif