#include "philo.h"
#include <string.h>
int ft_atoi(char *str)
{
    int i;
    int result;

    i = 0;
    result = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return(result);
}
