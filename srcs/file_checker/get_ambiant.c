/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambiant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:16:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/13 13:52:58 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Recuperation de la resolution a partir de la ligne R du fichier.rt
**  tab 0		tab 1 		tab 2
**	"R"			 x			 y
**	"R"			"1920"		"1080"			//	EXAMPLE //
*/

int		get_resolution(t_app *app, char **tab)
{
	static int	get_resolution = 0;

	if (get_resolution == 1)
		return (file_error(app, "RESOLUTION", ERR_DEF_TWICE));
	if (tab_len(tab) != 3)
		return (file_error(app, "RESOLUTION", ERR_BAD_VALUE));
	app->size = create_vec2(ft_atoi(tab[1]), ft_atoi(tab[2]));
	if (app->size.x <= 0 || app->size.y <= 0)
		return (file_error(app, "RESOLUTION", ERR_BAD_VALUE));
	app->size.x = app->size.x > RES_X_MAX ? RES_X_MAX : app->size.x;
	app->size.y = app->size.y > RES_Y_MAX ? RES_Y_MAX : app->size.y;
	get_resolution = 1;
	return (0);
}

/*
** Recuperation de la lumiere ambiante a partir de la ligne A du fichier.rt
**  tab 0		tab 1 		tab 2
**	"A"			ratio		color
**	"A"			"0.2"		"255,255,255"			//	EXAMPLE //
*/

int		get_ambiant_ligth(t_app *app, char **tab)
{
	t_color		ambiant_color;
	double		ratio;

	if (tab_len(tab) != 3
	|| (ratio = ft_atof(tab[1])) > 1.0
	|| ratio < 0.0
	|| get_color_from_line(&ambiant_color, tab[2]))
		return (file_error(app, "AMBIANT LIGHT", ERR_BAD_VALUE));
	if (!(app->scene->light_ambiant = malloc_light(create_vec3(0, 0, 0),
	ratio, ambiant_color)))
		return (file_error(app, "AMBIANT LIGHT", ERR_MALLOC));
	return (0);
}

/*
** Recuperation d'une lumiere a partir de la ligne l du fichier.rt
**  tab 0		tab 1 		tab 2		tab 3
**	"l"			coord		ratio		color
**	"l"			"-40,0,30"	"0.2"		"255,255,255"			//	EXAMPLE //
*/

int		get_light(t_app *app, char **tab)
{
	t_color		light_color;
	double		ratio;
	t_vec3		pos;

	if (tab_len(tab) < 4
	|| (ratio = ft_atof(tab[2])) > 1
	|| ratio < 0
	|| get_color_from_line(&light_color, tab[3])
	|| get_coord_from_line(&pos, tab[1]))
		return (file_error(app, "LIGHT", ERR_BAD_VALUE));
	if (!(app->scene->light = malloc_light(pos, ratio, light_color)))
		return (file_error(app, "LIGHT", ERR_MALLOC));
	return (0);
	// t_light tmp; voir pour plusieurs lights
}

/*
** Recuperation d'une camera a partir de la ligne c du fichier.rt
**  tab 0		tab 1 		tab 2		tab 3
**	"c"			pos			orient		fov
**	"c"			"-40,0,30"	"-40,0,30"	 0 < 180		//	EXAMPLE //
*/

int		get_camera(t_app *app, char **tab)
{
	t_vec3		pos;
	t_vec3		orient;
	double		fov;

	if (tab_len(tab) < 4
	|| get_coord_from_line(&pos, tab[1])
	|| get_coord_from_line(&orient, tab[2])
	|| (fov = ft_atof(tab[3])) < 0 || fov > 180)
		return (file_error(app, "CAMERA", ERR_BAD_VALUE));
	if (!(app->scene->cam = malloc_camera(fov, pos, orient)))
		return (file_error(app, "CAMERA", ERR_MALLOC));
	return (0);
}
