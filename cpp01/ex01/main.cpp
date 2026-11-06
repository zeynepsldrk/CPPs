#include "Zombie.hpp"

int main(void)
{
	int i = 0;
    Zombie *horde;

	horde = zombieHorde(5, "Zombie");

	if (horde == NULL)
	{
		std::cout << "Could not create a zombie army." << std::endl;
		return 1;
	}
	
	while (i < 5)
	{
		horde[i].announce();
		i++;
	}

	delete [] horde;

	return 0;
}
