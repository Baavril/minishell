/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:39:31 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:39:32 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "g_builtins.h"

char		**get_the_path(t_list *current_env_list)
{
	int		i;
	char	**paths_tab;
	char	*path_tmp;
	t_list	*voyager;

	i = 0;
	paths_tab = NULL;
	path_tmp = NULL;
	voyager = current_env_list;
	while (voyager)
	{
		if (ft_strncmp(voyager->content, "PATH", 4) == 0)
		{
			path_tmp = ft_strdup(voyager->content);
			while (path_tmp[i] != '=')
				i++;
			i++;
			if (!(paths_tab = ft_strsplit(&path_tmp[i], ":")))
				return (NULL);
			free(path_tmp);
		}
		voyager = voyager->next;
	}
	return (paths_tab);
}

static int	launch_commands(char **shell_command, t_list *current_env_list)
{
	char **path;

	path = NULL;
	if (shell_command && *shell_command)
	{
		path = get_the_path(current_env_list);
		if (!(handle_command(path, shell_command, current_env_list)))
			return (0);
		ft_free_tabs(shell_command, NULL, NULL);
	}
	return (1);
}

static int	launch_builtins(char **shell_command, t_list *current_env_list)
{
	int i;

	i = 0;
	if (!(shell_command = dollar_var(shell_command, current_env_list)))
		return (0);
	if (*shell_command != NULL)
	{
		while (i < 6)
		{
			if (ft_strcmp(g_builtins[i].command, *shell_command) == 0)
			{
				shell_command++;
				(g_builtins[i].function_call)(current_env_list, shell_command);
				i = 0;
				shell_command--;
				ft_free_tabs(shell_command, NULL, NULL);
				return (0);
			}
			i++;
		}
	}
	return (1);
}

static int	ft_prompt(void)
{
	char	*pwd;
	int		i;

	i = 0;
	pwd = NULL;
	if (!(pwd = getcwd(0, 4096)))
		return (0);
	while (ft_isin('/', &pwd[i]) == 1 && ft_strlen(pwd) > 1)
		i++;
	ft_putstr("\033[38;5;93m");
	ft_putchar('[');
	ft_strcat(&pwd[i], "] ");
	ft_putstr(&pwd[i]);
	ft_putstr("\033[0m");
	free(pwd);
	return (1);
}

int			launch_minishell(t_list *current_env_list)
{
	char	*line;
	char	**shell_command;
	int		ret;

	ft_prompt();
	shell_command = NULL;
	if ((ret = get_next_line(0, &line)) == -1 || ft_strlen(line) < 1
	|| !(shell_command = ft_strsplit(line, " \t")) || (*shell_command == '\0'))
	{
		ft_strdel(&line);
		ft_free_tabs(shell_command, NULL, NULL);
		if (ret == 0)
			exit(0);
		return (0);
	}
	if (!(launch_builtins(shell_command, current_env_list)))
	{
		ft_strdel(&line);
		return (0);
	}
	if (!(launch_commands(shell_command, current_env_list)))
		return (0);
	ft_strdel(&line);
	return (1);
}
