#include "philo.h"
long long time_diff(long long past, long long pressnt)
{
    return(pressnt- past);
}
void    sleepy_gary(long long t, t_input *info)
{
    long long i;

    i = timestamp();
    while(!(info->rip))
    {
        if (time_diff(i, timestamp()) >= t)
            break;
        usleep(50);
    }
}
//processus of who's going to eat first
void    launch_time(t_philo *philo)
{
    t_input *info;

    info = philo->info;
    pthread_mutex_lock(&(info->fork[philo->l_fork]));
    print_msg(info, "has taken a fork", philo->id);
    pthread_mutex_lock(&(info->fork[philo->r_fork]));
    print_msg(info, "has taken a fork", philo->id);
    pthread_mutex_lock(&(info->meal_c));
    print_msg(info, "is eating", philo->id);
    philo->l_meal = timestamp();
    pthread_mutex_unlock(&(info->meal_c));
    sleepy_gary(info->t_2_eat, info);
    (philo->n_ate)++;
    pthread_mutex_unlock(&(info->fork[philo->l_fork]));
    pthread_mutex_unlock(&(info->fork[philo->r_fork]));
}
void    *fun(void *argv)
{
    t_input *info;
    t_philo *philo;

    philo = (t_philo *)argv;
    info  = philo->info;
    if (philo->id % 2) //asba9ia lol
        usleep(15000);
    while(!info->rip)
    {
        launch_time(philo);
        if(info->done_eating)
            break;
        print_msg(info, "is sleeping", philo->id);
        sleepy_gary(info->t_2_sleep, info);
        print_msg(info, "is thinking", philo->id);
    }
    return  (NULL);
}
void	done(t_input *rules, t_philo *philos)
{
	int i;

	i = -1;
	while (++i < rules->n_philo)
		pthread_join(philos[i].thread_id, NULL);//at  waitihom kamlin
	i = -1;
	while (++i < rules->n_philo)
		pthread_mutex_destroy(&(rules->fork[i]));//destroyi zmar we're donr
	pthread_mutex_destroy(&(rules->write));
}
void pulse(t_philo *p, t_input *info, int i)
{
    pthread_mutex_lock(&(info->meal_c));
	if (time_diff(p[i].l_meal, timestamp()) > info->t_2_die)
	{
		print_msg(info, "died", i);
		info->rip = 1;
	}
}
void	rip_check(t_input *info, t_philo *p)
{
	int i;
	while (!(info->done_eating))
	{
		i = -1;
		while (++i < info->n_philo && !(info->rip))
		{
        pulse(p, info, i);			
        pthread_mutex_unlock(&(info->meal_c));
		usleep(100);
		}
		if (info->rip)
			break ;
		i = 0;
		while (info->t_2_eat != -1 && i < info->n_philo ) //&& p[i].n_ate >= info->n_t_philo_2_eat
			i++;
		if (i == info->n_philo)
			info->done_eating = 1;
	}
}
    /// @brief  function responsible of making the philosopher live, eat, think, sleep, or die
    /// @param philo all the data needed to run the function
    /// @return 0 if successful | 1 if error
int     start(t_input *info)
{
    t_philo *philo;
    int     i;

    i = 0;
    philo = info->philosopher;
    info->chrono = timestamp();
    while(i < info->n_philo)
    {
        if (pthread_create(&(philo[i].thread_id), NULL, fun, &(philo[i])))            
            return(1);
        philo[i].l_meal = timestamp();
        i++;
    }
    rip_check(info, info->philosopher);
    done(info, philo);
    return (0);
}