/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:06:40 by baavril           #+#    #+#             */
/*   Updated: 2019/10/09 13:41:25 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>

extern char		*g_cd_path;

typedef struct	s_builtins
{
	char		*command;
	int			(*function_call)(t_list*, char **);
}				t_builtins;

t_list			*ft_create_list_env(char **env);
int				handle_command(char **path, char **function, t_list *current);
int				set_pwd_path(t_list *current_env_list, char *pwd_path);
void			ft_print_errors(char *error, int flag);
char			**get_the_path(t_list *current_env_list);
int				fork_the_prog(char **path, char **shell_command,
				t_list *current_env_list);
void			delete_list(t_list *list_to_del, int flag);
int				ft_tablen(char **tab);
void			print_list(t_list *current_env_list);
char			*get_name(char *var);
int				ft_lstlen(t_list *current_env_list);

t_list			*ft_install_env();
int				ft_modify_shlvl(t_list *current_env_list);
int				launch_minishell(t_list *current_env_list);

int				execution(char **command_path, char **function_to_find,
				char **tabenv);
int				check_execerrors(char **command_path, char **function_to_find,
				char **tabenv);

char			*get_begin(char *str, int lim);
char			*get_exp(char *str);
char			*get_value(char *str);
char			*get_end(char *str);
int				get_nbr_dollar(char *shell_command);
int				set_begin(char *shell_command, char **tmp_var, int i);
int				get_middle_token(char *shell_command, char **tmp_var, int i);
int				translate_expansion(char **keeper, t_list **tmp,
				char ***tmp_var);
char			**dollar_var(char **shell_command, t_list *current_env_list);

char			**ft_recreate_env_tab(t_list *current_env_list);
char			**ft_create_env_tab(char **shell_command);

int				oldpwd_settings(t_list *current_env_list);
int				change_pwd(t_list *current_env_list);
int				set_oldpwd(t_list *current_env_list);
char			*reach_home(t_list *current, int flag);
int				cd_hyphen(int flag);

int				ft_echo(t_list *current_env_list, char **shell_command);
int				ft_cd(t_list *current_env_list, char **shell_command);
int				ft_env(t_list *current_env_list, char **shell_command);
int				ft_setenv(t_list *current_env_list, char **shell_command);
int				setvar(t_list *current_env_list, char *shell_command);
int				ft_unsetenv(t_list *current_env_list, char **shell_command);
int				ft_exit(t_list *current_env_list, char **shell_command);

void			ft_free_tabs(char **path_to_open, char **function_to_find,
				char **tabenv);

#endif
