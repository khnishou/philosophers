/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:20:06 by ykerdel           #+#    #+#             */
/*   Updated: 2023/06/11 13:27:54 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] <= '9' && argv[i][j] >= '0'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dead(t_philo *philo, long int time)
{
	if (time > philo->data->time_die)
		return (1);
	return (0);
}
