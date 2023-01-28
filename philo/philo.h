/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:31:12 by nbouljih          #+#    #+#             */
/*   Updated: 2023/01/22 23:44:38 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# define AC_RED "\x1b[31m"
# define AC_YELLOW "\x1b[33m"

typedef struct s_info
{
	int				sleep;
	int				eat;
	int				die;
	int				must;
	int				np;
	int				full;
	long			start_time;
	pthread_mutex_t	write;
}	t_info;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	fork;
	t_info			*info;
	long			last_meal;
	int				ate;
	bool			full;
	struct s_philo	*next;
	struct s_philo	*previous;
}	t_philo;

int		init(char **av, t_info **input, t_philo **philo);
t_philo	*fill_info(t_info *input);
void	pointeur(t_philo **up, t_philo *new);
long	get_time(void);
long	curent_time(t_philo *philo);
void	chill(long time);
void	msg(long time, t_philo *philo, char *str);
int		start(t_philo *philo);
void	death(t_philo *philo);
void	ft_free(t_philo *head);
#endif
