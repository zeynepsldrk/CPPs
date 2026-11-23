#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    int i = 0;
    while (i < 100)
    {
        ideas[i] = "Default";
        i++;
    }
}

Brain::~Brain()
{
    std::cout << "Brain default destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    int i = 0;
    while (i < 100)
    {
        ideas[i] = other.ideas[i];
        i++;
    }
}
        
Brain& Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy assigment constructor called" << std::endl;
    
    if (this != &other)
    {
        int i = 0;
        while (i < 100)
        {
            ideas[i] = other.ideas[i];
            i++;
        }
    }
    return *this;
}
