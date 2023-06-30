/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:29:18 by ykerdel           #+#    #+#             */
/*   Updated: 2023/03/21 17:41:46 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int n)
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

char	*ft_htoa(unsigned int n)
{
	int		len;
	char	*d;
	char	*tab;

	tab = "0123456789ABCDEF";
	if (n == 0)
		return (tt_strdup("0"));
	len = ft_hexlen(n) - 1;
	d = malloc (len + 1);
	if (!d)
		return (NULL);
	d[len] = 0;
	len--;
	while (n != 0)
	{
		d[len--] = tab[n % 16];
		n = n / 16;
	}
	return (d);
}
