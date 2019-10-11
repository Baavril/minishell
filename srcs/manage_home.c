/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_home.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <baavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:39:42 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:39:44 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_current_home(t_list ***current)
{
	char	*tmp;
	char	*ret;
	int		i;

	i = 0;
	tmp = NULL;
	ret = NULL;
	if (!(tmp = ft_strdup((**current)->content)))
		return (NULL);
	while (tmp[i] != '=')
		i++;
	i++;
	if (!(ret = ft_strdup(&tmp[i])))
		return (NULL);
	free(tmp);
	return (ret);
}

static int	find_home(t_list **current, char **ret, int flag)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	if (ft_strncmp((*current)->content, "HOME=", 5) == 0)
	{
		if (!(tmp = get_current_home(&current)))
			return (0);
		if (!flag)
		{
			chdir(tmp);
			free(tmp);
			return (1);
		}
		else
		{
			if (!(*ret = ft_strdup(tmp)))
				return (0);
			free(tmp);
			return (2);
		}
	}
	return (-1);
}

char		*reach_home(t_list *current, int flag)
{
	int		val;
	char	*ret;

	val = 0;
	ret = NULL;
	while (current)
	{
		if (!(val = find_home(&current, &ret, flag)))
			return (0);
		else if (val == 1)
			return (NULL);
		else if (val == 2)
			return (ret);
		current = current->next;
	}
	if (val == -1)
		ft_putendl("HOME not set");
	return (ft_strdup("~"));
}
