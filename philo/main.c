/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:54:03 by nbouljih          #+#    #+#             */
/*   Updated: 2023/01/22 23:44:32 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	decimal(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] >= '0' && av[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	*input;
	t_philo	*philo;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (decimal(argv[i]))
			return (printf("%sworng set of input\n", AC_YELLOW), 1);
		i++;
	}
	if (argc != 5 && argc != 6)
		return (printf("%sUSAGE: ./philo[number_of_philosophers][time_to_die]\n"
				"\t[time_to_eat][time_to_sleep]\n"
				"\t[number_of_times_eacih_philosopher_must_eat]", AC_RED));
	if (init(argv, &input, &philo))
		return (printf("%sProblem during initialization\n", AC_RED));
	if (start(philo))
		return (printf("%sProblem during execution [routine]\n", AC_RED));
	death(philo);
	return (0);
}
