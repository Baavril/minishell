/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_builtins.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:45:51 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:31:34 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_BUILTINS_H
# define G_BUILTINS_H

# include "minishell.h"

t_builtins	g_builtins[] =
{
	{"cd", &ft_cd},
	{"exit", &ft_exit},
	{"env", &ft_env},
	{"echo", &ft_echo},
	{"setenv", &ft_setenv},
	{"unsetenv", &ft_unsetenv}
};

#endif
