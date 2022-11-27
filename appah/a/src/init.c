/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:58:24 by beadam            #+#    #+#             */
/*   Updated: 2022/08/22 04:10:12 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int initialization(int argc, char **argv, t_info **info)
{
	(*info) = malloc(sizeof(t_info));
	(*info)->nbr = ft_atoi(argv[1]);
	(*info)->die = ft_atoi(argv[2]);
	(*info)->eat = ft_atoi(argv[3]);
	(*info)->sleep = ft_atoi(argv[4]);
	(*info)->must = -1;
	if (argc == 6)
	{
		(*info)->must = ft_atoi(argv[5]);
		if ((*info)->must < 1)
			return (1);
	}
	(*info)->full_philo = 0;
	(*info)->start_time = get_time();
	if ((*info)->die < 0 || (*info)->eat < 0 || (*info)->nbr < 1 || (*info)->sleep < 0)
		return (1);
	return (0);
}