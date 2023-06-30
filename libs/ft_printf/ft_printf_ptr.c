/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:23:21 by ykerdel           #+#    #+#             */
/*   Updated: 2023/03/21 17:32:42 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uhexlen(unsigned long long n)
{
	int	i;

	i = 1;
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*ft_ptoa(unsigned long long n)
{
	int		len;
	char	*d;
	char	*tab;

	tab = "0123456789abcdef";
	if (n == 0)
		return (tt_strdup("0x0"));
	len = ft_uhexlen(n) + 1;
	d = malloc (len + 3);
	if (!d)
		return (NULL);
	d[len] = 0;
	d[1] = 'x';
	d[0] = '0';
	len--;
	while (n != 0)
	{
		d[len--] = tab[n % 16];
		n = n / 16;
	}
	return (d);
}
