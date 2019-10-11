/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:23:04 by baavril           #+#    #+#             */
/*   Updated: 2019/10/07 19:23:05 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 5

typedef struct	s_list_fd
{
	struct s_list_fd	*next;
	char				*rd;
	int					fd;
}				t_list_fd;

int				get_next_line(const int fd, char **line);

#endif
