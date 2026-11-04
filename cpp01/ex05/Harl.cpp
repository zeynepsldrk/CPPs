#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void(Harl::*pointerOfFunctions[4])();

    pointerOfFunctions[0] = &Harl::debug;
    pointerOfFunctions[1] = &Harl::info;
    pointerOfFunctions[2] = &Harl::warning;
    pointerOfFunctions[3] = &Harl::error;

    int i = 0;
    while(i < 4)
    {
        if(levels[i] == level)
        {
            (*this.*pointerOfFunctions[i])();
            break;
        }
        i++;
    }
}
