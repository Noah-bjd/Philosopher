/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:02:03 by nbouljih          #+#    #+#             */
/*   Updated: 2023/01/22 23:44:25 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * res + str[i] - 48;
		i++;
	}
	return (res);
}

int	init(char **av, t_info **input, t_philo **philo)
{
	(*input) = malloc(sizeof(t_info));
	(*input)->np = ft_atoi(av[1]);
	(*input)->die = ft_atoi(av[2]);
	(*input)->eat = ft_atoi(av[3]);
	(*input)->sleep = ft_atoi(av[4]);
	(*input)->start_time = get_time();
	(*input)->full = 0;
	if ((*input)->eat <= 0 || (*input)->np < 1 || \
			(*input)->die <= 0 || (*input)->sleep <= 0)
		return (printf("%sInputs must be greater than 0\n", AC_YELLOW), 1);
	if (av[5])
	{
		(*input)->must = ft_atoi(av[5]);
		if ((*input)->must < 1)
			return (printf("%sInputs must be greater than"
					"or equal than 1\n", AC_YELLOW), 1);
	}
	else
		(*input)->must = -1;
	(*philo) = fill_info(*input);
	if (!philo)
		return (printf("%sERROR Philo\n", AC_YELLOW), 1);
	return (0);
}
