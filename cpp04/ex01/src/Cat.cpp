#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    type = "Cat";
    catBrain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete catBrain;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    catBrain = new Brain(*other.catBrain);
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        this->type = other.type;
        delete catBrain; //pointer başka bi nesneyi göstreceği için eski
        //nesneyi silmek gerekli. Aslında iki pointer aynı nesneyi gösterebilir
        //ancak bu durumda diğer pointer tarafından nesne değiştirilme riskine sahip olur.
        catBrain = new Brain(*other.catBrain);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meoww" << std::endl;
}
