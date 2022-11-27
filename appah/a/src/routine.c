/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:53:17 by beadam            #+#    #+#             */
/*   Updated: 2022/09/02 17:50:48 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_usleep(long time)
{
	long	now;

	now = get_time();
	while (get_time() - now < time)
		usleep(10);
}

static void	routine2(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->printing);
	printf("%ld %d is sleeping\n", current_time(philo), philo->index);
	pthread_mutex_unlock(&philo->info->printing);
	ft_usleep(philo->info->sleep);
	pthread_mutex_lock(&philo->info->printing);
	printf("%ld %d is thinking\n", current_time(philo), philo->index);
	pthread_mutex_unlock(&philo->info->printing);
}

static void	routine(t_philo *philo)
{
	long	lock_time;

	while (true)
	{
		pthread_mutex_lock(&philo->fork);
		lock_time = current_time(philo);
		pthread_mutex_lock(&philo->info->printing);
		printf("%ld %d has taken a fork\n", lock_time, philo->index);
		pthread_mutex_unlock(&philo->info->printing);
		pthread_mutex_lock(&philo->next->fork);
		lock_time = current_time(philo);
		pthread_mutex_lock(&philo->info->printing);
		printf("%ld %d has taken a fork\n", lock_time, philo->index);
		printf("%ld %d is eating\n", lock_time, philo->index);
		pthread_mutex_unlock(&philo->info->printing);
		philo->last_meal = get_time();
		philo->eats++;
		ft_usleep(philo->info->eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		routine2(philo);
	}
}

void	begin(t_philo *top)
{
	int		i;
	t_philo	*philo;

	i = 1;
	philo = top;
	while (i <= top->info->nbr)
	{
		pthread_create(&philo->thread, NULL, (void *)routine, philo);
		philo = philo->next;
		ft_usleep(100);
		i++;
	}
}
