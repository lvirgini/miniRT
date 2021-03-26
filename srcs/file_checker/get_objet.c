/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:16:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/26 11:07:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Recuperation d'une sphere a partir de la ligne sp du fichier.rt
**  tab 0		tab 1 		tab 2		tab 3
**	"sp"		pos			radius		color [0:255]
**	"sp"		"-40,0,30"	"20"		"255,255,255"		//	EXAMPLE //
*/

int		get_sphere(t_app *app, char **tab)
{
	t_sphere	*sphere;
	t_vec3		pos;
	double		radius;
	t_color		color;
	int			texture;

	if (tab_len(tab) < 4
	|| (radius = ft_atof(tab[2]) / 2) <= 0.0
	|| get_coord_from_line(&pos, tab[1])
	|| get_color_from_line(&color, tab[3]))
		return (file_error(app, "SPHERE", ERR_BAD_VALUE));
	texture = (tab_len(tab) == 5 && tab[4]) ? get_texture(tab[4]) : 0;
	if (!(sphere = malloc_sphere(pos, radius, color, texture)))
		return (file_error(app, "SPHERE", ERR_MALLOC));
	return (save_obj_in_scene(app->scene, SPHERE, sphere));
}

/*
** Recuperation d'un plan a partir de la ligne pl du fichier.rt
**  tab 0		tab 1 		tab 2		tab 3
**	"pl"		pos			orient		color
**							[-1:1]		[0:255]
**	"pl"		"-40,0,30"	"0,1.0,0"	"255,255,255"			//	EXAMPLE //
*/

int		get_plane(t_app *app, char **tab)
{
	t_vec3		pos;
	t_vec3		orient;
	t_color		color;
	t_plane		*plane;
	int			texture;

	texture = 0;
	if (tab_len(tab) < 4
	|| get_coord_from_line(&pos, tab[1])
	|| get_coord_from_line(&orient, tab[2])
	|| check_in_range(orient, -1.0, 1.0)
	|| get_color_from_line(&color, tab[3]))
		return (file_error(app, "PLANE", ERR_BAD_VALUE));
	texture = (tab_len(tab) == 5 && tab[4]) ? get_texture(tab[4]) : 0;
	if (!(plane = malloc_plane(pos, orient, color, texture)))
		return (file_error(app, "PLANE", ERR_MALLOC));
	return (save_obj_in_scene(app->scene, PLANE, plane));
}

/*
** Recuperation d'un square a partir de la ligne sq du fichier.rt
**  tab 0		tab 1 		tab 2		tab3	tab 4
**	"sq"		pos			orient		hauteur	color
**							[-1:1]				[0:255]
**	"sq"		"-40,0,30"	"0,1.0,0"	"26.5"	"255,255,255" //	EXAMPLE //
*/

int		get_square(t_app *app, char **tab)
{
	t_vec3		pos_orient[2];
	double		hight;
	t_color		color;
	t_square	*square;
	int			texture;

	if (tab_len(tab) < 5
	|| (hight = ft_atof(tab[3])) <= 0.0
	|| get_coord_from_line(pos_orient, tab[1])
	|| get_coord_from_line(pos_orient + 1, tab[2])
	|| check_in_range(pos_orient[1], -1.0, 1.0)
	|| get_color_from_line(&color, tab[4]))
		return (file_error(app, "SQUARE", ERR_BAD_VALUE));
	texture = (tab_len(tab) == 6 && tab[5]) ? get_texture(tab[5]) : 0;
	if (!(square = malloc_square(pos_orient, hight, color, texture)))
		return (file_error(app, "SQUARE", ERR_MALLOC));
	return (save_obj_in_scene(app->scene, SQUARE, square));
}

/*
** Recuperation d'un square a partir de la ligne sq du fichier.rt
**  tab 0	tab 1 		tab 2		tab3		tab4	tab 5
**	"sq"	pos			orient		diametre	hauteur	color
**						[-1:1]							[0:255]
**	"sq"	"-40,0,30"	"0,1.0,0"	"26.5"		"12.2"	"255,255,255"
*/

int		get_cyl(t_app *app, char **tab)
{
	t_vec3		pos_orient[2];
	double		radius_hight[2];
	t_color		color;
	t_cyl		*cyl;
	int			texture;

	if (tab_len(tab) < 6
	|| (radius_hight[0] = ft_atof(tab[3]) / 2) < 0.0
	|| (radius_hight[1] = ft_atof(tab[4])) < 0.0
	|| get_coord_from_line(pos_orient, tab[1])
	|| get_coord_from_line(pos_orient + 1, tab[2])
	|| check_in_range(pos_orient[1], -1.0, 1.0)
	|| get_color_from_line(&color, tab[5]))
		return (file_error(app, "CYLINDER", ERR_BAD_VALUE));
	texture = (tab_len(tab) > 6 && tab[6]) ? get_texture(tab[6]) : 0;
	if (!(cyl = malloc_cyl(pos_orient, radius_hight, color, texture)))
		return (file_error(app, "CYLINDER", ERR_MALLOC));
	if (tab_len(tab) == 8 && tab[7] && ft_strcmp(tab[7], "caps") == 0)
		malloc_caps_cylinder(cyl, app);
	return (save_obj_in_scene(app->scene, CYLINDER, cyl));
}

/*
** Recuperation d'un square a partir de la ligne sq du fichier.rt
**  tab 0	tab 1 		tab 2		tab 3		tab 4
**	"tr"	pos1		pos2		pos3		color
**	"tr"	"-40,0,30"	"0,1.0,0"	"20,10,10"	"255,255,255"
*/

int		get_triangle(t_app *app, char **tab)
{
	t_triangle	*triangle;
	t_vec3		pos[3];
	t_color		color;
	int			texture;

	if (tab_len(tab) < 5
	|| get_coord_from_line(pos, tab[1])
	|| get_coord_from_line(pos + 1, tab[2])
	|| get_coord_from_line(pos + 2, tab[3])
	|| get_color_from_line(&color, tab[4]))
		return (file_error(app, "TRIANGLE", ERR_BAD_VALUE));
	texture = (tab_len(tab) == 6 && tab[5]) ? get_texture(tab[5]) : 0;
	if (!(triangle = malloc_triangle(pos, color, texture)))
		return (file_error(app, "TRIANGLE", ERR_MALLOC));
	return (save_obj_in_scene(app->scene, TRIANGLE, triangle));
}
