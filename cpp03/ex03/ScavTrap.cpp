#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) //super class ın copy constr. kullanmasını belirtir. Belirtilmezse default constr. ile boş bir nesne oluşturur ve sonra copy constr. çağrılır. Bu da hataya sebep olur.
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor with the name parameter called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

void ScavTrap::attack(const std::string &target)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		if(_name == "")
			std::cout << "ScavTrap NULL has no energy or hit points left!" << std::endl;
		else
			std::cout << "ScavTrap " << _name << " has no energy or hit points left!" << std::endl;
		return;
	}
	if(_name == "")
		std::cout << "ScavTrap NULL attacks " << target << ", causing " << _attackDamage << 
		" points of damage!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << 
			" points of damage!" << std::endl;
	}
	_energyPoints--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now guarding the gate!" << std::endl;
}

