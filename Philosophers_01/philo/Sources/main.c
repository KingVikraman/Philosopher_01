/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:45:08 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/07 14:45:08 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void			print_action(t_data *data, int id, char *str);
int				main(int argc, char **argv);
void			timer(long long int time);
bool			check_stop(t_data *data);
long long int	gettime(void);

void	print_action(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&(data->writing_lock));
	pthread_mutex_lock(&(data->sim_lock));
	if (data->sim_running)
	{
		printf("%lld ", gettime() - data->start_time);
		printf("%d ", id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(data->sim_lock));
	pthread_mutex_unlock(&(data->writing_lock));
}

void	timer(long long int time)
{
	long long int	current;

	current = gettime();
	while (1)
	{
		if (gettime() - current >= time)
			return ;
		usleep(100);
	}
}

bool	check_stop(t_data *data)
{
	bool	status;

	pthread_mutex_lock(&data->sim_lock);
	status = data->sim_running;
	pthread_mutex_unlock(&data->sim_lock);
	return (status);
}

long long int	gettime(void)
{
	struct timeval	time;
	long long int	time_milisec;

	gettimeofday(&time, NULL);
	time_milisec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_milisec);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (printf(VALIDITY_ERROR), 1);
	if (is_valid_check(&data, argv))
		print_error(2);
	init_all(&data, argc);
	start_sim(&data);
	print_success(1);
}
