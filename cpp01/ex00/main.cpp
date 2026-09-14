#include "Zombie.hpp"

int main(void)
{
    Zombie *heapZombie;
    
    std::cout << "Heap zombie created." << std::endl;

    heapZombie = newZombie("A");
    heapZombie->announce();

    std::cout << heapZombie << std::endl;

    std::cout << "Stack zombie created." << std::endl;

    Zombie stackZombie("B");
    stackZombie.announce();

    std::cout << "Deleting heap zombie." << std::endl;
    delete heapZombie;

}