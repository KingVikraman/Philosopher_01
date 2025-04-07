/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/04/07 14:26:56 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/07 14:26:56 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILOS 200
# define MAX_INT_LIMIT 1024
# define VALIDITY_ERROR "Invalid number of arguments! Usage:\
 ./philo number_of_philos time_to_die time_to_eat time_to_sleep [must_eat]\n"
# define STR_ERR_NUMBERS "Arguments must be positive numbers!"
# define STD_ERR_LIMITS "One or more arguments are out of range!"
# define STD_ERR_START "All arguments are valid! Starting the simulation..."
# define ERR_00 "FAILURE:Fork also cannot initialise, HAIYA!!!.\n"
# define ERR_03 "FAILURE: Writing lock also cannot initialise. GG!!!\n."

typedef struct s_philo
{
	int				id;
	int				id_left;
	int				id_right;
	long long		last_feast;
	int				num_of_meals;
	pthread_t		thread;
	pthread_mutex_t	feast_lock;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	long long int	start_time;
	int				death_time;
	int				feasting_time;
	int				sleeping_time;
	int				meals_sum;
	bool			sim_running;
	int				philo_sum;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	writing_lock;
	pthread_mutex_t	sim_lock;
	t_philo			philo[200];
}	t_data;

long long int	gettime(void);
void			print_error(int n);
void			eat(t_philo *philo);
void			print_success(int n);
void			start_sim(t_data *data);
bool			check_stop(t_data *data);
void			philo_init(t_data *data);
void			set_sim_end(t_data *data);
void			timer(long long int time);
void			end_checker(t_data *data);
bool			check_all_ate(t_data *data);
void			*routine(void *philosopher);
void			create_threads(t_data *data);
int				setup_fork_mutex(t_data *data);
bool			check_philo_death(t_data *data);
void			init_all(t_data *data, int argc);
int				is_valid_check(t_data *data, char **argv);
void			print_action(t_data *data, int id, char *str);

#endif
