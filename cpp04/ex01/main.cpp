#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal a;
    a.makeSound();

    Animal *b = new Cat();
    b->makeSound();

    Brain* brain1;
    int i = 0;
    while(i < 5)
    {
        brain1->ideas[i] = "for brain's brain";
        std::cout << brain1->ideas[i] << std::endl;
        i++;
    }

    std::cout << "---------------------" << std::endl;

    brain1 = b->catBrain; //bu olmuyor çünkü aynı sınıfa ait brain nesneleri değiller direkt bu şekilde kullanılamıyor
    /*brain cat ve dog içinde private olmalı.
    deep copy yaptığımı kanıtlamak için cat içine get set hazırlayacağım ki brain e ulaşabileyim dog içinde aynı şeyler geçerli
    İstenen hayvan dizisi oluşturulmamış. main içinde bir Animal ve bir Cat var; yarısı Dog, 
    yarısı Cat olan bir Animal* dizisi oluşturulmalı. Örneğin 10 elemanın 5’i new Dog(), 
    5’i new Cat() olabilir.
    delete ler eksik
    
    */

    i = 0;
    while(i < 5)
    {
        std::cout << brain1->ideas[i] << std::endl;
        i++;
    }

    return 0;
}