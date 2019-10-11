/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:37:52 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:37:56 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int
	cd_execute(char **shell_command, int flag)
{
	if (g_cd_path && flag && ft_strncmp(g_cd_path, "OLDPWD=", 7) == 0)
	{
		while (ft_isin('=', g_cd_path) == 1)
			g_cd_path++;
		if (chdir(g_cd_path) == 0)
		{
			ft_putendl(g_cd_path);
			while (*g_cd_path != 'O')
				g_cd_path--;
			return (2);
		}
		else
		{
			ft_print_errors(*shell_command, 0);
			return (0);
		}
	}
	ft_putendl("cd: OLDPWD not set");
	return (-1);
}

static int
	ft_cd_global_handle(char **shell_command, t_list *current)
{
	int		flag;
	int		handle;

	flag = 0;
	handle = 0;
	if (*shell_command == NULL)
	{
		reach_home(current, 0);
		return (2);
	}
	while (current)
	{
		if (ft_strncmp(current->content, "OLDPWD=", 7) == 0)
			flag++;
		current = current->next;
	}
	if (**shell_command == '-' && *(*shell_command + 1) == '\0')
	{
		if ((handle = cd_hyphen(flag)) >= 0)
			return (handle);
		if ((handle = cd_execute(shell_command, flag)) >= 0)
			return (handle);
	}
	return (0);
}

static int
	find_oldpwd(t_list **current, char **pwd, char **pwd_path, int handle)
{
	while (*current)
	{
		if (ft_strncmp((*current)->content, "OLDPWD=", 7) == 0)
		{
			if (!(*pwd_path = ft_strdup("OLDPWD=")))
				return (0);
			free((*current)->content);
			if (!((*current)->content = ft_strjoinfree(*pwd_path, *pwd)))
				return (0);
			if (g_cd_path)
				ft_strdel(&g_cd_path);
			if (!(g_cd_path = ft_strdup((*current)->content)))
				return (0);
			free(*pwd);
			if (handle == 2)
				return (2);
			return (1);
		}
		if ((*current)->next != NULL)
			(*current) = (*current)->next;
		else
			break ;
	}
	free(*pwd);
	return (-1);
}

static int
	change_oldpwd(t_list *current_env_list, char **shell_command)
{
	char	*pwd;
	int		handle;
	char	*pwd_path;

	pwd_path = NULL;
	handle = 0;
	pwd = NULL;
	if (!(pwd = getcwd(0, 4096)))
		return (0);
	handle = ft_cd_global_handle(shell_command, current_env_list);
	if ((handle = find_oldpwd(&current_env_list, &pwd, &pwd_path, handle)) >= 0)
		return (handle);
	if (handle == -1)
	{
		if (!(oldpwd_settings(current_env_list)))
			return (0);
		current_env_list = current_env_list->next;
	}
	if (g_cd_path)
		ft_strdel(&g_cd_path);
	if (!(g_cd_path = ft_strdup(current_env_list->content)))
		return (0);
	if (handle == 2)
		return (2);
	return (0);
}

int
	ft_cd(t_list *current_env_list, char **shell_command)
{
	int	handle_path;

	handle_path = change_oldpwd(current_env_list, shell_command);
	if (!(change_pwd(current_env_list)) || handle_path == 2)
		return (0);
	if (chdir(*shell_command) == 0)
	{
		if (!(change_pwd(current_env_list)))
			return (0);
	}
	else
	{
		if (handle_path == 0)
			return (0);
		ft_print_errors(*shell_command, 0);
		return (0);
	}
	return (1);
}
