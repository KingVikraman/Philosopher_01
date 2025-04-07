/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:23:09 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/07 17:30:45 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_error(int n);
void	print_success(int n);
void	set_sim_end(t_data *data);
bool	check_all_ate(t_data *data);
bool	check_philo_death(t_data *data);

void	print_error(int n)
{
	write(2, "Error: ", 7);
	if (n == 1)
		write(2, "wrong philo usage", 17);
	if (n == 2)
		write(2, "Argument is invalid, Please check again!", 41);
	if (n == 3)
		write(2, "mutex init failed", 17);
	if (n == 4)
		write(2, "pthread creation failed", 24);
	write(2, "\n", 1);
	exit(1);
}

void	print_success(int n)
{
	write(2, "Success: ", 7);
	if (n == 1)
		write(2, "The simulation has ended!", 25);
	write(2, "\n", 1);
	exit(1);
}

bool	check_philo_death(t_data *data)
{
	int			i;
	long long	now;

	i = -1;
	now = gettime();
	while (++i < data->philo_sum)
	{
		pthread_mutex_lock(&data->philo[i].feast_lock);
		if ((now - data->philo[i].last_feast) > (long long)data->death_time)
		{
			print_action(data, i, "died");
			set_sim_end(data);
			pthread_mutex_unlock(&data->philo[i].feast_lock);
			return (true);
		}
		pthread_mutex_unlock(&data->philo[i].feast_lock);
	}
	return (false);
}

bool	check_all_ate(t_data *data)
{
	int		i;
	bool	all_ate;

	if (data->meals_sum <= 0)
		return (false);
	i = -1;
	all_ate = true;
	while (++i < data->philo_sum && all_ate)
	{
		pthread_mutex_lock(&data->philo[i].feast_lock);
		all_ate = (data->philo[i].num_of_meals >= data->meals_sum);
		pthread_mutex_unlock(&data->philo[i].feast_lock);
	}
	if (all_ate)
	{
		print_action(data, -1, "All philosophers are full");
		set_sim_end(data);
		return (true);
	}
	return (false);
}

void	set_sim_end(t_data *data)
{
	pthread_mutex_lock(&data->sim_lock);
	data->sim_running = false;
	pthread_mutex_unlock(&data->sim_lock);
}
