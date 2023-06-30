/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:03:26 by ykerdel           #+#    #+#             */
/*   Updated: 2022/11/09 17:35:44 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	tt_strlcpy(char *dest, const char *src, double size)
{
	unsigned int	i;
	unsigned int	lsrc;

	size = size + 1;
	lsrc = 0;
	while (src[lsrc] != '\0')
		lsrc++;
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (lsrc);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	size;

	if (start >= ft_strlen (s))
		return (ft_strdup (""));
	else if (ft_strlen(s) - start < len)
		size = ft_strlen(s) - start;
	else
		size = len;
	d = malloc (size + 1);
	if (d == NULL)
		return (NULL);
	tt_strlcpy(d, s + start, len);
	return (d);
}
