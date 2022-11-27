#include "philo.h"

void    print_msg(t_input *info, char *str, int id)
{
    pthread_mutex_lock(&(info->write));
    if(!(info->rip))
        printf("%lli\t%i %s\n", current_t(info), id + 1, str);
    pthread_mutex_unlock(&(info->write));
    return ;
}