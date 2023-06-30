/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@sudent.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:46:55 by khnishou          #+#    #+#             */
/*   Updated: 2022/10/29 13:39:55 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;

	cc = (char) c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == cc)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}
