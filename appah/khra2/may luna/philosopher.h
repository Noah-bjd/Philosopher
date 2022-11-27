#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
typedef struct philo
{
    pthread_t           philo;
    int                 id;
    long                last_meal;
    pthread_mutex_t     fork[200];
    int                 ate;
}t_philo;
typedef struct info
{
    int             np;
    int             t_eat;
    int             t_die;
    int             t_sleep;
    int             n_eat;
    int             full_p;
    long            start;
    pthread_mutex_t write;
    t_philo         philo[200];
}t_info;

int init(int ac, char **av, t_info *input);
#endif