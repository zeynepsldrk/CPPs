#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : aHasAWeapon(weapon), name(name){}

void HumanA::attack()
{
    std::cout << name << " attacks with their " <<  aHasAWeapon.getType() << std::endl;
}