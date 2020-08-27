/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:16:39 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/27 11:39:51 by lvirgini         ###   ########.fr       */
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
	sphere = malloc_sphere(pos, radius, color, 0);
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

int		get_plane(char **tab)
{
	if (tab)
		return (0);
	return (0);
}

int		get_square(char **tab)
{
	if (tab)
		return (0);
	return (0);
}

int		get_cyl(char **tab)
{
	if (tab)
		return (0);
	return (0);
}

int		get_triangle(char **tab)
{
	if (tab)
		return (0);
	return (0);
}
