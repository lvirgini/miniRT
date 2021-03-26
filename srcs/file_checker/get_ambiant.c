/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambiant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:16:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/26 16:42:06 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Recuperation de la resolution a partir de la ligne R du fichier.rt
**  tab 0		tab 1 		tab 2
**	"R"			 x			 y
**	"R"			"1920"		"1080"
*/

int			get_resolution(t_app *app, char **tab)
{
	static int	get_resolution = 0;

	if (get_resolution == 1)
		return (file_error("RESOLUTION", ERR_DEF_TWICE));
	if (tab_len(tab) != 3)
		return (file_error("RESOLUTION", ERR_BAD_VALUE));
	app->size = create_vec2(ft_atoi(tab[1]), ft_atoi(tab[2]));
	if (app->size.x <= 0 || app->size.y <= 0)
		return (file_error("RESOLUTION", ERR_BAD_VALUE));
	get_resolution = 1;
	return (0);
}

/*
** Recuperation de la lumiere ambiante a partir de la ligne A du fichier.rt
**  tab 0		tab 1 		tab 2
**	"A"			ratio		color
**				[0:1]		[0:255]
**	"A"			"0.2"		"255,255,255"
*/

int			get_ambiant_ligth(t_app *app, char **tab)
{
	t_color		ambiant_color;
	double		ratio;

	if (tab_len(tab) != 3
	|| (ratio = ft_atof(tab[1])) > 1.0
	|| ratio < 0.0
	|| get_color_from_line(&ambiant_color, tab[2]))
		return (file_error("AMBIANT LIGHT", ERR_BAD_VALUE));
	if (!(app->scene->light_ambiant = malloc_light(create_vec3(0, 0, 0),
	ratio, ambiant_color)))
		return (file_error("AMBIANT LIGHT", ERR_MALLOC));
	return (0);
}

/*
** Recuperation d'une lumiere a partir de la ligne l du fichier.rt
**  tab 0		tab 1 		tab 2		tab 3
**	"l"			coord		ratio		color
**							[0:1]		[0:255]
**	"l"			"-40,0,30"	"0.2"		"255,255,255"
*/

int			get_light(t_app *app, char **tab)
{
	t_color		light_color;
	double		ratio;
	t_vec3		pos;
	t_light		*light;

	if (tab_len(tab) < 4
	|| (ratio = ft_atof(tab[2])) > 1.0
	|| ratio < 0.0
	|| get_color_from_line(&light_color, tab[3])
	|| get_coord_from_line(&pos, tab[1]))
		return (file_error("LIGHT", ERR_BAD_VALUE));
	if (!(light = malloc_light(pos, ratio, light_color)))
		return (file_error("LIGHT", ERR_MALLOC));
	light->next = app->scene->light;
	app->scene->light = light;
	app->scene->total_intens += light->ratio;
	return (0);
}

/*
** put on list camera, first in first out
*/

static void	put_camera(t_scene *scene, t_camera *to_add)
{
	t_camera	*tmp;

	if (!scene->cam)
		scene->cam = to_add;
	else
	{
		tmp = scene->cam;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = to_add;
	}
}

/*
** Recuperation d'une camera a partir de la ligne c du fichier.rt
**  tab 0		tab 1 		tab 2		tab 3
**	"c"			pos 		orient		fov
**	"c"						[-1:1]	 	[0:180]
*/

int			get_camera(t_app *app, char **tab)
{
	t_vec3		pos;
	t_vec3		orient;
	double		fov;
	t_camera	*cam;

	if (tab_len(tab) < 4
	|| get_coord_from_line(&pos, tab[1])
	|| get_coord_from_line(&orient, tab[2])
	|| check_in_range(orient, -1.0, 1.0)
	|| (fov = ft_atof(tab[3])) <= 0 || fov > 180)
		return (file_error("CAMERA", ERR_BAD_VALUE));
	if (!(cam = malloc_camera(fov, pos, orient)))
		return (file_error("CAMERA", ERR_MALLOC));
	put_camera(app->scene, cam);
	app->scene->nb_cam++;
	return (0);
}
