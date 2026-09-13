#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string name);
        ~Zombie();

        void announce( void ); //<name>: BraiiiiiiinnnzzzZ...
        
};

    Zombie* newZombie( std::string name ); // creates a zombie, names it, and returns it so you can use it outside
                                        // of the function scope
    void randomChump( std::string name ); //creates a zombie, names it, and makes it announce itself

#endif