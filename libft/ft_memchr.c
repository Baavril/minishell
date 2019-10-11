/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:31 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:12:32 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (!(*((unsigned char*)s + (i * sizeof(*s))) - (unsigned char)c))
			return ((void*)(s + (i * sizeof(*s))));
		i++;
	}
	return (NULL);
}
