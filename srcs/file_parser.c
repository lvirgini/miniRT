/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:14:56 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/01 17:32:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		read_file(char *str)
{
	int 	fd_file;
	int		num_f;
	char	*line;
	t_func 	*f;

	f = set_functions(f);
	if ((fd_file = open(str, O_RDONLY)) == -1)
		return(file_error(3));
	while (get_next_line(fd_file, &line) > 0)
	{
		if (line && line[0] != '\0' && ((num_f = index_set(line)) != -1))
		{
			f[num_f](line);
		}
		free(line);
	}
	close(fd_file);
	return (check_file_is_complete());
}

/*
**  recherche l'index de fonctions correspondant a set_functions()
*/

int		index_set(char *s)
{
	char *set = "RAlcpct";

	if(s[0] == 's')
	{
		if (s[1] == 'p')
			return (7);
		if (s[1] == 'q')
			return (8);
		else
			return (-1);
	}
	return (ft_strchr_i(set, s[0])); 
}

/*
**	initialise le tableau de fonctions en correlation avec index_set();
**		0	1	2	3	4	5	6	7	8
** 		R	A	l	c	p	c	t	sp	sq
*/


t_func		*set_functions(t_func *f) 
{	
	f[0] = &create_resolution;
	f[1] = &create_ambiant_ligth;
	f[2] = &create_light;
	f[3] = &create_camera;
	f[4] = &create_plane;
	f[5] = &create_cyl;
	f[6] = &create_triangle;
	f[7] = &create_sphere;
	f[8] = &create_square;


		return(f);
}

/*
** verifie s'il ne manque pas un parametre obligatoire pour le scene.
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
