/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:14:56 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/29 17:49:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		read_file(char *str)
{
	int 	fd_file;
	char	*line;

	if ((fd_file = open(str, O_RDONLY)) == -1)
		return(file_error(3));
	while (get_next_line(fd_file, &line) > 0)
	{
		if (line_parser(line) == -1)
			{
				free(line);
				return (-1);
			}
		free(line);
	}
	//file_complete();
	close(fd_file);
	return (0);
}

/*
**
*/

int	line_parser(char *line)
{
	if (!line || line[0] == '\0')
		return (0);
		
/*	if (line[0] == 'R')
		return(line_resolution(line));
	else if (line[0] == 'A')
		return(line_ambiant_light(line));
	else if (line[0] == 'l')
		return (line_light(line));
	else if (line[0] == 'c')
		return(line_ambiant_light(line));
	else if (line[0] == '')
		return (line_light(line));

*/	
	return (0);
}