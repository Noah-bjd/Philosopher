void		smart_sleep(long long time, t_info *rules)
{
	long long i;

	i = timestamp();
	while (!(rules->dieded))
	{
		if (time_diff(i, timestamp()) >= time)
			break ;
		usleep(50);
	}
}
	smart_sleep(rules->time_eat, rules);