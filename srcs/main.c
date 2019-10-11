/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:39:37 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:39:38 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*g_cd_path = NULL;

int		main(int argc, char **argv, char **env)
{
	t_list	*current_env_list;

	(void)argc;
	(void)argv;
	current_env_list = NULL;
	if (!(current_env_list = (env && *env)
	? ft_create_list_env(env) : ft_install_env()))
		return (0);
	if (!(ft_modify_shlvl(current_env_list)))
		return (0);
	while (42)
		launch_minishell(current_env_list);
	return (0);
}
