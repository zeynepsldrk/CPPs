#include "Zombie.hpp"

int main(void)
{
    Zombie *heapZombie;
    
    std::cout << "Heap zombie -1- created." << std::endl;

    heapZombie = newZombie("A");
    heapZombie->announce();

    std::cout << "Heap zombie -2- created." << std::endl;

    Zombie *heapZombie2 = newZombie("B");
    (*heapZombie2).announce();

    std::cout << "Stack zombie created." << std::endl;

    Zombie stackZombie("C");
    stackZombie.announce();

    std::cout << "Deleting heap zombie -1-." << std::endl;
    delete heapZombie;
    
    std::cout << "Deleting heap zombie -2-." << std::endl;
    delete heapZombie2;

}