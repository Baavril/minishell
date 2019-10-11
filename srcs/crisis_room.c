/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crisis_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:38:10 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:38:12 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void
	ft_print_errors(char *error, int flag)
{
	if (*error && flag == 0)
	{
		ft_putstr("minishell: cd: ");
		ft_putstr(error);
		ft_putendl(": No such file or directory");
	}
	if (*error && flag == 1)
	{
		ft_putstr(error);
		ft_putendl(": command not found");
	}
	if (*error && flag == 2)
	{
		ft_putstr("env : option [");
		ft_putstr(error);
		ft_putendl("] is not setted yet");
		ft_putendl("Usage : env [-i] [expansions] [binaire]");
	}
	if (*error && flag == 4)
	{
		ft_putstr("minishell: no such file or directory: ");
		ft_putendl(error);
	}
}

void
	ft_free_tabs(char **path_to_open, char **function_to_find, char **tabenv)
{
	int	i;

	i = 0;
	if (path_to_open)
	{
		while (path_to_open[i])
			ft_strdel(&(path_to_open[i++]));
		free(path_to_open);
	}
	i = 0;
	if (function_to_find)
	{
		while (function_to_find[i])
			ft_strdel(&(function_to_find[i++]));
		free(function_to_find);
	}
	i = 0;
	if (tabenv)
	{
		while (tabenv[i])
			ft_strdel(&(tabenv[i++]));
		free(tabenv);
	}
}
