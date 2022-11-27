/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_mutex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouljih <Noahbjd20@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 04:01:55 by nbouljih          #+#    #+#             */
/*   Updated: 2022/11/10 18:31:04 by nbouljih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// //race condition
// #include <stdio.h>
// #include <pthread.h>
// #include <time.h>
// pthread_t tid[2];
// //  0xFFFFFFFF wtf does this shit mean ??
// int counter;
// pthread_mutex_t mutex;
// int c = 0;
// void    *routine()
// {
//     time_t start, end;
//     start = time(NULL);
//     //pthread_mutex_lock(&mutex);
    
//     //unsigned long i = 0;
//     counter +=1;
//     printf("\n Job %d has started", counter);
//     for(int i = 0; i < 2; i++)
//         printf("\n Job %d has finnished", counter);
//     //pthread_mutex_unlock(&mutex);
//     end = time(NULL);
//     printf("\n %2.f seconds", difftime(start, end));
//     return NULL;
// }
// // void    *count(void *arg)
// // {
// //     for(int i = 0; i <= 100; i++)
// //         c++;
// // }
// int main(int ac, char **av)
// {
//     pthread_t t1, t2;
//     //pthread_mutex_init(&mutex, NULL);
//     if (pthread_create(&t1, NULL, &routine, NULL) != 0)//if the thread was created successfully its return value is 0
//         printf("\n thread can not be");
//     if (pthread_create(&t2, NULL, &routine, NULL) != 0)
//        printf("\n thread can not be");
//     //pthread_join is a function which waits for the specified thread to be terminated
//     pthread_join(t1, NULL);
//     printf("\n%d\n", c);
//     pthread_join(t2, NULL);
//     //pthread_mutex_destroy(&mutex);
//     return(0);
// }

#include <stdio.h>
#include <pthread.h>
int count;
pthread_mutex_t
void    *fun(void *argv)
{
    count += 1;
    printf("job %d has started \n", count);
    for(int i = 0; i < 1; i++)
        printf("job %d has ended\n", count);
    return NULL;
}
int main(void)
{  
    pthread_t   t, p;
    if(pthread_create(&t, NULL, &fun, NULL))
        return(1);
    if(pthread_create(&p, NULL, &fun, NULL))
        return(1);
    pthread_join(t, NULL);
    pthread_join(p, NULL);
    return  0;
}