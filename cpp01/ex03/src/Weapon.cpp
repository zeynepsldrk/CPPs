#include "Weapon.hpp"

Weapon::Weapon(){}

std::string Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string newType)
{
	newType = type;
}