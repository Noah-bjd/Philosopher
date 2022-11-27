#include "philo.h"

char print(char *str)
{
    int i = 0;
    while(str[i])
        write(1, &str[i++], 1);
    return(*str);
}
