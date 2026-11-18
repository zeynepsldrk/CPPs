#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	_name = ""; //null atayamayız null pointerlar içindir string nesnesine mutlaka bellekte değeri olan bir değer tutmalıdır.
	_hitPoint = 10;
	_energyPoint = 10;
	_attackDamage = 2;
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
	else
		return *this;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor with the name parameter called" << std::endl;
	this->_name = name;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap <name> attacks <target>, causing <damage> points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{
	//kendini onarırken enerji punanı kaybedecek
}