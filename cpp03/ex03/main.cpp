#include "DiamondTrap.hpp"

int main()
{

    DiamondTrap d1("Diamond");
    d1.whoAmI();

    std::cout <<"**Use ScavTrap's attack func.**" << std::endl;
    d1.attack("Target");   
  
    std::cout <<"**Inheritance Claptrap func.**" << std::endl;
    d1.takeDamage(30);
    d1.beRepaired(10);

    std::cout <<"**Inheritance Scavtrap and Fragtrap func.**" << std::endl;
    d1.guardGate();
    d1.highFivesGuys();

    std::cout <<"**Must be same name testing for copy constr.**" << std::endl;
    DiamondTrap d2(d1);
    d2.whoAmI();

    std::cout << "**Check warning messages**" << std::endl;
    DiamondTrap A;
    int i = 0;
    while(i < 52)
    {
        A.attack("B");
        i++;
    }

    DiamondTrap C("C");
    C.takeDamage(100);
    C.attack("D");
    C.beRepaired(5);
    C.whoAmI();
    C.guardGate();
    C.highFivesGuys();

    std::cout <<"Desturctors:" << std::endl;

    return 0;
}