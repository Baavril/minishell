/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:38:40 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:38:41 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_modify_shlvl(t_list *current_env_list)
{
	int		l;
	char	*concat;

	l = 1;
	concat = NULL;
	while (current_env_list)
	{
		if (ft_strncmp(current_env_list->content, "SHLVL=", 6) == 0)
		{
			while (*((char*)(current_env_list->content)) != '=')
				current_env_list->content++;
			current_env_list->content++;
			l += ft_atoi(&(*(char*)(current_env_list->content)));
			if (!(concat = ft_itoa(l)))
				return (0);
			*((char*)(current_env_list->content)) = '\0';
			ft_strcat(current_env_list->content, concat);
			while (*((char*)(current_env_list->content)) != 'S')
				current_env_list->content--;
			free(concat);
		}
		current_env_list = current_env_list->next;
	}
	return (1);
}

t_list	*ft_install_env(void)
{
	char	*pwd;
	char	**cpy;
	t_list	*create_env_list;

	pwd = NULL;
	cpy = NULL;
	create_env_list = NULL;
	if (!(cpy = (char**)ft_memalloc(sizeof(char*) * 4)))
		return (0);
	if (!(pwd = getcwd(0, 4096)))
		return (0);
	if (!(cpy[0] = ft_strjoin("PWD=", pwd)))
		return (0);
	if (!(cpy[1] = ft_strdup("SHLVL=0")))
		return (0);
	if (!(create_env_list = ft_create_list_env(cpy)))
	{
		ft_free_tabs(cpy, NULL, NULL);
		ft_strdel(&pwd);
		return (0);
	}
	ft_free_tabs(cpy, NULL, NULL);
	ft_strdel(&pwd);
	return (create_env_list);
}
