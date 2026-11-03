#include "HumanB.hpp"

HumanB::HumanB(std::string name){
    this->name = name;
    this->bHasAWeapon = NULL;
}

void HumanB::setWeapon(Weapon &weapon)
{
    bHasAWeapon = &weapon;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << bHasAWeapon->getType() << std::endl;
}