/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 16:29:41 by lvirgini          #+#    #+#             */
/*   Updated: 2020/07/02 15:22:47 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copie tout ou une partie de buf dans line.
*/

static int	copy_buf_in_line(char **line, char *buf, int end_of_line, int len)
{
	if (end_of_line == -1 && len <= 0)
		len = ft_strlen(buf);
	else
		len = end_of_line;
	if (buf[0] == '\n')
		len = 0;
	*line = ft_strjoin_gnl(*line, buf, len);
	if (len == BUFFER_SIZE)
	{
		len = -1;
		buf[0] = '\0';
	}
	buf = ft_strncpy(buf, buf + len + 1, BUFFER_SIZE);
	if (*line == NULL)
		return (-1);
	return (1);
}

/*
** Recherche l'index de la structure correspondante au fd.
*/

static int	find_t_gnl(t_gnl gnl[NB_FD], int fd)
{
	int i;

	i = 0;
	while (gnl && gnl[i].fd != 0 && gnl[i].fd != fd)
		i++;
	if (gnl[i].fd == 0)
		gnl[i].fd = fd;
	return (i);
}

/*
**  GNL :
**	- tant que (\n) n'est pas ete trouve dans le buffer, on lit le fd.
**	tout en copiant le buffer dans *line.
**	- on arrete de (read) des (\n).
**	- retourne 1 pour chaque ligne copiee.
**	- retourne 0 si EOF.
*/
int			get_next_line(int fd, char **line)
{
	static t_gnl	gnl[NB_FD];
	int				end_of_line;
	int				i;
	int				len;

	*line = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 1 || (read(fd, gnl[0].buf, 0) == -1))
		return (-1);
	i = find_t_gnl(gnl, fd);
	len = 0;
	*line = ft_strjoin_gnl(NULL, gnl[i].buf, 0);
	while ((end_of_line = ft_strchr_len(gnl[i].buf, '\n')) < 0)
	{
		if ((copy_buf_in_line(line, gnl[i].buf, end_of_line, len) != 1)
		|| ((len = read(fd, gnl[i].buf, BUFFER_SIZE)) < BUFFER_SIZE))
			return (stop_read(line, gnl[i].buf, end_of_line, len));
	}
	return (copy_buf_in_line(line, gnl[i].buf, end_of_line, len));
}
