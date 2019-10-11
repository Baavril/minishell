/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_builtins_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:39:47 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:39:48 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_exit(t_list *current_env_list, char **shell_command)
{
	char *line;

	(void)shell_command;
	(void)current_env_list;
	close(0);
	line = NULL;
	get_next_line(0, &line);
	ft_strdel(&line);
	exit(0);
}

int		cd_hyphen(int flag)
{
	char	*pwd;

	pwd = NULL;
	if (!(g_cd_path) && flag)
	{
		if (!(pwd = getcwd(0, 4096)))
			return (0);
		ft_putendl(pwd);
		free(pwd);
		return (2);
	}
	return (-1);
}

void	ft_putmstr(char *str)
{
	while (*str)
	{
		if (!(*str == '"'))
			ft_putchar(*str);
		str++;
	}
	ft_putchar(' ');
}

int		ft_echo(t_list *current_env_list, char **shell_command)
{
	(void)current_env_list;
	while (shell_command && *shell_command)
	{
		ft_putmstr(*shell_command);
		shell_command++;
	}
	ft_putstr("\n");
	return (1);
}
