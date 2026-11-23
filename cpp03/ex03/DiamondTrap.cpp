#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() //bu şekilde üst sınıfları belirtmeme gerek yok
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    _name = "";
    ClapTrap::_name = _name + "_clap_name";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) //burada gerekli çünkü üst sınıfların kopyalama constructor'larını çağırmam gerekiyor yoksa other ın verileri kullanılmış olmaz
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    _name = other._name;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
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
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
}

void DiamondTrap::whoAmI()
{
    if(_name == "")
    {
        std::cout << "I am NULL" << ", a DiamondTrap!" << std::endl;
        return;
    }
    std::cout << "I am " << _name << ", a DiamondTrap!" << std::endl;
    std::cout << "And my ClapTrap name is " << ClapTrap::_name << std::endl;
}
