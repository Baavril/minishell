/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:12:10 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:12:11 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*new_bot;

	if (lst)
	{
		if (!(new = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		new = (*f)(new);
		new_bot = new;
	}
	else
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(new_bot = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		new_bot = (*f)(new_bot);
		ft_lstadd_back(&new, new_bot);
	}
	return (new);
}
