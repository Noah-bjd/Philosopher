#include "philo.h"
int decimal(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return(1);
    }
    return(0);
}
    /// @brief init the data given in the input
    /// @param philo data \struct which will hold the data passed in the arguments
    /// @param av 5 or 6 arguments \category n_p 2_eat 2_sleep 2_die 2| n_of_time_to_eat
    /// @return 0 if successful  | 1 if error
int init(char **av,int ac, t_input *input)
{
    int i;

    i = 1; // we'll start from the first argv 
    while(i < ac)
    {
        if(decimal(av[i]))
            return(print("\n[Only Intiger]\n"), 1);
        i++;
    }
    input->n_philo = ft_atoi(av[1]);
    input->t_2_die = ft_atoi(av[2]);
    input->t_2_eat = ft_atoi(av[3]);
    input->t_2_sleep = ft_atoi(av[4]);
    if (input->t_2_die < 0 || input->t_2_eat < 0 || input->t_2_sleep < 0)
        return(print("\n[positive value only]\n"), 1);
    if(input->n_philo <= 0)// 
        return(print("\nN of philosophers should be greater than [0]\n"), 1);
    if(av[5]){ 
            input->n_t_philo_2_eat = ft_atoi(av[5]);
            if(input->n_t_philo_2_eat < 0)
                return(1);
             }
    if(ft_mutex(input))
        return(print("\nERROR MUTEX\n"), 1);
    init_philo(input);
    return(0);
}