#include <iostream>

int main(int ac, char **argv)
{
    int i = 1;
    int j = 0;

    (void)(ac);
    if (argv[1] != NULL)
    {
        while (argv[i])
        {
            while (argv[i][j])
            {
                std::cout << (char)std::toupper(argv[i][j]);
                j++;
            }
            j = 0;
            i++;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    return (0);
}