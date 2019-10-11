/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:39:06 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:42:27 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int
	execution(char **command_path, char **function_to_find, char **tabenv)
{
	pid_t	process;
	int		status;

	if ((process = fork()))
	{
		waitpid(process, &status, WUNTRACED);
		ft_strdel(command_path);
		return (status);
	}
	else
		execve(*command_path, function_to_find, tabenv);
	return (1);
}

int
	check_execerrors(char **command_path,
	char **function_to_find, char **tabenv)
{
	struct stat	filestat;

	stat(*command_path, &filestat);
	if (access(*command_path, F_OK) == 0 && !(filestat.st_mode & S_IFDIR))
	{
		if (access(*command_path, X_OK) == 0)
			execution(command_path, function_to_find, tabenv);
		else
		{
			ft_putstr("minishell: permission denied: ");
			ft_putendl(*command_path);
			ft_strdel(command_path);
		}
	}
	else
		return (-1);
	return (1);
}
