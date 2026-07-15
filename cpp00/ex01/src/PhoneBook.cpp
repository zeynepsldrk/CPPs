#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContacts(0) {} //int bir ilkel (primitive) tiptir, sınıf değildir. Primitive tiplerin "default constructor"ı diye bir şey yoktur
// eğer sen elle bir değer vermezsen, çöp (garbage) değer kalır, yani bellekte o an ne varsa o kalır
PhoneBook::~PhoneBook() {}

void PhoneBook::setTotalContacts(int totalContacts)
{
    this->totalContacts = totalContacts;
}

int PhoneBook::getTotalContacts() const
{
    return totalContacts;
}

int PhoneBook::takeField(std::string &field, const std::string output) //referans ile field gönderdim çünkü referans null olamaz pointer null olabilir.
{
    while (1)
    {
        std::cout << "Enter a " << output;
        std::getline(std::cin, field);
        if (std::cin.eof())
            return (1);
        if (field.empty() || field == " ")
            continue;
        else
            return (0);
    }
}

void PhoneBook::addContact() //!! enter girince yeniden isim sormuyor, boşlukta da aynı
{
    int count = 0;
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    while (count < 5)
    {
        if (count == 0)
        {
            if(takeField(firstName, "first name:"))
                break;
            else
                count++;
        }
        else if (count == 1)
        {
            if(takeField(lastName, "last name:"))
                break;
            else
                count++;
        }
        else if (count == 2)
        {
            if(takeField(nickName, "nick name:"))
                break;
            else
                count++;
        }
        else if (count == 3)
        {
            if(takeField(phoneNumber, "phone number:"))
                break;
            else
                count++;
        }
        else if (count  == 4)
        {
            if(takeField(darkestSecret, "secret:"))
                break;
            else
                count++;
        }
    }
    int index = totalContacts % 8;

    contacts[index].setFirstName(firstName);
    contacts[index].setLastName(lastName);
    contacts[index].setNickName(nickName);
    contacts[index].setPhoneNumber(phoneNumber);
    contacts[index].setDarkestSecret(darkestSecret);

    totalContacts++;

    std::cout << "Contact added!" << std::endl;
}

void PhoneBook::searchContact() const
{
    
}