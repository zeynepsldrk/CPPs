#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("Serena");
    scavTrap.attack("Target");
    scavTrap.guardGate();
    scavTrap.takeDamage(5);
    scavTrap.beRepaired(3);
    scavTrap.attack("Another Target");

    std::cout << "*****************" << std::endl;

    ScavTrap anotherScavTrap;
    anotherScavTrap.attack("Enemy");
    anotherScavTrap.guardGate();
    anotherScavTrap.takeDamage(99);
    anotherScavTrap.beRepaired(10);
    anotherScavTrap.takeDamage(11);
    anotherScavTrap.beRepaired(5);

    return 0;
}