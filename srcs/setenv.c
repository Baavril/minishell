/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:39:53 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:39:54 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_name(char *var)
{
	int		i;
	char	*rav;

	i = 0;
	rav = NULL;
	while (var[i] && var[i] != '=')
		i++;
	if (!(rav = ft_strndup(var, i)))
		return (0);
	return (rav);
}

static	int	reachvar(t_list *check_list, char **tmp_name, char *shell_command)
{
	char	*var_name;

	var_name = NULL;
	while (check_list)
	{
		if (!(var_name = get_name(check_list->content)))
			return (0);
		if (ft_strcmp(var_name, *tmp_name) == 0)
		{
			free(check_list->content);
			check_list->content_size = ft_strlen(shell_command);
			if (!(check_list->content = ft_strdup(shell_command)))
				return (0);
			if (ft_strncmp("OLDPWD=", shell_command, 7) == 0)
				g_cd_path = ft_strdup(shell_command);
			free(var_name);
			free(*tmp_name);
			return (1);
		}
		else
			free(var_name);
		check_list = check_list->next;
	}
	return (2);
}

static int	checkvar(t_list *check_list, char *shell_command)
{
	char	*tmp_name;

	tmp_name = NULL;
	if (!(tmp_name = get_name(shell_command)))
		return (0);
	if (reachvar(check_list, &tmp_name, shell_command) == 1)
		return (1);
	free(tmp_name);
	return (2);
}

int			setvar(t_list *current_env_list, char *shell_command)
{
	t_list	*new_back;

	new_back = NULL;
	if (!(new_back = ft_lstnew(shell_command, ft_strlen(shell_command) + 1)))
		return (0);
	if (ft_isin('=', shell_command))
		ft_lstadd_back(&current_env_list, new_back);
	else
	{
		ft_putendl("Wrong Syntax. Setenv bultin syntax : var=value");
		if (new_back)
		{
			free(new_back->content);
			free(new_back);
		}
	}
	return (1);
}

int			ft_setenv(t_list *current_env_list, char **shell_command)
{
	t_list	*tmp;
	int		flag;

	flag = 0;
	while (*shell_command)
	{
		tmp = current_env_list;
		if (!(flag = checkvar(tmp, *shell_command)))
			return (0);
		if (flag != 1)
		{
			if (!(setvar(tmp, *shell_command)))
				return (0);
		}
		shell_command++;
	}
	shell_command++;
	return (1);
}
