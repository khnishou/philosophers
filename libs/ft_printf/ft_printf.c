/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:38:09 by ykerdel           #+#    #+#             */
/*   Updated: 2023/01/25 14:57:08 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

int	ft_formats(va_list args, char c)
{
	int	len;

	len = 1;
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		len = ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		len = ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		len = ft_print_unsigned(va_arg(args, unsigned long long));
	else if (c == 'x' || c == 'X')
		len = ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	int		len;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len = len + ft_formats(args, str[i]);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
