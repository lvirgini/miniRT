/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:16:39 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/28 13:22:19 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Recuperation d'une sphere a partir de la ligne sp du fichier.rt
**  tab 0		tab 1 		tab 2		tab 3
**	"sp"		pos			radius		color
**	"sp"		"-40,0,30"	"20"		"255,255,255"			//	EXAMPLE //
*/

int		get_sphere(char **tab)
{
	t_obj		*obj;
	t_sphere	*sphere;
	t_vec3		pos;
	double		radius;
	t_color		color;

	if (tab_len(tab) < 4 || (radius = ft_atof(tab[2]) / 2) < 0.0
		|| get_coord_from_line(&pos, tab[1])
		|| get_color_from_line(&color, tab[3]))
		file_error("SPHERE", 2);
	if (!(sphere = malloc_sphere(pos, radius, color, 0)))
		minirt_exit_on_error(1);
	if (!(g_app->scene->objs))
	{
		if (!(g_app->scene->objs = malloc_object(SPHERE, sphere)))
			minirt_exit_on_error(1);
	}
	else
	{
		obj = find_last_obj(g_app->scene->objs);
		if (!(obj->next = malloc_object(SPHERE, sphere)))
			minirt_exit_on_error(1);
	}
	return (0);
}

/*
** Recuperation d'un plan a partir de la ligne pl du fichier.rt
**  tab 0		tab 1 		tab 2		tab 3
**	"pl"		pos			orient		color
**	"pl"		"-40,0,30"	"0,1.0,0"	"255,255,255"			//	EXAMPLE //
*/

int		get_plane(char **tab)
{
	t_vec3		pos;
	t_vec3		orient;
	t_color		color;
	t_plane		*plane;
	t_obj		*obj;

	if ((tab_len(tab) < 4
		|| get_coord_from_line(&pos, tab[1])
		|| get_coord_from_line(&orient, tab[2])
		|| get_color_from_line(&color, tab[3])))
		file_error("PLAN", 2);
	if (!(plane = malloc_plane(pos, orient, color, 0)))
		minirt_exit_on_error(1);
	if (!(g_app->scene->objs))
	{
		if (!(g_app->scene->objs = malloc_object(PLANE, plane)))
			minirt_exit_on_error(1);
	}
	else
	{
		obj = find_last_obj(g_app->scene->objs);
		if (!(obj->next = malloc_object(SPHERE, plane)))
			minirt_exit_on_error(1);
	}
	return (0);
}

/*
** Recuperation d'un square a partir de la ligne sq du fichier.rt
**  tab 0		tab 1 		tab 2		tab3	tab 4
**	"sq"		pos			orient		hauteur	color
**	"sq"		"-40,0,30"	"0,1.0,0"	"26.5"	"255,255,255" //	EXAMPLE //
*/

int		get_square(char **tab)
{
	t_vec3		pos_orient[2];
	double		hight;
	t_color		color;
	t_square	*square;
	t_obj		*obj;

	if ((tab_len(tab) < 5 || (hight = ft_atof(tab[3])) < 0.0
		|| get_coord_from_line(pos_orient, tab[1])
		|| get_coord_from_line(pos_orient + 1, tab[2])
		|| get_color_from_line(&color, tab[4])))
		file_error("SQUARE", 2);
	if (!(square = malloc_square(pos_orient, hight, color, 0)))
		minirt_exit_on_error(1);
	if (!(g_app->scene->objs))
	{
		if (!(g_app->scene->objs = malloc_object(SQUARE, square)))
			minirt_exit_on_error(1);
	}
	else
	{
		obj = find_last_obj(g_app->scene->objs);
		if (!(obj->next = malloc_object(SQUARE, square)))
			minirt_exit_on_error(1);
	}
	return (0);
}

/*
** Recuperation d'un square a partir de la ligne sq du fichier.rt
**  tab 0	tab 1 		tab 2		tab3		tab4	tab 5
**	"sq"	pos			orient		diametre	hauteur	color
**	"sq"	"-40,0,30"	"0,1.0,0"	"26.5"		"12.2"	"255,255,255"
*/

int		get_cyl(char **tab)
{
	t_vec3		pos_orient[2];
	double		radius_hight[2];
	t_color		color;
	t_cyl		*cyl;
	t_obj		*obj;

	if ((tab_len(tab) < 6 || (radius_hight[0] = ft_atof(tab[3]) / 2) < 0.0
		|| (radius_hight[1] = ft_atof(tab[4])) < 0.0 || get_coord_from_line(
		pos_orient, tab[1]) || get_coord_from_line(pos_orient + 1, tab[2])
		|| get_color_from_line(&color, tab[5])))
		file_error("CYLINDRE", 2);
	if (!(cyl = malloc_cyl(pos_orient, radius_hight, color, 0)))
		minirt_exit_on_error(1);
	if (!(g_app->scene->objs))
	{
		if (!(g_app->scene->objs = malloc_object(CYLINDRE, cyl)))
			minirt_exit_on_error(1);
	}
	else
	{
		obj = find_last_obj(g_app->scene->objs);
		if (!(obj->next = malloc_object(CYLINDRE, cyl)))
			minirt_exit_on_error(1);
	}
	return (0);
}

/*
** Recuperation d'un square a partir de la ligne sq du fichier.rt
**  tab 0	tab 1 		tab 2		tab 3		tab 4
**	"tr"	pos1		pos2		pos3		color
**	"tr"	"-40,0,30"	"0,1.0,0"	"20,10,10"	"255,255,255"
*/

int		get_triangle(char **tab)
{
	t_triangle	*triangle;
	t_vec3		pos[3];
	t_color		color;
	t_obj		*obj;

	if ((tab_len(tab) < 5
		|| get_coord_from_line(pos, tab[1])
		|| get_coord_from_line(pos + 1, tab[2])
		|| get_coord_from_line(pos + 2, tab[3])
		|| get_color_from_line(&color, tab[4])))
		file_error("TRIANGLE", 2);
	if (!(triangle = malloc_triangle(pos, color, 0)))
		minirt_exit_on_error(1);
	if (!(g_app->scene->objs))
	{
		if (!(g_app->scene->objs = malloc_object(TRIANGLE, triangle)))
			minirt_exit_on_error(1);
	}
	else
	{
		obj = find_last_obj(g_app->scene->objs);
		if (!(obj->next = malloc_object(TRIANGLE, triangle)))
			minirt_exit_on_error(1);
	}
	return (0);
}
