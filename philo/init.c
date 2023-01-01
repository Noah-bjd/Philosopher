/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:02:03 by nbouljih          #+#    #+#             */
/*   Updated: 2023/01/01 19:37:26 by nbouljih         ###   ########.fr       */
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

void	check_5(char **av, t_info **input)
{
	if (av[5])
	{
		(*input)->must = ft_atoi(av[5]);
		if ((*input)->must < 1)
		{	
			printf("inputs > 1");
			return ;
		}
	}
	else
		(*input)->must = -1;
}

int	init(int ac, char **av, t_info **input, t_philo **philo)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (decimal(av[i]))
			return (1);
		i++;
	}
	(*input) = malloc(sizeof(t_info));
	(*input)->np = ft_atoi(av[1]);
	(*input)->die = ft_atoi(av[2]);
	(*input)->eat = ft_atoi(av[3]);
	(*input)->sleep = ft_atoi(av[4]);
	(*input)->start_time = get_time();
	(*input)->full = 0;
	if ((*input)->eat < 0 || (*input)->np < 1 || \
			(*input)->die < 0 || (*input)->sleep < 0)
		return (printf("inputs > 0"), 1);
	check_5(av, input);
	(*philo) = fill_info(*input);
	if (!philo)
		return (printf("\nERROR philo\n"), 1);
	return (0);
}
