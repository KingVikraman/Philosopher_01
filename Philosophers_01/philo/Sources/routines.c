/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:34:58 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/07 17:16:00 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat(t_philo *philo);
void	*routine(void *philosopher);
void	end_checker(t_data *data);
void	create_threads(t_data *data);
void	start_sim(t_data *data);

void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (data->philo_sum == 1)
	{
		pthread_mutex_lock(&(data->fork[philo->id_left]));
		print_action(data, philo->id, "has taken a fork");
		pthread_mutex_unlock(&(data->fork[philo->id_left]));
		timer(data->death_time + 10);
		return ;
	}
	pthread_mutex_lock(&(data->fork[philo->id_left]));
	print_action(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->fork[philo->id_right]));
	print_action(data, philo->id, "has taken a fork");
	print_action(data, philo->id, "is eating");
	pthread_mutex_lock(&philo->feast_lock);
	philo->last_feast = gettime();
	philo->num_of_meals++;
	pthread_mutex_unlock(&philo->feast_lock);
	timer(data->feasting_time);
	pthread_mutex_unlock(&(data->fork[philo->id_right]));
	pthread_mutex_unlock(&(data->fork[philo->id_left]));
}

void	*routine(void *philosopher)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)philosopher;
	data = philo->data;
	if (philo->id % 2 != 0)
	{
		print_action(data, philo->id, "is thinking");
		timer(data->feasting_time / 2);
	}
	while (check_stop(data))
	{
		eat(philo);
		print_action(data, philo->id, "is sleeping");
		timer(data->sleeping_time);
		print_action(data, philo->id, "is thinking");
	}
	return (NULL);
}

void	end_checker(t_data *data)
{
	while (1)
	{
		if (check_philo_death(data) || check_all_ate(data))
			return ;
		usleep(500);
	}
}
// void	end_checker(t_data *data)
// {
// 	int			i;
// 	bool		all_ate;
// 	long long	now;

// 	while (1)
// 	{
// 		i = -1;
// 		now = gettime();
// 		while (++i < data->philo_sum)
// 		{
// 			pthread_mutex_lock(&data->philo[i].feast_lock);
// 			if ((now - data->philo[i].last_feast) > (long long)data->death_time)
// 			{
// 				print_action(data, i, "died");
// 				pthread_mutex_lock(&data->sim_lock);
// 				data->sim_running = false;
// 				pthread_mutex_unlock(&data->sim_lock);
// 				pthread_mutex_unlock(&data->philo[i].feast_lock);
// 				return ;
// 			}
// 			pthread_mutex_unlock(&data->philo[i].feast_lock);
// 		}
// 		if (data->meals_sum > 0)
// 		{
// 			all_ate = true;
// 			i = -1;
// 			while (++i < data->philo_sum && all_ate)
// 			{
// 				pthread_mutex_lock(&data->philo[i].feast_lock);
// 				all_ate = (data->philo[i].num_of_meals >= data->meals_sum);
// 				pthread_mutex_unlock(&data->philo[i].feast_lock);
// 			}
// 			if (all_ate)
// 			{
// 				print_action(data, -1, "All philosophers are full");
// 				pthread_mutex_lock(&data->sim_lock);
// 				data->sim_running = false;
// 				pthread_mutex_unlock(&data->sim_lock);
// 				return ;
// 			}
// 		}
// 		usleep(500);
// 	}
// }

void	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_sum)
	{
		data->philo[i].last_feast = data->start_time;
		if (pthread_create(&(data->philo[i].thread), NULL, routine,
				&(data->philo[i])) != 0)
			print_error(4);
		i++;
	}
}

void	start_sim(t_data *data)
{
	int	i;

	if (data->meals_sum == 0)
		return ;
	data->sim_running = true;
	data->start_time = gettime();
	create_threads(data);
	end_checker(data);
	i = 0;
	while (i < data->philo_sum)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->philo_sum)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->writing_lock);
}
