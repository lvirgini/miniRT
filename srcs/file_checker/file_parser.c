/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:14:56 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/26 16:42:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**  recherche l'index de fonctions correspondant a set_functions_get()
**		0	1	2	3	4	5	6	7	8
** 		A	l	c	pl	tr	cy	sp	sq	R
*/

static size_t	index_set(char *s)
{
	static char	*set[9] = {"A", "l", "c", "pl", "tr", "cy", "sp", "sq", "R"};
	static char r_done = 0;
	static char a_done = 0;
	size_t		i;

	i = 0;
	while (i < 9 && ft_strcmp(set[i], s) != 0)
		i++;
	if (i == 0 && a_done++ == 1)
		return (file_error("AMBIANT LIGHT", ERR_DEF_TWICE));
	else if (i == 8 && r_done++ == 1)
		return (file_error("RESOLUTION", ERR_DEF_TWICE));
	else if (i == 9)
		return (file_error(s, ERR_NOT_TYPE));
	return (i);
}

/*
**	initialise le tableau de fonctions en correlation avec index_set();
**		0	1	2	3	4	5	6	7	8
** 		A	l	c	pl	tr	cy	sp	sq	R
*/

static void		set_functions_get(t_func *f)
{
	f[0] = &get_ambiant_ligth;
	f[1] = &get_light;
	f[2] = &get_camera;
	f[3] = &get_plane;
	f[4] = &get_triangle;
	f[5] = &get_cyl;
	f[6] = &get_sphere;
	f[7] = &get_square;
	f[8] = &get_resolution;
}

/*
** recuperation de chaque parametre de la ligne.
*/

static int		parse_line(char *line, t_app *app, t_func *f, int fd)
{
	int		index_ft;
	char	**tab;

	tab = ft_split_set(line, " \r\t\v\f");
	index_ft = index_set(tab[0]);
	if (index_ft == -1 || f[index_ft](app, tab) != 0)
	{
		free_tab(tab);
		free(line);
		close(fd);
		return (-1);
	}
	free_tab(tab);
	return (0);
}

/*
** Get next line du fichier.rt et envoie de la ligne a parse line
*/

int				read_file(char *str, t_app *app)
{
	t_func	f[8];
	int		fd;
	char	*line;
	int		ret;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (file_error(str, ERR_NOT_READ));
	set_functions_get(f);
	while ((ret = get_next_line(fd, &line)) > 0 || (ret == 0 && line[0] != 0))
	{
		if (line && line[0] != '\0' && line[0] != '#')
			if (parse_line(line, app, f, fd) == -1)
				return (-1);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
