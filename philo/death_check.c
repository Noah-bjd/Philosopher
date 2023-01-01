/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:15:25 by nbouljih          #+#    #+#             */
/*   Updated: 2023/01/01 19:37:32 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death(t_philo *philo)
{
	while (true)
	{
		if (get_time() - philo->last_meal >= philo->info->die
			&& curent_time(philo) % philo->info->die == 0)
		{
			msg(curent_time(philo), philo, "die\n");
			break ;
		}
		if (philo->info->must > 0)
		{
			if (philo->info->full >= philo->info->np)
			{
				pthread_mutex_lock(&philo->info->write);
				return ;
			}
			if (philo->ate >= philo->info->must && !philo->full)
			{
				philo->full = true;
				philo->info->full++;
			}
		}
		philo = philo->next;
	}
}
