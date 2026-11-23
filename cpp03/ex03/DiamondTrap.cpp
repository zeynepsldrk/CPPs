#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    _name = "";
    ClapTrap::_name = _name + "_clap_name";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::DiamondTrap(std::string name)
{
    std::cout << "DiamondTrap parameterized constructor called" << std::endl;
    _name = name;
    ClapTrap::_name = _name + "_clap_name";
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << _name << ", a DiamondTrap!" << std::endl;
    std::cout << "And my ClapTrap name is " << ClapTrap::_name << std::endl;
}
