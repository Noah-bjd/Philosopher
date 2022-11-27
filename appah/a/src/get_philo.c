/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:57:19 by beadam            #+#    #+#             */
/*   Updated: 2022/08/27 12:15:28 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void add_new(int i, t_philo **top, t_info *info)
{
	t_philo *new;

	new = malloc(sizeof(t_philo));
	if (!new)
		allocation_error();
	new->index = i;
	new->info = info;
	new->last_meal = info->start_time;
	new->eats = 0;
	new->full = false;
	pthread_mutex_init(&new->fork, NULL);
	if (!*top)
	{
		new->next = new;
		new->previous = new;
		*top = new;
		return ;
	}
	new->previous = (*top)->previous;
	new->next = *top;
	((*top)->previous)->next = new;
	(*top)->previous = new;
}

t_philo *get_philo(t_info *info)
{
	t_philo *top;
	int i;

	i = 1;
	top = NULL;
	pthread_mutex_init(&info->printing, NULL);
	while (i <= info->nbr)
	{
		add_new(i, &top, info);
		i++;
	}
	return (top);
}
