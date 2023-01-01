/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:22:54 by nbouljih          #+#    #+#             */
/*   Updated: 2023/01/01 19:37:19 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routin(t_philo *philo)
{
	long	time;

	while (true)
	{
		pthread_mutex_lock(&philo->fork);
		time = curent_time(philo);
		msg(time, philo, "has taken a fork\n");
		pthread_mutex_lock(&philo->next->fork);
		time = curent_time(philo);
		msg(time, philo, "has taken a fork\n");
		msg(time, philo, "is eating\n");
		philo->last_meal = get_time();
		philo->ate++;
		chill(philo->info->eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		time = curent_time(philo);
		msg(time, philo, "is sleeping\n");
		chill(philo->info->sleep);
		time = curent_time(philo);
		msg(time, philo, "is thinking\n");
	}
}

int	start(t_philo *top)
{
	int		i;
	t_philo	*philo;

	i = 1;
	philo = top;
	while (i <= top->info->np)
	{
		if (pthread_create(&(philo->thread), NULL, (void *)routin, philo))
			return (1);
		philo = philo->next;
		usleep(100);
		i++;
	}
	return (0);
}
