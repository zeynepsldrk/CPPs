#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	_name = ""; //null atayamayız null pointerlar içindir string nesnesine mutlaka bellekte değeri olan bir değer tutmalıdır.
	_hitPoint = 10; //aldığı hasara karşı sahip olduğu can miktarı
	_energyPoint = 10;
	_attackDamage = 0; //verdiği hasar miktarı
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoint = copy._hitPoint;
		this->_energyPoint = copy._energyPoint;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor with the name parameter called" << std::endl;
	this->_name = name;
	this->_hitPoint = 10;
	this->_energyPoint = 10;
	this->_attackDamage = 0;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoint <= 0 || _hitPoint <= 0)
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
	_energyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hitPoint)
		_hitPoint = 0;
	else
		_hitPoint -= amount;
	if(_name == "")
	{
		std::cout << "ClapTrap NULL takes " << amount << 
			" points of damage! Remaining hit points: " << _hitPoint <<  " and energy points: " << _energyPoint << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << 
			" points of damage! Remaining hit points: " << _hitPoint <<  " and energy points: " << _energyPoint << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint <= 0 || _hitPoint <= 0)
	{
		if(_name == "")
			std::cout << "ClapTrap NULL has no energy or hit points left!" << std::endl;
		else
			std::cout << "ClapTrap " << _name << " has no energy or hit points left!" << std::endl;
		return;
	}
	_energyPoint--;
	_hitPoint += amount;
	if(_name == "")
		std::cout << "ClapTrap NULL" << " is repaired by " << amount << 
		" points! Remaining hit points: " << _hitPoint << " and energy points: " << _energyPoint << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " is repaired by " << amount << 
			" points! Remaining hit points: " << _hitPoint << " and energy points: " << _energyPoint << std::endl;
	}
}