/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uni.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:34:05 by ykerdel           #+#    #+#             */
/*   Updated: 2023/03/21 17:32:27 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

size_t	ft_unumlen(unsigned int n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*d;

	if (n == 0)
		return (tt_strdup("0"));
	len = ft_unumlen(n);
	d = malloc (len + 1);
	if (!d)
		return (NULL);
	d[len] = 0;
	len--;
	while (n != 0)
	{
		d[len--] = '0' + (n % 10);
		n = n / 10;
	}
	return (d);
}
