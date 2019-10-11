/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:21:14 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:21:15 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*dup;

	i = (n < ft_strlen(str) ? n : ft_strlen(str));
	if (!(dup = (char *)malloc(sizeof(*dup) * (i + 1))))
		return (NULL);
	dup[i] = '\0';
	while (i-- > 0)
		dup[i] = str[i];
	return (dup);
}
