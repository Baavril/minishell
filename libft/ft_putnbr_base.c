/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:13:53 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:13:54 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verif_base(char *str)
{
	while (*str)
	{
		if (ft_isin(*str, str + 1) || ft_isin(*str, "+-/*"))
			return (0);
		str++;
	}
	return (1);
}

void		ft_putnbr_base(int n, char *base)
{
	unsigned int	i;
	size_t			j;

	if (!(ft_verif_base(base)) || !(j = ft_strlen(base)))
	{
		ft_putstr_fd("Usage : les bases correctes sont non vides, sans doublons\
				,et sans operateur", 2);
		return ;
	}
	j = ft_strlen(base);
	if (n < 0)
		ft_putchar('-');
	i = (n < 0 ? -n : n);
	if (i >= j)
		ft_putnbr_base(i / j, base);
	ft_putchar(base[i % j]);
}
