#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap //public kalıtım hem subject gereksimi hem de super classın public ve protected üyelerine erişim sağlar.
{
    public :
        ScavTrap();
        ScavTrap(const ScavTrap &other);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &other);

        ScavTrap(std::string name);

        void attack(const std::string &target);
        void guardGate();
};

#endif