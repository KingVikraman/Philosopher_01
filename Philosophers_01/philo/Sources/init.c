/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:03:18 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/04 22:11:14 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"



int		setup_fork_mutex(t_data *data)
{
	int fork;
	int error;

	fork = 0;
	while (fork < data->philo_sum)
	{
		error = pthread_mutex_init(&data->fork[fork], NULL);
		if (error != 0)
			return(printf(ERR_00));
		fork++;
	}
	error = pthread_mutex_init(&data->writing_lock, NULL);
	error = pthread_mutex_init(&data->sim_lock, NULL);
	if (error != 0)
		return(printf(ERR_03), -1);
	return(-1);
}

void philo_init(t_data *data)
{

	int i = 0;

	while (i < data->philo_sum)
	{
		data->philo[i] = (t_philo){ 
        .id          = i,
        .id_left     = i,
        .id_right    = (i+1) % data->philo_sum,
        .last_feast  = 0,
        .num_of_meals= 0,  
        .data        = data,             
    	};
    	pthread_mutex_init(&data->philo[i].feast_lock, NULL);
    	i++;
	}
}


void 	init_all(t_data *data, int argc)
{
	if ((argc == 6 && data->meals_sum < 0) ||
		(data->philo_sum < 1) || 
		(data->philo_sum > 200) ||
		(data->death_time < 60) ||
		(data->feasting_time < 60) ||
		(data->sleeping_time < 60))
	{
		print_error(1);
	}	
	setup_fork_mutex(data);
	philo_init(data);
}