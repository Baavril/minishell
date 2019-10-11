/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tab_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:38:46 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:38:47 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		ft_lstlen(t_list *current_env_list)
{
	int	i;

	i = 0;
	while (current_env_list)
	{
		current_env_list = current_env_list->next;
		i++;
	}
	return (i);
}

char	**ft_recreate_env_tab(t_list *current_env_list)
{
	char	**tmp_envtab;
	t_list	*keep_list;
	int		i;

	i = 0;
	tmp_envtab = NULL;
	keep_list = current_env_list;
	if (!(tmp_envtab = (char**)malloc(sizeof(char*)
	* ft_lstlen(current_env_list) + 8)))
		return (0);
	while (current_env_list)
	{
		tmp_envtab[i] = ft_strdup(current_env_list->content);
		current_env_list = current_env_list->next;
		i++;
	}
	tmp_envtab[i] = 0;
	return (tmp_envtab);
}

char	**ft_create_env_tab(char **shell_command)
{
	char	**tmp_envtab;
	int		i;

	i = 0;
	tmp_envtab = NULL;
	if (!(*shell_command))
		return (0);
	if (!(tmp_envtab = (char**)malloc(sizeof(char*)
	* ft_tablen(shell_command) + 8)))
		return (0);
	while (shell_command[i + 1] != NULL)
	{
		tmp_envtab[i] = ft_strdup(shell_command[i]);
		i++;
	}
	tmp_envtab[i] = 0;
	return (tmp_envtab);
}
