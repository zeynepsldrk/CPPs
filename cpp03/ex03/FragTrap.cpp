#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor with the name parameter called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

void FragTrap::highFivesGuys()
{
    if(_name == "")
        std::cout << "FragTrap NULL is saying a high five buddy!" << std::endl;
    else
    std::cout << "FragTrap " << _name << " is saying a high five buddy!" << std::endl;
}

