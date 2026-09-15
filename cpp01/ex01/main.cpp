#include "Zombie.hpp"

int main(void)
{
	int i = 0;
    Zombie *horde;

	horde = zombieHorde(5, "Zombie");

	while (i < 5)
	{
		horde[i].announce();
		i++;
	}

	delete [] horde;

	return 0;
}
