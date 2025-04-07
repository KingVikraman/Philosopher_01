#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_PHILOS 200
#define MAX_INT_LIMIT 1024
#define	VALIDITY_ERROR	"Invalid number of arguments! Usage: ./philo number_of_philos time_to_die time_to_eat time_to_sleep [must_eat]"
#define STR_ERR_NUMBERS	 "Arguments must be positive numbers!"
#define STD_ERR_LIMITS	 "One or more arguments are out of range!"
#define	STD_ERR_START	"All arguments are valid! Starting the simulation..."
#define ERR_00 "FAILURE:Fork also cannot initialise, HAIYA!!!.\n"
#define ERR_03 "FAILURE: Writing lock also cannot initialise. GG!!!\n."

typedef struct s_philo
{
	int 		id;
	int			id_left;
	int			id_right;
	long long	last_feast;     // Protection (feast-lock)
	int			num_of_meals;   // Protection (feast-lock)
	pthread_t	thread;
	pthread_mutex_t feast_lock;
	struct s_data *data;
} t_philo;

typedef struct s_data{
	long long int	start_time;
	int 			death_time;
	int 			feasting_time;
	int 			sleeping_time;
	int 			meals_sum;
	bool sim_running;      // Protection (sim_lock) 
	int philo_sum;
	pthread_mutex_t fork[200];
	pthread_mutex_t writing_lock; // Locking printing
	pthread_mutex_t sim_lock;
	// t_args *args;
	t_philo philo[200];
} t_data;


void	timer(long long int time);
void	print_error(int n);
void print_success(int n);
long long int	gettime(void);
void philo_init(t_data *data);
void	eat(t_philo *philo);
void	start_sim(t_data *data);
void create_threads(t_data * data);
int		setup_fork_mutex(t_data *data);
void	end_checker(t_data *data);
void	*routine(void *philosopher);
void 	init_all(t_data *data, int argc);
void	print_action(t_data *data, int id, char *str);
int is_valid_check(t_data *data ,char **argv);

#endif

// Example of a struct:

// struct def_types {
// 	char name[50];
// 	int age;
// 	float gpa;
// };



// int hello(int *x)
// {
// 	*x = 10;
// }
// int main()
// {
// 	int x;
// 	hello(&x);
// 	printf("%d\n", x);
// }


// git commit code convetions.

// simplify thing as mcu as possible, find a way to automate.(A.I or Script)

// only use comments when other dev might not understand whats going on from the code.[Avoid notes in your code!].
// Code -> write your code like a english sentace (utilise clear names and usage of descriptive names).

// Utilise all the vs code shortcuts, see what repetative and find shrotcuts to do it. [Ask GPT].

// usage of Makefile-> DO the makefile first!!
// Codes overall structure test everything in main file. Expand from the makefile.
// Commit for every feature/fix, then refactor according ot file structure. make and run again.

// Define your priblem properly, very clearly
// 	->WHAT?
// 	->HOW?
// 	->WHY?
// Visualise diffrent inputs followed their outputs, then start experimenting where you cna see the results of the 
// input and output.



