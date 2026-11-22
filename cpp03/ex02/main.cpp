#include "FragTrap.hpp"

int main()
{
    FragTrap fragTrap("Serena");
    fragTrap.attack("Target");
    fragTrap.highFivesGuys();
    fragTrap.takeDamage(5);
    fragTrap.beRepaired(3);
    fragTrap.attack("Another Target");
    fragTrap.highFivesGuys();

    std::cout << "*****************" << std::endl;

    FragTrap anotherFragTrap;
    anotherFragTrap.attack("Enemy");
    anotherFragTrap.highFivesGuys();
    anotherFragTrap.takeDamage(99);
    anotherFragTrap.beRepaired(10);
    anotherFragTrap.takeDamage(11);
    anotherFragTrap.beRepaired(5);
    anotherFragTrap.highFivesGuys();

    return 0;
}