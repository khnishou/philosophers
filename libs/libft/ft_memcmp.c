/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@sudent.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:41:11 by ykerdel           #+#    #+#             */
/*   Updated: 2022/10/29 13:36:37 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sv1;
	unsigned char	*sv2;

	i = 0;
	sv1 = (unsigned char *)s1;
	sv2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- != 0)
	{
		if (sv1[i] != sv2[i])
			return (sv1[i] - sv2[i]);
		i++;
	}
	return (0);
}
