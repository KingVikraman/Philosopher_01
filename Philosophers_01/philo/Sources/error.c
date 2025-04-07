/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:23:09 by rvikrama          #+#    #+#             */
/*   Updated: 2025/03/29 16:23:49 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"


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

void print_success(int n)
{
	write(2, "Success: ", 7);
	if ( n == 1)
		write(2, "The simulation has ended!", 25);
	write(2, "\n", 1);
	exit(1);
}
