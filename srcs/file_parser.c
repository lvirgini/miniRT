/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:14:56 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/01 13:52:37 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		read_file(char *str)
{
	int 	fd_file;
	char	*line;
	int		nb_tab;
	t_func 	*f;
	

	f = set_functions();
	if ((fd_file = open(str, O_RDONLY)) == -1)
		return(file_error(3));
	while (get_next_line(fd_file, &line) > 0)
	{
		if (line && line[0] != '\0')
		{
			
			f[line[0]](line); // pas line 0 mais son eauivalence
		
		}
		free(line);
	}
	close(fd_file);
	return (check_file_is_complete());
}

/*
**
*/


//	initialise le tableau de fonctions

t_func		*set_functions(void) 
{
	static int 	(*f[9])(char *) = {
		&create_resolution,
		&create_ambiant_ligth,
		&create_light,
		&create_camera,
		&create_sphere,
		&create_plane,
		&create_square,
		&create_cyl,
		&create_triangle, 
		};

		return(f);
}

/*
** verifie s'il ne manque pas un parametre essentiel
*/

int	check_file_is_complete(void)
{
	return (0);
}











/* foret de if
int	line_parser(char *line)
{
	
		
	if (line[0] == 'R')
		return(line_resolution(line));
	else if (line[0] == 'A')
		return(line_ambiant_light(line));
	else if (line[0] == 'l')
		return (line_light(line));
	else if (line[0] == 'c')
		return(line_ambiant_light(line));
	else if (line[0] == '')
		return (line_light(line));
	
	return (0);
}*/
