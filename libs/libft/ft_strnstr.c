/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:47:14 by ykerdel           #+#    #+#             */
/*   Updated: 2022/10/29 18:32:21 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	exists(const char *str, const char *to_find, size_t n)
{
	size_t	i;

	i = 0;
	while (to_find[i] != '\0')
	{
		if (str[n] != to_find[i])
			return (0);
		i++;
		n++;
	}
	return (1);
}

char	*ft_strnstr(const char	*str, const char *to_find, size_t len)
{
	size_t	i;

	i = 0;
	if (!str && !len)
		return (NULL);
	if (to_find[i] == '\0')
		return ((char *)(str));
	while (str[i] != '\0' && i < len)
	{
		if (!(ft_strlen(to_find) + i - 1 < len))
			return (NULL);
		if (str[i] == to_find[0])
		{
			if (i + ft_strlen(to_find) > len)
				return (NULL);
			if (exists(str, to_find, i))
				return ((char *)(&str[i]));
		}
		i++;
	}
	return (NULL);
}
