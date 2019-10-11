/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:19:03 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:19:04 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strappend(char **dest, char **src)
{
	char	*tmp;
	size_t	i;

	i = ft_strlen(*dest) + ft_strlen(*src) + 1;
	if (!(tmp = (char*)malloc(i)))
		return ;
	ft_memcpy(tmp, *dest, ft_strlen(*dest) + 1);
	tmp = ft_strcat(tmp, *src);
	ft_memdel((void**)dest);
	ft_memdel((void**)src);
	*dest = tmp;
}
