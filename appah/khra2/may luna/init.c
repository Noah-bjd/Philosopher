#include "philosopher.h"
int decimal(char *av)
{
    int i;

    i = 0;
    while(av[i])
    {
        if (av[i] >= '0' && av[i] <= '9')
            i++;
        else
            return(1);
    }
    return(0);
}
int ft_atoi(char *str)
{
    int i;
    int res;

    i = 0;
    res = 0;
    if (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = 10 * res + str[i] - 48;
        i++;
    }
    return(res);
}
int init(int ac, char **av, t_info *input)
{
    int i;
    
    i = 1;
    while(i < ac)
    {
        if(decimal(av[i]))
            return(1);
        i++;
    }
    input->np = ft_atoi(av[1]);
    input->t_die = ft_atoi(av[2]);
    input->t_eat = ft_atoi(av[3]);
    input->t_sleep = ft_atoi(av[4]);
    if(input->n_eat < 0 || input->np < 0 || input->t_die < 0 || input->t_sleep < 0)
        return(printf("inputs > 0"), 1);
    if (av[5])
        {
            input->n_eat = ft_atoi(av[5]);
            if (input->n_eat < 1)
                return(printf("inputs > 0"), 1);
        }
    // if(mutex(input))
    //     return(1);
    return(0);
}