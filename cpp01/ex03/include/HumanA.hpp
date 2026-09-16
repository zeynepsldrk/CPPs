#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon &aHasAWeapon;
		std::string name;

	public:
		HumanA(std:string name, Weapon &weapon);
		void attack();
};

#endif