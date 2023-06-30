/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:25:51 by ykerdel           #+#    #+#             */
/*   Updated: 2023/06/02 15:49:55 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	time_wait(int time)
{
	useconds_t microsecond;

	microsecond = (useconds_t) time * 1000;
	usleep(microsecond);
}

long int	time_init(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
