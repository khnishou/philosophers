/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_khnishou.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:11:35 by ykerdel           #+#    #+#             */
/*   Updated: 2023/03/21 17:33:21 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*tt_itoa(int n)
{
	int		len;
	char	*d;

	if (n == 0)
		return (tt_strdup("0"));
	if (n == -2147483648)
		return (tt_strdup("-2147483648"));
	len = ft_intlen(n);
	d = malloc (len + (n < 0) + 1);
	if (!d)
		return (NULL);
	d[len + (n < 0)] = 0;
	if (n < 0)
	{
		d[0] = '-';
		n = n * -1;
	}
	else
		len--;
	while (n != 0)
	{
		d[len--] = '0' + (n % 10);
		n = n / 10;
	}
	return (d);
}

int	tt_tolower(int str)
{
	if (!(str <= 'Z' && str >= 'A'))
		return (str);
	return (str + 32);
}

char	*tt_strdup(const char *s)
{
	char	*d;
	size_t	len;

	len = tt_strlen(s) + 1;
	d = malloc (len);
	if (d == NULL)
		return (NULL);
	d = tt_memcpy (d, s, len);
	return (d);
}

size_t	tt_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*tt_memcpy(const char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dest && !src)
		return (0);
	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
