/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:20:42 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:20:43 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*res;

	if (!(s))
		return (NULL);
	i = ft_strlen(s) + 1;
	if (!(res = (char*)malloc(sizeof(*s) * i)))
		return (NULL);
	i = 0;
	while (*s)
		res[i++] = (*f)(*s++);
	res[i] = '\0';
	return (res);
}
