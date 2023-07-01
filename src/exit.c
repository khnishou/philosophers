/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:55:30 by ykerdel           #+#    #+#             */
/*   Updated: 2023/07/01 20:25:13 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_free(t_philo *philo)
{
	int		i;
	int		len;

	i = 0;
	len = philo[i].data->num_philo;
	pthread_mutex_destroy(&philo[i].data->print_wait);
	while (i < len)
	{
		pthread_mutex_destroy(&philo[i].r_fork);
		i++;
	}
	free(philo);
}

void	ft_exit(t_error err, t_philo *philo)
{
	if (err == VALID || err == TH_CREATE_ERR || err == TH_JOIN_ERR)
		ft_free(philo);
	if (err == VALID)
		exit (0);
	if (err == ARGC_ERR)
		printf("Error: Argc error!!!\n");
	if (err == ARGV_ERR)
		printf("Error: Invalid argv!!!\n");
	if (err == TH_CREATE_ERR)
		printf("Error: Thread create error!!!\n");
	if (err == TH_JOIN_ERR)
		printf("Error: Thread join error!!!\n");
	exit (1);
}
