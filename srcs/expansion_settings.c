/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:39:18 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:39:19 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_nbr_dollar(char *shell_command)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (shell_command[i])
	{
		if (shell_command[i] == '$')
			ret++;
		i++;
	}
	return (ret);
}

int	set_begin(char *shell_command, char **tmp_var, int i)
{
	char	*begin_var;

	begin_var = NULL;
	if (shell_command[i] != '$' && i == 0)
	{
		begin_var = get_begin(&shell_command[i], 0);
		*tmp_var = ft_strdup(begin_var);
		free(begin_var);
	}
	return (1);
}

int	get_middle_token(char *shell_command, char **tmp_var, int i)
{
	char	*middle_var;

	middle_var = NULL;
	if (!(middle_var = get_begin(&shell_command[i], 1)))
		return (0);
	if (middle_var)
	{
		*tmp_var = ft_strjoinfree(*tmp_var, middle_var);
		ft_strdel(&middle_var);
	}
	return (1);
}

int	translate_expansion(char **keeper, t_list **tmp, char ***tmp_var)
{
	if (!(*keeper = get_value((*tmp)->content)))
		return (0);
	if (!(**tmp_var))
	{
		if (!(**tmp_var = get_value((*tmp)->content)))
			return (0);
	}
	else
		**tmp_var = ft_strjoinfree(**tmp_var, *keeper);
	return (1);
}
