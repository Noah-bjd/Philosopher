#include "philosopher.h"
void get_philo(t_info *input)
{
    int i;

    i = input->np;
    while(--i >= 0)
    {
        input->philo[i].id = i;
        input->philo[i].
    }
}
int mutex(t_info *input)
{
    int i;
    
    i = input->np;
    while(--i >= 0)
    {
        if(pthread_mutex_init(&(input->philo->fork[i]), NULL))
            return(1);
    }
    if(pthread_mutex_init(&(input->write), NULL))
        return(1);
    get_philo(input);
    return(0);
}