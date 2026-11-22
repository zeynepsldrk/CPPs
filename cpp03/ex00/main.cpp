#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("A");
    clapTrap.attack("B");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);

    std::cout << "*****************" << std::endl;

    clapTrap.attack("C");
    clapTrap.attack("D");

    clapTrap.beRepaired(10);
    clapTrap.takeDamage(30);
    clapTrap.beRepaired(5);

    std::cout << "*****************" << std::endl;

    ClapTrap namelessClapTrap;
    namelessClapTrap.attack("B");
    namelessClapTrap.takeDamage(4);
    namelessClapTrap.beRepaired(5);

    return 0;
}