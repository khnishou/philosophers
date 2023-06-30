/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@sudent.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:10:16 by ykerdel           #+#    #+#             */
/*   Updated: 2022/10/29 13:30:47 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*d;

	len = ft_strlen(s);
	if (!s)
		return (0);
	d = malloc(len + 1);
	if (!d)
		return (0);
	i = 0;
	while (i < len)
	{
		d[i] = f(i, s[i]);
		i++;
	}
	d[len] = 0;
	return (d);
}
