#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "----------------------" << std::endl;

    WrongAnimal* wrongAnimal = new WrongAnimal();
    WrongAnimal* a = new WrongCat();
    std::cout << a->getType() << " " << std::endl;
    a->makeSound();
    wrongAnimal->makeSound();

    std::cout << "----------------------" << std::endl;

    delete i;
    delete j;
    delete meta;
    delete a;
    delete wrongAnimal;

    return 0;
}