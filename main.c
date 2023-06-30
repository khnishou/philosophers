/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnishou <khnishou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:01:25 by ykerdel           #+#    #+#             */
/*   Updated: 2023/06/12 01:10:09 by khnishou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philosophers.h"

void zbel(t_philo *philo)
{
    while (philo->num_eat && !philo->data->is_dead)
    {
        pthread_mutex_lock(philo->l_fork);
        action_fork(philo);
        if (philo->data->num_philo != 1)
        {
            pthread_mutex_lock(&philo->r_fork);
            action_fork(philo);
        }
        philo->time_alive = time_init();
        philo->time_alive = action_eat(philo);
        philo->num_eat--;
        pthread_mutex_unlock(philo->l_fork);
        if (philo->data->num_philo != 1)
            pthread_mutex_unlock(&philo->r_fork);
        action_sleep(philo);
        action_think(philo);
    }
}

void *function(void *arg)
{
    t_philo     *philo;

	philo = (t_philo *)arg;
    if ((philo->index % 2))
        time_wait(5);
	zbel(philo);
    return (NULL);
}

void ft_threads(t_philo *philo, t_data data)
{
    size_t 	    i;
	pthread_t	th;
	long int	time;

    i = 0;
    while (i < data.num_philo)
    {
        if (pthread_create(&philo[i].cpu_id, NULL, function, (void *)&philo[i]) != 0)
            ft_exit(TH_CREATE_ERR, philo);
        i++;
    }
    while (!philo[i % philo[0].data->num_philo].data->is_dead && philo->num_eat)
    {
	    time = time_init() - philo[i % philo[0].data->num_philo].time_alive;
        if (check_dead(&philo[i % philo[0].data->num_philo], time))
            action_dead(&philo[i % philo[0].data->num_philo]);
        i++;
    }
    i = 0;
    while (i < data.num_philo)
    {
        if (pthread_join(philo[i].cpu_id, NULL) != 0)
            ft_exit(TH_JOIN_ERR, philo);
        i++;
    }
}

int	main(int argc, char *argv[])
{
	t_philo	    *philo;
    t_data      data;

	if (argc != 5 && argc != 6)
		ft_exit(ARGC_ERR, philo);
	if (check_arg(argc, argv))
		ft_exit(ARGV_ERR, philo);
    data = init_data(argc, argv);
    if (data.num_philo < 1)
    {
        pthread_mutex_destroy(&data.print_wait);
		ft_exit(ARGV_ERR, philo);
    }
	philo = init_philo(data, argc, argv);
	ft_threads(philo, data);
    ft_exit(VALID, philo);
	return (0);
}
