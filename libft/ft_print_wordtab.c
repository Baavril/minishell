/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wordtab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:13:14 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:25:01 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_print_wordtab(char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (tab[i])
		i++;
	j = 0;
	while (j < i)
	{
		k = 0;
		while (tab[j][k])
			ft_putchar(tab[j][k++]);
		ft_putchar('\n');
		j++;
	}
}
