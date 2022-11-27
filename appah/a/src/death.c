/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:04:37 by beadam            #+#    #+#             */
/*   Updated: 2022/09/03 15:23:31 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	death(t_philo *philo)
{
	while (true)
	{
		if (get_time() - philo->last_meal >= philo->info->die
			&& current_time(philo) % philo->info->die == 0)
		{
			pthread_mutex_lock(&philo->info->printing);
			printf("%ld %d die\n", current_time(philo), philo->index);
			return ;
		}
		if (philo->info->must > 0)
		{
			if (philo->info->full_philo >= philo->info->nbr)
			{
				pthread_mutex_lock(&philo->info->printing);
				return ;
			}
			if (philo->eats >= philo->info->full_philo && !philo->full)
			{
				philo->full = true;
				philo->info->full_philo++;
			}
		}
		philo = philo->next;
	}
}