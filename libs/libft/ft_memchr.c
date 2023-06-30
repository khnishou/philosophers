/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@sudent.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:02:29 by ykerdel           #+#    #+#             */
/*   Updated: 2022/10/29 13:40:57 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*ss;

	i = 0;
	ss = (char *)s;
	while (i < n)
	{
		if (ss[i] == (char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
