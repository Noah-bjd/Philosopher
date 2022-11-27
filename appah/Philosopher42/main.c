/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <Noahbjd20@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:25:24 by nbouljih          #+#    #+#             */
/*   Updated: 2022/11/10 07:55:53 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
char   print_error(char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1, &str[i++], 1);
    return(*str);
// }
// int ft_atoi(char *str)
// {
//     int i;
//     int sign;
//     int result;

//     i = 0;
//     sign = 1;
//     result = 0;
//     while(str[i] == ' ' || str[i] == '\t')
//         i++;
//     if (str[i] == '-')
//         sign = -1;
//     if (str[i] == '=' || str[i] == '+')
//         i++;
//     while(str[i] > '0' && str[i] < '9')
//         {
//             result = result * 10 + str[i] - '0';
//             i++;
//         }
//     return(result * sign);
// }
// int get_mutex(t_input *philo)
// {
//     // n computer programming, a mutex (mutual exclusion object) is a program object that is created so that
//     // multiple program thread can take turns sharing the same resource, such as access to a file.
//     int i;
    
//     i = 0;
//     while(i <= philo->n_philo)
//     {
//         if(pthread_mutex_init(&philo->fork[i], NULL) != 0)
//             return(1);
//         i++;
//     }
//     if (pthread_mutex_init(philo->speak, NULL))
//         return(1);
//     if (pthread_mutex_int(philo->meal_c, NULL))
//         return(1);
//     return(0);
// }
// int    initialize(char **av, t_input *philo)
// {
//     if (!philo)
//         return(print_error("initialization problem"));
//     philo->n_philo =ft_atoi(av[1]);
//     philo->time_to_die = ft_atoi(av[2]);
//     philo->time_to_eat = ft_atoi(av[3]);
//     philo->time_to_sleep = ft_atoi(av[4]);
//     if (philo->n_philo < 2 || philo->time_to_die <= 0 || philo->time_to_eat <= 0
//                 || philo->time_to_sleep <= 0)
//         return(1);
//     if (av[5])
//         {
//             philo->n_t_philo_eat = ft_atoi(av[5]);
//             if (philo->n_t_philo_eat <= 0)
//                 return(1);
//         }
//     else
//         philo->n_t_philo_eat = -1;
//     if (get_mutex(philo))
//         return(1);
//     //philo_info(philo);
//     return(0);
// }
// int   philo(t_input *philo)
// {
//     int i;

//     i = philo->n_philo;
//     while(i <= 0)
//     {
//         philo->info[i].id = i;
//         philo->info[i].left_fork = i;
//         philo->info[i].right_fork = i + 1;
//         philo->info[i].l_meal = 0;
//         i--;
//     }
//     return(0);
// }

int main(int ac, char **av)
{
    
    t_input   philo;
    
    /**
     * [step 1]
     * get the proper arguments asked in the project
     *          [number_of_philosophers]
     *          [time_to_die]
     *          [time_to_eat]
     *          [time_to_sleep]
     *          [number_of_times_each_philosopher_must_eat]
     */
    if (ac != 5 && ac != 6)
        return (print_error("wrong set of arguments : [number_of_philosophers]\n\t\t[time_to_die]\n\t\t[time_to_eat]\n\t\t[time_to_sleep]\n\t\t[number_of_times_each_philosopher_must_eat]"));
    /**
     *  [step 2]
     *  initialize the given infoermation
     */
    /*if (initialize(av, &philo))
        return(print_error("[Check your input]"));*/
    return(0);
}


    // while (ac > 0 &&  *av != '\0')
    // {
    //     printf("%s\n", *av);
    //     ac++;
    //     av++;
    // }