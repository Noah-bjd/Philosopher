/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beadam <beadam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 09:45:51 by beadam            #+#    #+#             */
/*   Updated: 2022/09/03 14:42:53 by beadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>


typedef struct s_info
{
	int				sleep;
	int				eat;
	int				die;
	int				must;
	int				nbr; 
	int				full_philo;
	long			start_time;
	pthread_mutex_t	printing;
}	t_info;

typedef struct s_philo
{
	pthread_t		thread;
	int				index;
	pthread_mutex_t	fork;
	t_info			*info;
	long			last_meal;
	int				eats;
	bool			full;
	struct s_philo	*next;
	struct s_philo	*previous;
}	t_philo;

//set info
int	initialization(int argc ,char **argv , t_info **info);

//get philo
t_philo	*get_philo(t_info *info);
void	add_new(int i, t_philo **top, t_info *info);

//tools
long	get_time(void);
int		ft_atoi(const char *str);

//errors
int		usage_mod(void);
int		input_error(void);
int		allocation_error(void);

//time
long	current_time(t_philo *philo);

//start_routine
void    begin(t_philo *top);

//check_death
void	death(t_philo *philo);

#endif