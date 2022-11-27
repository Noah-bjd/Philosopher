#include <threads.h>
#include <unistd.h>
#include "philosopher.h"

//Following is the util function to get current timestamp in milliseconds:
long long timestamp() {
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}
//

void		p_talk(t_input *info, int id, char *str)
{
	pthread_mutex_lock(&(info->speak));
	if (!(info->died))
	{
		printf("%lli ", timestamp() - info->timegasp);
		printf("%i ", id);//+1
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(info->speak));
	return ;
}
//utils
char    print_error(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
    return(*str);
}
int diff(long long s, long long e)
{
    return(s - e);
}
void    sleep_fun(long long time, t_input *philo)
{
    long long t;
    t = timestamp();
	while (!(philo->died))
	{
		if (diff(t, timestamp()) >= time)
			break ;
		usleep(50);
	}
}

int ft_atoi(char *str)
{
    int i;
    int neg;
    int result;

    i = 0;
    neg = 1;
    result = 0;
    if (str[i] == '-')
        neg = -1;
    if(str[i]== '+' || str[i]== '-')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
        {
            result = 10 * result + str[i] - 10;
            i++; 
        }
    return(result * neg);
}


//

//philo's initialization functions
int     ft_mutex(t_input *philo)
{
    int i;
    i = 0;
    while(i <= philo->n_philo)
    {
        if(pthread_mutex_init(&philo->fork[i], NULL))
            return(1);
        i++;
    }
    if(pthread_mutex_init(&philo->speak, NULL))
        return(1);
    if(pthread_mutex_init(&philo->meal_c, NULL))
        return(1);
    return(0);
}
int     init_philo(t_input *info)
{
    int p;
    p = info->n_philo;
    while(p-- >= 0)
    {
        info->info[p].id = p;
        info->info[p].ate = 0;
        info->info[p].left_fork = p;
        info->info[p].right_fork = 1 + p;// % left
        info->info[p].l_meal = 0;
        info->info[p].input = info;
    }
    return(0);
}
int     init(char **av, t_input *philo)
{
    if (!philo)
        return(1);
    philo->n_philo = ft_atoi(av[1]);
    philo->time_to_die = ft_atoi(av[2]);
    philo->time_to_eat = ft_atoi(av[3]);
    philo->time_to_sleep = ft_atoi(av[4]);
    if (philo->n_philo < 2 || philo->time_to_die < 0 ||
        philo->time_to_eat < 0 || philo->time_to_sleep < 0)
            return(1);
    if (av[5])
        {
            philo->n_t_philo_eat =ft_atoi(av[5]);
            if (philo->n_t_philo_eat < 0)
                return(1);
        }
    if (ft_mutex(philo))
        return(2);
    if (init_philo(philo))
        return(3);
    return(0);
}
// 
//function to check when to die


// start philosopher's function
void    get_fork(t_philo *philo)
{
    //time to eat a zin
    t_input *info;

    //n3tih infos
    info = philo->input;
    //mutex fork
    pthread_mutex_lock(&(info->fork[philo->left_fork]));
    //a print function which will lock unlock when to write
    //philo x has taken a fork
    //print action
    p_talk(info, philo->id, "has taken a fork");
    pthread_mutex_lock(&(info->fork[philo->right_fork]));
    p_talk(info, philo->id, "has taken a fork");
    pthread_mutex_lock(&(info->meal_c));
    p_talk(info, philo->id, "is eating");
    philo->l_meal = timestamp();
    pthread_mutex_unlock(&(info->meal_c));
    //hna sf ki yakl after eating the philo has to sleep
    sleep_fun(info->time_to_eat, info);
    //last thing unlock
    philo->ate++;
    pthread_mutex_unlock(&(info->fork[philo->left_fork]));
    pthread_mutex_unlock(&(info->fork[philo->right_fork]));

}


void    *fun(void *argv)
{
    int i;
    t_input *info;
    t_philo *philo;
    int     id;
    i= 0;
    philo = (t_philo *)argv;
    info = philo->input;
    id = philo->id;
    if (id % 2)
        usleep(15000);
    while(!info->died)
    {
        get_fork(philo);
        if (philo->ate)
            sleep(500);
        p_talk(info, philo->id, "is sleeping");
        sleep_fun(info->time_to_sleep, info);
        p_talk(info, philo->id, "is thinking");
        i++;
    }
    return NULL;
}
int     start(t_input *phi)
{
    t_philo *philo;
    int      i;

    philo = phi->info;
    i = 0;
    // i - 1
    //timestab function a
    while(i < phi->n_philo)
    {
        if(pthread_create(&(philo[i].p_id), NULL, &fun, &(phi[i])))
            {
                print_error("\n problem during the creation of the thread\n");
                return(1);
            }
            philo[i].l_meal = timestamp();
            i++;
    }
    return(0);
}
//


int main(int ac , char **av)
{
    t_input  philo;

    if (ac !=5 && ac != 6)
        return (print_error("wrong set of arguments"));
    // if(init(av, &philo))
    //     return(print_error("ERROR occured during initialization"));
    // else
    //     return(print_error("ok"));
    /*if(start(&philo))
        return(print_error("ERROR during execution"));
    return(0);*/
}