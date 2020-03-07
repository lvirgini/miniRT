/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:14:56 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/07 15:14:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**  recherche l'index de fonctions correspondant a set_functions_get()
*/

static int		index_set(char *s)
{
	char	*set;

	set = "RAlcpct";
	if (!s)
		return (-1);
	if (s[0] == 's')
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

static void		set_functions_get(t_func *f)
{
	f[0] = &get_resolution;
	f[1] = &get_ambiant_ligth;
	f[2] = &get_light;
	f[3] = &get_camera;
	f[4] = &get_plane;
	f[5] = &get_cyl;
	f[6] = &get_triangle;
	f[7] = &get_sphere;
	f[8] = &get_square;
}

/*
** verifie s'il ne manque pas un parametre obligatoire pour le scene.
*/

static int			check_file_is_complete(void)
{
	return (0);
}

/*
** Get next line du fichier.rt et recuperation de chaque parametre de la scene.
*/

int		read_file(char *str)
{
	int		fd_file;
	int		num_f;
	char	*line;
	t_func	f[9];

	set_functions_get(f);
	if ((fd_file = open(str, O_RDONLY)) == -1)
		return (file_error("file cannot be read by the (read) function", 0));
	while (get_next_line(fd_file, &line) > 0)
	{
		if (line && line[0] != '\0' && ((num_f = index_set(line)) != -1))
		{
			if (f[num_f](line) == -1)
			{
				free(line);
				return (-1);
			}
		}
		free(line);
	}
	close(fd_file);
	return (check_file_is_complete());
}
