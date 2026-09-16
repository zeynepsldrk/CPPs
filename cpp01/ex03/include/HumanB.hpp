#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *bHasAWeapon;
		std::string name;

	public:
		HumanB(std::string name);
		std::string getName() const;
		void setName(std::string name);
		void attack();
};

#endif