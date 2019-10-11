/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:34:04 by baavril           #+#    #+#             */
/*   Updated: 2018/11/27 13:40:52 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubfree(char const *s1, unsigned int go, size_t len)
{
	char *ret;

	if (!(ret = ft_strsub(s1, go, len)))
		return (NULL);
	ft_strdel((char**)&s1);
	return (ret);
}
