#include "philo.h"
long	get_time(void)
{
	struct timeval	tp;
	long			time;

	gettimeofday(&tp, NULL);
	time = tp.tv_sec * 1e3 + tp.tv_usec / 1e3;
	return (time);
}

long	current_time(t_philo *philo)
{
	return (get_time() - philo->info->start_time);
}

static int	ft_isspace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res -= *str - '0';
		str++;
	}
    if (*str != '\0')
        return (-1);
	return (res * sign);
}
