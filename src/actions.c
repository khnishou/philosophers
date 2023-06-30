/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnishou <khnishou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:01:51 by ykerdel           #+#    #+#             */
/*   Updated: 2023/06/30 16:11:58 by khnishou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	action_fork(t_philo *philo)
{
	long int	time;

	time = time_init();
	pthread_mutex_lock(&philo->data->print_wait);
	if (!philo->data->is_dead && philo->data->num_philo != 1)
		printf(YELLOW"%ld %d has taken a fork\n"RESET, time - philo->data->time_start, philo->index + 1);
	pthread_mutex_unlock(&philo->data->print_wait);
}

long int	action_eat(t_philo *philo)
{
	long int	time;

	time = time_init();
	pthread_mutex_lock(&philo->data->print_wait);
	if (!philo->data->is_dead && philo->data->num_philo != 1)
		printf(GREEN"%ld %d is eating\n"RESET, time - philo->data->time_start, philo->index + 1);
	pthread_mutex_unlock(&philo->data->print_wait);
	time_wait(philo->data->time_eat);
	return (time);
}

void	action_sleep(t_philo *philo)
{
	long int	time;

	time = time_init();
	pthread_mutex_lock(&philo->data->print_wait);
	if (!philo->data->is_dead && philo->data->num_philo != 1)
		printf(MAGENTA"%ld %d is sleeping\n"RESET, time - philo->data->time_start, philo->index + 1);
	pthread_mutex_unlock(&philo->data->print_wait);
	time_wait(philo->data->time_sleep);
}

void	action_think(t_philo *philo)
{
	long int	time;

	time = time_init();
	pthread_mutex_lock(&philo->data->print_wait);
	if (!philo->data->is_dead && philo->data->num_philo != 1)
		printf(BLUE"%ld %d is thinking\n"RESET, time - philo->data->time_start, philo->index + 1);
	pthread_mutex_unlock(&philo->data->print_wait);
}

void	action_dead(t_philo *philo)
{
	long int	time;

	time = time_init();
	pthread_mutex_lock(&philo->data->print_wait);
	printf(RED"%ld %d dead\n"RESET, time - philo->data->time_start, philo->index + 1);
	philo->data->is_dead = 1;
	pthread_mutex_unlock(&philo->data->print_wait);
}
