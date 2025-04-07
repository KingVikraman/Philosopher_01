/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 21:06:15 by rvikrama          #+#    #+#             */
/*   Updated: 2025/03/28 21:06:15 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"


void	timer(long long int time)
{
	long long int current;

	current = gettime();
	while (1)
	{
		if (gettime() - current >= time)
			return ;
		usleep(100);
	}
}

long long int	gettime(void)
{
	struct timeval	time;
	long long int	time_milisec;

	gettimeofday(&time, NULL);
	time_milisec = time.tv_sec * 1000 + time.tv_usec  / 1000;
	return (time_milisec);
}

int main(int argc, char **argv)
{
	
	t_data data;

	if (argc != 5 && argc != 6)
		return(printf(VALIDITY_ERROR), 1);

	if (is_valid_check(&data, argv))
		print_error(2);

	init_all(&data, argc);
	start_sim(&data);
	printf("after sim");
	print_success(1);
}



/*
int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}




int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}


Okay, what has to be done, firstly, we got to settle 
the pasing the argunments, 

according to jason he said that what you can do is that 
once you git pull  the libft folder from your ripo,
 you could use the so called helper functions in your philo, 
what i mean by helper funtions is that, the simple utils
functions.

Parsing Arguments:
	~Negative Numbers.
	~INT_MAX Numbers.
	~Invalid Arguments
		*Input is char.
		*Input is not the correct format.
		*Input is not right.
	~Incorrect format
	~Too many arguments
	~Too little arguments


As for the arguments, we need to handle most of the
above, moreover, we can take some referance on how 
the code is structured in the git hub, just incase 
your lost,. 

Okay once you have done that, you would need to go back to youb main
and work on your table initalization, philo initialisation, followed 
by the time, and after that you also got make a function to start 
the simulation, 

Simulations:
	~Deadlock.
	~Racing philos.
	~Mutex.
	~Thread.
	~Left handed philo.
	~Lone philo routine.
	~Initialisation of forks.
	~assigning the forks to philo.
	~assigning ID for the philo.

Table Initialisation:
	~Assign the time to eat to the time
	~Assign the time to die to the time
	~Assign the time to sleep to the time
	~Assign the number if time philo must eat
	to the time.
	~Ensure that the structs are declared properly,
	~usage of structs are really important, to reduce 
	the usag of the printf function.
	~

	c


*/

// Wah i need to commit now