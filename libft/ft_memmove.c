/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:57 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:12:58 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = (dst < src ? 0 : n - 1);
		while (ft_btw(i, 0, n - 1))
		{
			*((char*)dst + i) = *((char*)src + i);
			i += (dst < src ? 1 : -1);
		}
	}
	return (dst);
}
