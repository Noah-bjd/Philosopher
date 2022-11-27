#include "philo.h"

int main(int ac, char *av[])
{
    t_input philo;
    if (ac != 5 && ac != 6)
        return(print("wrong set of arguments"));

    if(init(av, ac, &philo))
        return(print("verrify your input"));

    if(start(&philo))
        return(print("problem during the set of the philosophers"));
    while(1);
    return 0;
}
