/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:38:54 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:45:07 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

static int
	execute_path_function(char **function, char **tabenv)
{
	char	*command_path;
	char	**tmp_tabenv;
	int		i;

	i = 0;
	command_path = NULL;
	tmp_tabenv = NULL;
	tmp_tabenv = tabenv;
	while (function[i] && function[i + 1]
			&& tmp_tabenv[i] && ft_isin('=', function[i]) == 1)
		i++;
	if (ft_strncmp(function[i], "/", 1) == 0
			|| ft_strncmp(function[i], "./", 2) == 0)
	{
		if (!(command_path = ft_strdup(function[i])))
			return (0);
		if (check_execerrors(&command_path, function, tabenv) == -1)
		{
			free(command_path);
			ft_print_errors(*function, 4);
		}
		return (1);
	}
	return (0);
}

static int
	find_function(char **path, char ***function, char **tabenv, int flag)
{
	DIR				*dirhandle;
	struct dirent	*filedata;
	char			*path_tmp;
	char			*tmp_path;

	path_tmp = NULL;
	tmp_path = NULL;
	while (*path)
	{
		if (!(dirhandle = opendir(*path)))
			return (-1);
		while ((filedata = readdir(dirhandle)))
		{
			if (ft_strcmp(filedata->d_name, **function) == 0)
			{
				path_tmp = ft_strjoin(*path, "/");
				tmp_path = ft_strjoinfree(path_tmp, filedata->d_name);
				check_execerrors(&tmp_path, *function, tabenv);
				flag++;
			}
		}
		closedir(dirhandle);
		path++;
	}
	return (flag);
}

static int
	execute_function(char **path, char **function, char **tabenv)
{
	int	flag;

	flag = 0;
	while (ft_isin('=', *function) == 1 && *(function + 1))
		function++;
	if ((flag = find_function(path, &function, tabenv, flag)) == -1)
		return (0);
	if (!flag)
		ft_print_errors(*function, 1);
	return (1);
}

int
	handle_command(char **path, char **function, t_list *current)
{
	char	**tabenv;

	tabenv = NULL;
	if (!(tabenv = (current == NULL) ?
				ft_create_env_tab(function)
				: ft_recreate_env_tab(current)))
	{
		ft_free_tabs(NULL, path, NULL);
		return (0);
	}
	if (execute_path_function(function, tabenv) == 1)
	{
		ft_free_tabs(path, NULL, tabenv);
		return (1);
	}
	if (!path || !(execute_function(path, function, tabenv)))
		ft_print_errors(*function, 1);
	ft_free_tabs(path, NULL, tabenv);
	return (1);
}
