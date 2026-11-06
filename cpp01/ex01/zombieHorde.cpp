#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int i = 0;

    Zombie *hordeZombies = new Zombie[N];

	if (N <= 0)
		return NULL;
	while (i < N)
	{
		hordeZombies[i].setName(name);
		i++;
	}

	return hordeZombies;
}
