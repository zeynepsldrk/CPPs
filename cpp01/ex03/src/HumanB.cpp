#include "HumanB.hpp"

HumanB::HumanB(std::string name){}

std::string HumanB::getName() const
{
 return name;
}

void HumanB::setName(std::string name)
{
 this->name = name;
}

void attack()
{
    std::cout << name << " attacks with their " << getType() << std::endl;
}