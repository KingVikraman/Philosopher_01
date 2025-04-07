/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:54:33 by rvikrama          #+#    #+#             */
/*   Updated: 2025/04/07 14:54:33 by rvikrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static int	ft_atoi(char *str)
{
	int				i;
	unsigned long	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > MAX_INT_LIMIT)
			return (-1);
		i++;
	}
	return ((int)nb);
}

int	is_valid_check(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->meals_sum = -1;
	while (argv[++i])
	{
		if (!ft_isdigit(argv[i]))
			return (printf("Not a number: %s\n", argv[i]));
		if (i == 1)
			data->philo_sum = ft_atoi(argv[i]);
		if (i == 2)
			data->death_time = ft_atoi(argv[i]);
		if (i == 3)
			data->feasting_time = ft_atoi(argv[i]);
		if (i == 4)
			data->sleeping_time = ft_atoi(argv[i]);
		if (i == 5)
			data->meals_sum = ft_atoi(argv[i]);
	}
	return (0);
}
