/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:54:03 by nbouljih          #+#    #+#             */
/*   Updated: 2023/01/01 20:12:37 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	ft_perror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
	return (*str);
}

int	main(int argc, char *argv[])
{
	t_info	*input;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (ft_perror("5 or 6 argv"));
	if (init(argc, argv, &input, &philo))
		return (ft_perror("Usage: ./philo <number_of_philos> <time_to_die> "
				"<time_to_eat> <time_to_sleep> "
				"[number_of_times_eacih_philosopher_must_eat]\n"));
	if (start(philo))
		return (ft_perror("\nproblem during executing routine\n"));
	death(philo);
	ft_free(philo);
	return (0);
}
