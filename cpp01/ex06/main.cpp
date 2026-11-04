#include "Harl.hpp"

int main(int ac, char **arg)
{
    Harl comment;
    
    if(ac != 2)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return (1);
    }
    comment.complain(arg[1]);
    return (0);

}