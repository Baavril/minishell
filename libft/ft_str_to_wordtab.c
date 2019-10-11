/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_wordtab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:18:56 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:26:33 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char *str)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if ((str[i] == ' ' && str[i + 1] != ' ')
		|| str[i + 1] == '\0')
			w++;
		i++;
	}
	return (w);
}

static int	ft_count_char(char *str)
{
	int	c;

	c = 0;
	while ((str[c] != ' ') && (str[c] != '\0') && (str[c] != '\n'))
		c++;
	c += 1;
	return (c);
}

char		**ft_str_to_wordtab(char *str)
{
	int		i;
	int		c;
	int		k;
	char	**tab;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * ft_count_word(str) + 1)))
		return (NULL);
	k = 0;
	while (k < ft_count_word(str))
	{
		c = 0;
		while (str[i] == ' ' && str[i] != '\0' && str[i] != '\n')
			i++;
		if (!(tab[k] = (char*)malloc(sizeof(char) * ft_count_char(str) + 1)))
			return (NULL);
		while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
			tab[k][c++] = str[i++];
		tab[k][c] = '\0';
		k++;
	}
	tab[k] = 0;
	ft_print_wordtab(tab);
	return (tab);
}
