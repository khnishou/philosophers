/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:29:58 by ykerdel           #+#    #+#             */
/*   Updated: 2022/10/21 10:54:16 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *restrict dest, const void *restrict src, size_t n)
{
	int		i;
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (d == s || n == 0)
		return (d);
	if (d > s)
	{
		i = n - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
		d = ft_memcpy(dest, src, n);
	return (d);
}
