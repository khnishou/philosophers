/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:13:57 by ykerdel           #+#    #+#             */
/*   Updated: 2023/04/13 11:54:32 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *args)
{
	size_t	i;

	i = 0;
	if (!args)
		return (ft_print_str("(null)"));
	while (args[i])
	{
		ft_putchar(args[i]);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int args)
{
	char	*d;
	int		len;

	d = tt_itoa(args);
	len = ft_print_str(d);
	free(d);
	return (len);
}

int	ft_print_unsigned(unsigned long long args)
{
	char	*d;
	int		len;

	d = ft_uitoa(args);
	len = ft_print_str(d);
	free(d);
	return (len);
}

int	ft_print_hex(unsigned int args, char c)
{
	char	*d;
	size_t	i;
	int		len;

	i = 0;
	d = ft_htoa(args);
	while (c == 'x' && d[i])
	{
		d[i] = tt_tolower(d[i]);
		i++;
	}
	len = ft_print_str(d);
	free(d);
	return (len);
}

int	ft_print_ptr(unsigned long long args)
{
	char	*d;
	int		len;

	d = ft_ptoa(args);
	len = ft_print_str(d);
	free(d);
	return (len);
}
