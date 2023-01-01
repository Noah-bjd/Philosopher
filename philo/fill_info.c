/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:18:10 by nbouljih          #+#    #+#             */
/*   Updated: 2023/01/01 19:38:41 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	node(int x, t_philo **up, t_info *input)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
	{
		printf("\nallocation issue\n");
		return ;
	}
	new->last_meal = input->start_time;
	new->id = x;
	new->ate = 0;
	new->full = false;
	new->info = input;
	pointeur(up, new);
}

t_philo	*fill_info(t_info *input)
{
	int		x;
	t_philo	*up;

	x = 1;
	up = NULL;
	pthread_mutex_init(&input->write, NULL);
	while (x <= input->np)
	{
		node(x, &up, input);
		x++;
	}
	return (up);
}
