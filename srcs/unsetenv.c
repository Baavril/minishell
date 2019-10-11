/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:39:58 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:39:59 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_list(t_list *current_env_list)
{
	while (current_env_list)
	{
		ft_putendl(current_env_list->content);
		current_env_list = current_env_list->next;
	}
}

static int	unsetvar(t_list *current, char **var_name, char **tmp_name)
{
	t_list *relink;

	while (current && current->next)
	{
		if (!(*var_name = get_name(current->next->content)))
			return (0);
		if (ft_strcmp(*var_name, *tmp_name) == 0)
		{
			relink = current->next;
			current->next = current->next->next;
			free(relink->content);
			free(relink);
		}
		free(*var_name);
		current = current->next;
	}
	return (1);
}

int			ft_unsetenv(t_list *current_env_list, char **shell_command)
{
	t_list	*tmp;
	char	*tmp_name;
	char	*var_name;

	if (!(tmp_name = get_name(*shell_command)))
		return (0);
	if (!(unsetvar(current_env_list, &var_name, &tmp_name)))
		return (0);
	tmp = current_env_list;
	if (!(var_name = get_name(tmp->content)))
		return (0);
	if (tmp && (ft_strcmp(var_name, tmp_name) == 0))
	{
		current_env_list = tmp->next;
		free(tmp);
	}
	free(tmp_name);
	free(var_name);
	return (1);
}
