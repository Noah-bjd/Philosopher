/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:27:28 by nbouljih          #+#    #+#             */
/*   Updated: 2023/01/23 00:30:59 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//Following is the util function to get current timestamp in milliseconds:
//when documenting the run of a program, its output will contain
// a clear brief of when the timestamp run i the first place

long	get_time(void)
{
	struct timeval	tp;
	long			time;

	gettimeofday(&tp, NULL);
	time = tp.tv_sec * 1e3 + tp.tv_usec / 1e3;
	return (time);
}

long	curent_time(t_philo *philo)
{
	long	time;

	time = get_time() - philo->info->start_time;
	return (time);
}

void	chill(long time)
{
	long	now;

	now = get_time();
	while (get_time() - now < time)
		usleep(100);
}

void	msg(long time, t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->write);
	printf("\033[0;32m");
	printf("%ld %d %s", time, philo->id, str);
	pthread_mutex_unlock(&philo->info->write);
}

void	pointeur(t_philo **up, t_philo *new)
{
	pthread_mutex_init(&new->fork, NULL);
	if (!*up)
	{
		new->next = new;
		new->previous = new;
		*up = new;
		return ;
	}
	new->previous = (*up)->previous;
	new->next = *up;
	((*up)->previous)->next = new;
	(*up)->previous = new;
}
