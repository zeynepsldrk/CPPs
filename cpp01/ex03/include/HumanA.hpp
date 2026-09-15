#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon aHasAWeapon;
		std::string name;

	public:
		HumanA(Weapon weapon);
		std::string getName() const;
		void setName(std::string name);
		void attack();
};

#endif