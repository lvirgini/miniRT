/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:14:56 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/07 23:17:08 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t			tab_len(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void			free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

/*
**  recherche l'index de fonctions correspondant a set_functions_get()
**		0	1	2	3	4	5	6	7	8
** 		R	A	l	c	pl	tr	cy	sp	sq
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
		file_error("AMBIANT LIGHT", 1);
	else if (i == 8 && r_done++ == 1)
		file_error("RESOLUTION", 1);
	else if (i == 9)
		file_error(s, 4);
	return (i);
}

/*
**	initialise le tableau de fonctions en correlation avec index_set();
**		0	1	2	3	4	5	6	7	8
** 		R	A	l	c	pl	tr	cy	sp	sq
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
}

/*
** Get next line du fichier.rt et recuperation de chaque parametre de la scene.
*/

// ATTENTION REFAIRE GNL car ne lit pas la derniere ligne, pb lors du compressage pour la maj libft
int				read_file(char *str, t_app *app)
{
	t_func	f[8];
	int		fd_file;
	int		index_ft;
	char	*line;
	char	**tab;

	if ((fd_file = open(str, O_RDONLY)) == -1)
		return (file_error("file cannot be read by the (read) function", 0));
	set_functions_get(f);
	while (get_next_line(fd_file, &line) > 0)
	{
		if (line && line[0] != '\0')
		{
			tab = ft_split_set(line, " \r\t\v\f");
			index_ft = index_set(tab[0]);
			if ((index_ft == 8 && (get_resolution(tab, &(app)->size) != 0))
			|| (index_ft != 8 && (f[index_ft](tab) != 0)))
			{
				free_tab(tab);
				free(line);
				close(fd_file);
				return (-1);
			}
			free_tab(tab);
		}
		free(line);
	}
	close(fd_file);
	return (0);
}
