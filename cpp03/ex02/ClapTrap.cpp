#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	_name = ""; //null atayamayız null pointerlar içindir string nesnesine mutlaka bellekte değeri olan bir değer tutmalıdır.
	_hitPoints = 10; //aldığı hasara karşı sahip olduğu can miktarı
	_energyPoints = 10;
	_attackDamage = 0; //verdiği hasar miktarı
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor with the name parameter called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		if(_name == "")
			std::cout << "ClapTrap NULL has no energy or hit points left!" << std::endl;
		else
			std::cout << "ClapTrap " << this->_name << " has no energy or hit points left!" << std::endl;
		return;
	}
	if(_name == "")
		std::cout << "ClapTrap NULL attacks " << target << ", causing " << _attackDamage << 
		" points of damage!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << 
			" points of damage!" << std::endl;
	}
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	if(_name == "")
	{
		std::cout << "ClapTrap NULL takes " << amount << 
			" points of damage! Remaining hit points: " << _hitPoints <<  " and energy points: " << _energyPoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << 
			" points of damage! Remaining hit points: " << _hitPoints <<  " and energy points: " << _energyPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0 || _hitPoints <= 0)
	{
		if(_name == "")
			std::cout << "ClapTrap NULL has no energy or hit points left!" << std::endl;
		else
			std::cout << "ClapTrap " << _name << " has no energy or hit points left!" << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	if(_name == "")
		std::cout << "ClapTrap NULL" << " is repaired by " << amount << 
		" points! Remaining hit points: " << _hitPoints << " and energy points: " << _energyPoints << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " is repaired by " << amount << 
			" points! Remaining hit points: " << _hitPoints << " and energy points: " << _energyPoints << std::endl;
	}
}