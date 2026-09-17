#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon){}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << getType() << std::endl;
}