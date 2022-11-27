#include "philosopher.h"
char    ft_perror(char *str)
{
    int i;

    i = 0;
    while(str[i])
        write(1, &str[i++], 1);
    write(1, "\n", 1);
    return(*str);
}
int main(int argc, char *argv[])
{
    t_info philo;
    if (argc != 5 && argc != 6)
        return(ft_perror("5 or 6 argv"));
    if (init(argc, argv, &philo))
        return(ft_perror("problem during initialization"));
    start_routine(&philo);
    return 0;
}
