/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:02:20 by ykerdel           #+#    #+#             */
/*   Updated: 2023/07/01 20:28:09 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"
# include <sys/time.h>
# include <time.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef enum e_error_code
{
	VALID,
	ARGC_ERR,
	ARGV_ERR,
	TH_CREATE_ERR,
	TH_JOIN_ERR
}					t_error;

typedef struct s_data
{
	int					is_dead;
	int					num_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	long int			time_start;
	pthread_mutex_t		print_wait;
}	t_data;

typedef struct s_philo
{
	int					num_eat;
	pthread_t			cpu_id;
	t_data				*data;
	int					index;
	long int			time_alive;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		r_fork;

}	t_philo;

int			check_arg(char **argv);
int			check_dead(t_philo *philo, long int time);

void		ft_exit(t_error err, t_philo *philo);

t_data		init_data(char *argv[]);
t_philo		*init_philo(t_data data, int argc, char *argv[]);

void		time_wait(int time);
long int	time_init(void);

void		action_fork(t_philo *philo);
void		action_dead(t_philo *philo);
void		action_think(t_philo *philo);
long int	action_eat(t_philo *philo);
void		action_sleep(t_philo *philo);

#endif