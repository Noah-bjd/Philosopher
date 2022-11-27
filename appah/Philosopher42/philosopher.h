/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <Noahbjd20@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:26:12 by nbouljih          #+#    #+#             */
/*   Updated: 2022/11/10 07:59:04 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
typedef struct philo
{
    pthread_t               p_id;
    struct input            *input;
    int                     ate;
    int                     id;
    int                     left_fork;
    int                     right_fork;
    int                     l_meal;
}t_philo;

typedef struct input
{
    int                 died;
    int                 n_philo;
    int                 time_to_eat;
    int                 time_to_die;
    int                 time_to_sleep;
    int                 n_t_philo_eat;
    long long           timegasp;
    pthread_mutex_t     fork[100];
    pthread_mutex_t     speak;
    pthread_mutex_t     meal_c;
    t_philo             *info;
} t_input;

#endif