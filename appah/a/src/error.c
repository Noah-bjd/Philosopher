/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:58:18 by beadam            #+#    #+#             */
/*   Updated: 2022/08/19 09:06:24 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	usage_mod(void)
{
	printf("usage mode: ./philo {nbr_of_philos}\
 {time_to_die} {time_to_eat} {time_to_sleep}\
 {number_of_times_each_philosopher_must_eat}\n");
	return (0);
}

int	input_error(void)
{
	printf("input error\n");
	return (0);
}

int	allocation_error(void)
{
	printf("memory allocation exception\n");
	return (0);
}