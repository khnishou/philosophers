/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:10:51 by ykerdel           #+#    #+#             */
/*   Updated: 2023/04/30 09:50:51 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	d = malloc (s1_len + s2_len + 1);
	if (d == NULL)
		return (NULL);
	ft_strlcpy (d, s1, s1_len + 1);
	ft_strlcpy (d + s1_len, s2, s2_len + 1);
	return (d);
}
