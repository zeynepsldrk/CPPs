#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    type = "Dog";
    dogBrain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete dogBrain;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    dogBrain = new Brain(*other.dogBrain);
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        this->type = other.type;
        delete dogBrain;
        dogBrain = new Brain(*other.dogBrain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Wooff" << std::endl;
}
