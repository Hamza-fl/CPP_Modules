#include <iostream>

int main(int ac, char **av)
{
    int i = 1;
    int j;
    if (ac >= 2)
    {
        while(av[i])
        {
            j = 0;
            while (av[i][j])
            {
                std::cout << (char)toupper(av[i][j]);
                j++;
            }
            i++;
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}
