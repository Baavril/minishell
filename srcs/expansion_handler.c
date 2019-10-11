/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:39:13 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:39:14 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int
	find_expansion(char **tmp_sec, char **tmp_var, t_list *current_env_list)
{
	char	*var_name;
	char	*keeper;
	t_list	*tmp;

	keeper = NULL;
	tmp = current_env_list;
	while (tmp)
	{
		if (!(var_name = get_name(tmp->content)))
			return (0);
		if (ft_strcmp(*tmp_sec, var_name) == 0)
		{
			if (!(translate_expansion(&keeper, &tmp, &tmp_var)))
				return (0);
			free(var_name);
			free(keeper);
			break ;
		}
		free(var_name);
		tmp = tmp->next;
		if (!tmp && !ft_strcmp("$", *tmp_sec))
			*tmp_var = ft_strjoinfree(*tmp_var, *tmp_sec);
	}
	free(*tmp_sec);
	return (1);
}

static int
	tokenisation(char *shell_command, char **tmp_var, int i)
{
	if (!(set_begin(shell_command, tmp_var, i)))
		return (0);
	while (shell_command[i] != '$' && ft_isalnum(shell_command[i]))
		i++;
	if (!(get_middle_token(shell_command, tmp_var, i)))
		return (0);
	while (shell_command[i] != '$')
		i++;
	return (i);
}

static char
	*find_value(char *shell_command, t_list *current_env_list)
{
	int		ret;
	int		i;
	char	*tmp_sec;
	char	*tmp_var;
	char	*end_var;

	i = 0;
	tmp_var = NULL;
	ret = get_nbr_dollar(shell_command);
	while (ret > 0)
	{
		i = tokenisation(shell_command, &tmp_var, i);
		if (!(tmp_sec = get_exp(&shell_command[i])))
			return (0);
		i++;
		if (ret == 1)
			end_var = get_end(&shell_command[i]);
		if (!(find_expansion(&tmp_sec, &tmp_var, current_env_list)))
			return (0);
		ret--;
	}
	if (end_var)
		tmp_var = ft_strjoinfree(tmp_var, end_var);
	ft_strdel(&end_var);
	return (tmp_var);
}

char
	**dollar_var(char **shell_command, t_list *current_env_list)
{
	int		j;
	char	*str;

	j = 0;
	str = NULL;
	while (shell_command[j])
	{
		if (ft_isin('$', shell_command[j]) && shell_command[j][1]
				&& shell_command[j][1] != '$' && shell_command[j][1] != '~'
				&& shell_command[j][1] != '?')
		{
			str = shell_command[j];
			shell_command[j] = find_value(str, current_env_list);
			ft_strdel(&str);
		}
		else if (shell_command[j][0] == '~'
		&& shell_command[j][1] == '\0')
		{
			free(shell_command[j]);
			shell_command[j] = reach_home(current_env_list, 1);
		}
		j++;
	}
	return (shell_command);
}
