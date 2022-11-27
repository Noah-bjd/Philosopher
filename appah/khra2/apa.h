#include "philo.h"
void    eat(t_philo *philo)
{
    
}
void    *fun(void *argv)
{
    t_input *info;
    t_philo *philo;
    philo = (t_philo *)argv;
    while(info->done_eating)
    {
        eat(philo);
    }
}
int apa(t_input *info)
{
    t_philo *philo;
    int i;

    i = 0;
    while(i <= info->n_philo)
    {
        if(pthread_create(&(philo->thread_id), NULL, &fun, &(info->philosopher->id)))
            return(1);
    }
}