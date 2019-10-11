/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:16 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:12:17 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *cont, size_t cont_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (NULL);
	new->content_size = ((cont) ? cont_size : 0);
	if (!(new->content = (void*)ft_memalloc(new->content_size)))
		return (NULL);
	new->content = ((cont) ? ft_memcpy(new->content, cont, cont_size) : NULL);
	new->next = NULL;
	return (new);
}
