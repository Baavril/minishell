/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:38:20 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:38:22 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int
	ft_env_management_i(char **shell_command, char **path)
{
	char	**print_env;
	int		i;

	i = 0;
	if (!(print_env = (char**)ft_memalloc(sizeof(char*)
	* ft_tablen(shell_command) + 8)))
		return (0);
	while (shell_command[i])
	{
		if (ft_isin('=', shell_command[i]) == 1)
		{
			print_env[i] = ft_strdup(shell_command[i]);
			i++;
		}
		else
		{
			ft_free_tabs(print_env, NULL, NULL);
			handle_command(path, shell_command, NULL);
			return (0);
		}
	}
	print_env[i] = 0;
	ft_print_wordtab(print_env);
	ft_free_tabs(print_env, NULL, NULL);
	return (1);
}

static int
	env_tmp(char **path, char **shell_command, char ***tmp_env, int n)
{
	t_list	*tmp;
	int		j;

	j = 0;
	tmp = NULL;
	while (shell_command[j])
	{
		if (ft_isin('=', shell_command[j]) == 1)
		{
			tmp_env[0][n] = ft_strdup(shell_command[j]);
			j++;
			n++;
		}
		else
		{
			tmp_env[0][n] = 0;
			tmp = ft_create_list_env(*tmp_env);
			ft_free_tabs(*tmp_env, NULL, NULL);
			handle_command(path, shell_command, tmp);
			ft_lstfree(&tmp);
			return (0);
		}
	}
	tmp_env[0][n] = 0;
	return (1);
}

int
	ft_env_management(char **shell_command, char **path, t_list *current)
{
	char	**tmp_env;
	int		n;
	int		j;

	j = 0;
	n = 0;
	tmp_env = NULL;
	if (!(tmp_env = (char**)ft_memalloc(sizeof(char*)
	* (ft_tablen(shell_command) + ft_lstlen(current) + 1))))
		return (0);
	while (current)
	{
		tmp_env[j] = ft_strdup(current->content);
		j++;
		current = current->next;
	}
	n = j;
	if (!(env_tmp(path, shell_command, &tmp_env, n)))
		return (0);
	ft_print_wordtab(tmp_env);
	ft_free_tabs(tmp_env, NULL, NULL);
	return (1);
}

static int
	env_options(char **shell_command, char **path, t_list *current_env_list)
{
	if (ft_strcmp(*shell_command, "-i") == 0)
	{
		shell_command++;
		if (ft_env_management_i(shell_command, path) == 1)
		{
			ft_free_tabs(NULL, path, NULL);
			return (0);
		}
	}
	else if (ft_strncmp(*shell_command, "-", 1) == 0)
	{
		ft_print_errors(*shell_command, 2);
		ft_free_tabs(NULL, path, NULL);
		return (0);
	}
	else
	{
		if (ft_env_management(shell_command, path, current_env_list) == 1)
		{
			ft_free_tabs(NULL, path, NULL);
			return (0);
		}
	}
	return (0);
}

int
	ft_env(t_list *current_env_list, char **shell_command)
{
	char	**path;

	path = NULL;
	path = get_the_path(current_env_list);
	if (*shell_command == NULL)
	{
		print_list(current_env_list);
		ft_free_tabs(NULL, path, NULL);
		return (1);
	}
	else
	{
		if (!(env_options(shell_command, path, current_env_list)))
			return (0);
	}
	return (0);
}
