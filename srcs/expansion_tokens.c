/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:39:25 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:39:27 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_begin(char *str, int lim)
{
	int		i;
	char	*begin;

	i = 0;
	begin = NULL;
	if (!lim)
	{
		while (str[i] && str[i] != '$' && ft_isalnum(str[i]))
			i++;
	}
	else
	{
		while (str[i] && str[i] != '$')
			i++;
	}
	if (!(begin = ft_strndup(str, i)))
		return (0);
	return (begin);
}

char	*get_exp(char *str)
{
	int		i;
	char	*ret;
	char	*tmp;

	ret = NULL;
	tmp = NULL;
	i = ft_strcspn(str, "$") + 1;
	if (!ft_isalnum(str[i]))
	{
		i--;
		return (ft_strdup("$"));
	}
	tmp = &str[i];
	while (tmp[i] && ft_isalnum(tmp[i]))
		i++;
	if (!(ret = ft_strndup(tmp, i)))
		return (0);
	return (ret);
}

char	*get_value(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (str[i] && str[i] != '=')
		i++;
	i++;
	if (!(ret = ft_strdup(&str[i])))
		return (0);
	return (ret);
}

char	*get_end(char *str)
{
	int		i;

	i = 0;
	while (ft_isalnum(str[i]))
		i++;
	return (ft_strdup(&str[i]));
}
