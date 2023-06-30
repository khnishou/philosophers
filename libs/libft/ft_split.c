/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:43:17 by ykerdel           #+#    #+#             */
/*   Updated: 2023/01/20 22:48:23 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **tab, size_t rows)
{
	size_t	i;

	i = 0;
	while (i < rows)
	{
		free (tab[i]);
		i++;
	}
	free (tab);
	return ((void) 0);
}

static size_t	delimiter(char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

static char	**condition(char **tab, size_t rows, char const *s, char c)
{
	int		len;
	int		i;
	int		i_tab;
	int		start;

	i_tab = 0;
	i = -1;
	while (++i < (int) ft_strlen(s))
	{
		if (s[i] != c)
			start = i;
		len = 0;
		while (s[i] != c && i < (int) ft_strlen(s))
		{
			len++;
			if ((s[i + 1] == c || s[i + 1] == 0))
			{
				tab[i_tab++] = ft_substr(s, start, len);
				if (tab == NULL)
					ft_free(tab, rows);
			}
			i++;
		}
	}
	return (tab);
}

static char	**alloc(char const *s, char c, size_t rows)
{
	char	**tab;

	tab = (char **)malloc((rows + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = condition(tab, rows, s, c);
	tab[rows] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	rows;

	if (s == 0)
		return (0);
	rows = delimiter(s, c);
	return (alloc(s, c, rows));
}
