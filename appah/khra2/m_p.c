#include "philo.h"

int init_philo(t_input *info)
{
    int x;

    x = info->n_philo;
    info->done_eating = 0;
    info->rip = 0;
    while(--x >= 0)
    {
        info->philosopher[x].id = x;
        info->philosopher[x].n_ate = 0;
        info->philosopher[x].l_fork = x;
        info->philosopher[x].r_fork = (x + 1) % info->n_philo;
        // as first I went with the idea of just adding one to each
        // fork but if i = 5 + 1 we'll get 6 which is out of the limit number
        // of fork allowd.
        // so if i = 5 and n_philo = 5
        // f = (i + 1) % n_philo 
        // f = 1
        info->philosopher[x].info = info;
        info->philosopher[x].l_meal = 0;
    }
    return(0);
}
int ft_mutex(t_input *info)
{
    int i;

    //init the mutex
    // fork     each philo will got a fork
    // write    when he'll be able to righ
    // meal_c   check the meal
    if (!info)
        return(1);
    i = info->n_philo;
    while(--i >= 0)
    {
        //init each philo his own fork
        if(pthread_mutex_init(&(info->fork[i]), NULL))
            return(1);
    }
    if (pthread_mutex_init(&(info->meal_c), NULL))
        return(1);
    if(pthread_mutex_init(&(info->write), NULL))
        return(1);
    //init each philo his infos
    // init_philo(info);
    return(0);
}
