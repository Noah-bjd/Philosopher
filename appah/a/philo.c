/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:03:54 by beadam            #+#    #+#             */
/*   Updated: 2022/09/03 14:42:59 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void list_len(t_philo *top)
{
	int i = 0;
	int ref;

	ref = top->index;
	printf("first element:%d \n", top->index);
	while(!i || ref != top->index)
	{
		printf("current index: %d\n", top->index);
		top = top->next;
		i++;
	}
	printf("count: %d \n", i);
}

int	main(int argc, char *argv[])
{
	t_info	*info;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (usage_mod());
	if (initialization(argc, argv, &info))
		return (input_error());
	philo = get_philo(info);
	if (!philo)
		return (allocation_error());
	begin(philo);
	death(philo);
	return (0);
}
