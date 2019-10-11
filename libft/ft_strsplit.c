/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:21:47 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:21:49 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline static size_t
	separator(char const a, char *b)
{
	while (*b)
	{
		if (a == *b)
			return (a == *b);
		b++;
	}
	return (0);
}

inline static size_t
	ft_countwords(char const *str, char *c)
{
	int	i;
	int	nb_word;

	i = 0;
	nb_word = 0;
	if (!separator(str[0], c))
		nb_word = 1;
	while (str[i] != '\0')
	{
		if (separator(str[i], c) && str[i] != '\0')
		{
			if (!(separator(str[i + 1], c) || str[i + 1] == '\0'))
			{
				nb_word++;
				i++;
			}
		}
		i++;
	}
	return (nb_word);
}

inline static char
	**ft_strdup_modif(char const *str, int i, char **tab, char *c)
{
	int j;
	int nb_char;

	nb_char = 0;
	j = 0;
	while (!(separator(str[j], c) || str[j] == '\0'))
	{
		nb_char++;
		j++;
	}
	if (nb_char == 0)
		return (tab);
	if (!(tab[i] = ft_strnew(nb_char)))
		return (NULL);
	j = 0;
	while (!(separator(str[j], c) || str[j] == '\0'))
	{
		tab[i][j] = str[j];
		j++;
	}
	return (tab);
}

char
	**ft_strsplit(char const *str, char *c)
{
	int		i;
	int		k;
	char	**tab;

	i = 0;
	if (!str)
		return (NULL);
	k = ft_countwords(str, c);
	if (!(tab = (char**)ft_memalloc(sizeof(*tab) * (k + 1))))
		return (NULL);
	while (i < k)
	{
		while (separator(*str, c) && *str != '\0')
			str++;
		ft_strdup_modif(str, i, tab, c);
		while (!(separator(*str, c) || *str == '\0'))
			str++;
		i++;
	}
	return (tab);
}
