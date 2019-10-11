/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:21:29 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:21:30 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;

	if (!(i = 0) && !(ft_strlen(needle)))
		return ((char*)haystack);
	while (*haystack && i < n)
	{
		if (*haystack == *needle)
		{
			i = 1;
			while (needle[i] && haystack[i] == needle[i] && i < n)
				i++;
			if (!(needle[i]))
				return ((char*)haystack);
		}
		haystack++;
		n--;
	}
	return (NULL);
}
