/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:08:02 by ykerdel           #+#    #+#             */
/*   Updated: 2023/07/01 20:24:44 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_data	init_data(char *argv[])
{
	t_data	data;

	data.num_philo = ft_atoi(argv[1]);
	data.time_die = ft_atoi(argv[2]);
	data.time_eat = ft_atoi(argv[3]);
	data.time_sleep = ft_atoi(argv[4]);
	data.time_start = time_init();
	pthread_mutex_init(&data.print_wait, NULL);
	data.is_dead = 0;
	return (data);
}

t_philo	*init_philo(t_data data, int argc, char *argv[])
{
	int		i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * data.num_philo);
	i = 0;
	while (i < data.num_philo)
	{
		philo[i].num_eat = -1;
		if (argc == 6)
			philo[i].num_eat = ft_atoi(argv[5]);
		philo[i].index = i;
		philo[i].time_alive = data.time_start;
		philo[i].data = &data;
		pthread_mutex_init(&philo[i].r_fork, NULL);
		if (i == data.num_philo - 1)
			philo[0].l_fork = &philo[i].r_fork;
		if (i)
			philo[i].l_fork = &philo[i - 1].r_fork;
		i++;
	}
	return (philo);
}
