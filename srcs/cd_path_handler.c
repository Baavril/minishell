/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:38:03 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:38:05 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_oldpwd(t_list *current_env_list)
{
	char	*pwd;
	char	*pwd_path;
	char	*oldpwd;

	pwd = NULL;
	pwd_path = NULL;
	oldpwd = NULL;
	if (!(pwd = getcwd(0, 4096)))
		return (0);
	if (!(pwd_path = ft_strdup("OLDPWD=")))
		return (0);
	if (!(oldpwd = ft_strjoinfree(pwd_path, pwd)))
		return (0);
	free(pwd);
	if (!(setvar(current_env_list, oldpwd)))
		return (0);
	free(oldpwd);
	return (1);
}

int	oldpwd_settings(t_list *current_env_list)
{
	t_list	*list;
	int		flag;

	flag = 0;
	list = current_env_list;
	while (list)
	{
		if (ft_strncmp(list->content, "OLDPWD=", 7) == 0)
			flag++;
		list = list->next;
	}
	if (!flag)
	{
		if (!(set_oldpwd(current_env_list)))
			return (0);
	}
	return (1);
}

int	change_pwd(t_list *current_env_list)
{
	char	*pwd;
	char	*pwd_path;

	pwd = NULL;
	pwd_path = NULL;
	while (current_env_list)
	{
		if (ft_strncmp((char*)current_env_list->content, "PWD=", 4) == 0)
		{
			if (!(pwd = getcwd(0, 4096)))
				return (0);
			if (!(pwd_path = ft_strdup("PWD=")))
				return (0);
			ft_strdel((void*)&current_env_list->content);
			if (!(current_env_list->content = ft_strjoinfree(pwd_path, pwd)))
				return (0);
			if (pwd)
				free(pwd);
			return (1);
		}
		current_env_list = current_env_list->next;
	}
	return (0);
}
