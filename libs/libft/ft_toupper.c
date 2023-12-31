/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khnishou <khnishou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:47:02 by khnishou          #+#    #+#             */
/*   Updated: 2022/10/18 18:47:02 by khnishou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int str)
{
	if (!(str <= 'z' && str >= 'a'))
		return (str);
	return (str - 32);
}
