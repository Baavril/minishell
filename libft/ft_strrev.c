/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:21:37 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:21:39 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	l;
	size_t	c;
	char	tmp;

	c = ft_strlen(str);
	l = 0;
	while (l < c / 2)
	{
		tmp = str[l];
		str[l] = str[c - l - 1];
		str[c - l - 1] = tmp;
		l++;
	}
	return (str);
}
