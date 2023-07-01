/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:01:51 by ykerdel           #+#    #+#             */
/*   Updated: 2023/07/01 20:27:02 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	action_fork(t_philo *philo)
{
	long int	time;

	time = time_init();
	pthread_mutex_lock(&philo->data->print_wait);
	if (!philo->data->is_dead)
		printf(YELLOW"%ld %d has taken a fork\n"RESET,
			time - philo->data->time_start, philo->index + 1);
	pthread_mutex_unlock(&philo->data->print_wait);
}

long int	action_eat(t_philo *philo)
{
	long int	time;

	time = time_init();
	pthread_mutex_lock(&philo->data->print_wait);
	if (!philo->data->is_dead)
		printf(GREEN"%ld %d is eating\n"RESET,
			time - philo->data->time_start, philo->index + 1);
	pthread_mutex_unlock(&philo->data->print_wait);
	time_wait(philo->data->time_eat);
	return (time);
}

void	action_sleep(t_philo *philo)
{
	long int	time;

	time = time_init();
	pthread_mutex_lock(&philo->data->print_wait);
	if (!philo->data->is_dead)
		printf(MAGENTA"%ld %d is sleeping\n"RESET,
			time - philo->data->time_start, philo->index + 1);
	pthread_mutex_unlock(&philo->data->print_wait);
	time_wait(philo->data->time_sleep);
}

void	action_think(t_philo *philo)
{
	long int	time;

	time = time_init();
	pthread_mutex_lock(&philo->data->print_wait);
	if (!philo->data->is_dead)
		printf(BLUE"%ld %d is thinking\n"RESET,
			time - philo->data->time_start, philo->index + 1);
	pthread_mutex_unlock(&philo->data->print_wait);
}

void	action_dead(t_philo *philo)
{
	long int	time;

	time = time_init();
	pthread_mutex_lock(&philo->data->print_wait);
	printf(RED"%ld %d dead\n"RESET,
		time - philo->data->time_start, philo->index + 1);
	philo->data->is_dead = 1;
	pthread_mutex_unlock(&philo->data->print_wait);
}
