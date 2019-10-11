/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:38:31 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:38:33 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	prev = NULL;
	current = *begin_list;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

t_list	*ft_create_list_env(char **env)
{
	t_list	*current;
	int		i;

	i = 0;
	current = NULL;
	while (env[i])
	{
		ft_lstadd(&current, ft_lstnew(env[i], ft_strlen(env[i]) + 1));
		i++;
	}
	ft_list_reverse(&current);
	return (current);
}
