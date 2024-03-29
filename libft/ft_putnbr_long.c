/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:18:34 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:18:35 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_long(long n)
{
	unsigned long	i;

	if (n < 0)
		ft_putchar('-');
	i = (n < 0 ? -n : n);
	if (i >= 10)
		ft_putnbr_long(i / 10);
	ft_putchar(i % 10 + '0');
}
