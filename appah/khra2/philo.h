#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
typedef struct philo
{
    int                 id;
    int                 n_ate;
    int                 l_fork;
    int                 r_fork;
    pthread_t           thread_id;
    long long           l_meal;
    struct input        *info;
}t_philo;

typedef struct input
{
    int                 rip;
    int                 done_eating;
    int                 n_philo;
    int                 t_2_eat;
    int                 t_2_die;
    int                 t_2_sleep;
    int                 n_t_philo_2_eat;
    t_philo             philosopher[250];
    pthread_mutex_t     fork[250];
    pthread_mutex_t     meal_c;
    pthread_mutex_t     write;
    long long           chrono;
}t_input;

long long       current_t(t_input *info);
long long       timestamp(void);
char            print(char *str);
int             ft_mutex(t_input *info);
int             start(t_input *info);
int             init_philo(t_input *info);
int             ft_atoi(char *str);
int             init_philo(t_input *info);
int             init(char **av, int ac, t_input *input);
void            print_msg(t_input *info, char *str, int id);

#endif