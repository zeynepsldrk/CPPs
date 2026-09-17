#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContacts(0) {} //int bir ilkel (primitive) tiptir, sınıf değildir. Primitive tiplerin "default constructor"ı diye bir şey yoktur
// eğer sen elle bir değer vermezsen, çöp (garbage) değer kalır, yani bellekte o an ne varsa o kalır
PhoneBook::~PhoneBook() {}

int PhoneBook::takeField(std::string &field, const std::string output) //referans ile field gönderdim çünkü referans null olamaz pointer null olabilir.
{
    while (1)
    {
        std::cout << "Enter a " << output;
        std::getline(std::cin, field);
        if (std::cin.eof())
            return (1);
        bool isBlank = true;
        for (size_t i = 0; i < field.size(); i++)
        {
            if (!std::isspace((unsigned char)(field[i]))) //cast ediyoruz çünkü isspace int alır char karkterlerde işaretli karakterler 
            //de var onların oluşturabileceği sorunları engellemk için işaretsiz char a cast ederiz
            {
                isBlank = false;
                break;
            }
        }
        if (field.empty() || isBlank)
            continue;
        else
            return (0);
    }
}

void PhoneBook::addContact()
{
    int index = 0;
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

    if (count == 5) //5 alanda sorunsuz doldurulduysa, yani boş alan yoksa, contact eklenir
    {
        index = totalContacts % 8;

        contacts[index].setFirstName(firstName);
        contacts[index].setLastName(lastName);
        contacts[index].setNickName(nickName);
        contacts[index].setPhoneNumber(phoneNumber);
        contacts[index].setDarkestSecret(darkestSecret);

        totalContacts++;

        std::cout << "Contact added!" << std::endl;        
    }
}

void PhoneBook::searchContact() const
{
    if (totalContacts == 0)
    {
        std::cout << "No contacts found." << std::endl;
        return;
    }
    
    std::cout << "|" <<std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << "|" <<std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    int i = 0;
    while (i < totalContacts && i < 8)
    {
        std::cout << "|" << std::setw(10) << std::right << i + 1 << "|";
        if (contacts[i].getFirstName().length() > 10)
            std::cout << std::setw(10) << std::right << contacts[i].getFirstName().substr(0, 9) + "." << "|";
        else
            std::cout << std::setw(10) << std::right << contacts[i].getFirstName() << "|";
        if (contacts[i].getLastName().length() > 10)
            std::cout << std::setw(10) << std::right << contacts[i].getLastName().substr(0, 9) + "." << "|";
        else
            std::cout << std::setw(10) << std::right << contacts[i].getLastName() << "|";
        if (contacts[i].getNickName().length() > 10)
            std::cout << std::setw(10) << std::right << contacts[i].getNickName().substr(0, 9) + "." << "|" << std::endl;
        else
            std::cout << std::setw(10) << std::right << contacts[i].getNickName() << "|" << std::endl;
        i++;
    }

    /*
    stringstream, bir string'i sanki bir giriş akışı gibi kullanmanı sağlıyor
    yani std::cin gibi davranıyor ama klavyeden değil, senin verdiğin string'den okuyor.
    Neden cin >> prompt yerine bunu kullanıyoruz da hata olmuyor?
    Çünkü burada risk aldığımız yer zaten güvenli hale getirilmiş: ss'in içine koyduğumuz 
    promptStr'in her karakterinin rakam olduğunu zaten önceden isNumber kontrolüyle doğrulamıştık.
    Yani ss >> prompt işlemi asla "geçersiz" bir string ile karşılaşmıyor, bu yüzden stringstream'in kendi failbit'i devreye girmiyor.
    cin'i doğrudan kullanmadığımız için de programın ana giriş akışı (std::cin) hiç bozulmuyor.
    */

    std::string promptStr;
    int prompt;

    std::cout << std::endl;
    std::cout << "Enter the index of the contact to view details: ";
    std::getline(std::cin, promptStr);
    std::stringstream ss(promptStr);

    if (!(ss >> prompt) || prompt < 1 || prompt > totalContacts || prompt > 8)
    {
        std::cout << "Non-existent contact." << std::endl;
    }
    else
    {
        std::cout << "First Name: " << contacts[prompt - 1].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[prompt - 1].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[prompt - 1].getNickName() << std::endl;
        std::cout << "Phone Number: " << contacts[prompt - 1].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contacts[prompt - 1].getDarkestSecret() << std::endl;
    }
    std::cout << std::endl;
}