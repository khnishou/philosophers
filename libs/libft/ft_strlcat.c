/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:37:47 by ykerdel           #+#    #+#             */
/*   Updated: 2022/11/08 17:08:28 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	i;

	if (((!src || !dest) && !size))
		return (0);
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (s_len);
	while ((src[i] != '\0') && (i + d_len < (size - 1)))
	{
		dest[i + d_len] = src[i];
		i++;
	}
	if (i && i < size)
		dest[i + d_len] = '\0';
	if (d_len > size)
		return (s_len + size);
	return (d_len + s_len);
}
