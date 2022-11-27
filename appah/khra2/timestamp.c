#include "philo.h"

//Following is the util function to get current timestamp in milliseconds:
//when documenting the run of a program, its output will contain
// a clear brief of when the timestamp run i the first place
long long timestamp() 
{
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}
long long	current_t(t_input *info)
{
	long long	time;

	time = timestamp() - info->chrono;
	return (time);
}