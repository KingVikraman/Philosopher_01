/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:19:24 by rvikrama          #+#    #+#             */
/*   Updated: 2025/03/29 18:19:24 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/philo.h"



static bool	ft_isdigit(char	*str)
{
	int i = 0;

	if (!str[i])
		return false;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
		i++;
	}
	return true;
}

static int ft_atoi(char *str)
{
	int i = 0;
	unsigned long nb = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0'); 
		if (nb > MAX_INT_LIMIT)  // Handle overflow 
			return -1;
		i++;
	}
	return (int)nb;
}
 


int is_valid_check(t_data *data ,char **argv)
{
    int i = 0;
   
    data->meals_sum = -1;
	while (argv[++i])
    {
        if (!ft_isdigit(argv[i]))
            return (printf("Not a number: %s\n", argv[i]));
		// if (data->death_time <= 0 || data->feasting_time <= 0)
    	// 	return (printf("Time values must be positive!\n"));
        //Stores the converted values inside the struct
        if (i == 1) data->philo_sum = ft_atoi(argv[i]);
        if (i == 2) data->death_time = ft_atoi(argv[i]);
        if (i == 3) data->feasting_time = ft_atoi(argv[i]);
        if (i == 4) data->sleeping_time = ft_atoi(argv[i]);
        if (i == 5) data->meals_sum = ft_atoi(argv[i]);
		//-----------data->args.meals_sum =nb;
	}
	return (0);
}