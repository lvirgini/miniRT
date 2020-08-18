/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambiant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:16:39 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/18 17:34:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


/*
** Recuperation de la resolution a partir de la ligne R du fichier.rt
**  tab 0		tab 1 		tab 2
**	"R"			 x			 y
**	"R"			"1920"		"1080"			//	EXAMPLE //
*/

int		get_resolution(char **tab)
{
	static int	get_resolution = 0;

	if (get_resolution == 1)
	if (tab_len(tab) < 3)
		file_error("RESOLUTION", 2);
	g_app->size = create_vec2(ft_atoi(tab[1]), ft_atoi(tab[2]));
	if (g_app->size.x <= 0 || g_app->size.x > RES_X_MAX
		|| g_app->size.y <= 0 || g_app->size.y > RES_Y_MAX)
		file_error("RESOLUTION", 2);
	return (0);
}

/*
** Recuperation de la lumiere ambiante a partir de la ligne A du fichier.rt
**  tab 0		tab 1 		tab 2
**	"A"			ratio		color
**	"A"			"0.2"		"255,255,255"			//	EXAMPLE //
*/

int		get_ambiant_ligth(char **tab)
{
	t_color		ambiant_color;
	double 		ratio;

	if (tab_len(tab) != 3 || (ratio = ft_atof(tab[1])) > 1 || ratio < 0
		|| get_color_from_line(&ambiant_color, tab[2]))
		file_error("AMBIANT LIGHT", 2);
	g_app->scene->light_ambiant = malloc_light(create_vec3(0, 0, 0), 
								ratio,
								ambiant_color);
	return (0);
}

/*
** Recuperation d'une lumiere a partir de la ligne l du fichier.rt
**  tab 0		tab 1 		tab 2		tab 3
**	"l"			coord		ratio		color
**	"l"			"-40,0,30"	"0.2"		"255,255,255"			//	EXAMPLE //
*/

int		get_light(char **tab)
{	
	t_color		light_color;
	double 		ratio;
	t_vec3		pos;

	if (tab_len(tab) < 4 
		|| (ratio = ft_atof(tab[2])) > 1 || ratio < 0
		|| get_color_from_line(&light_color, tab[3])
		|| get_coord_from_line(&pos, tab[1]))
		file_error("LIGHT", 2);
	g_app->scene->light = malloc_light(pos, ratio, light_color); /// voir pour plusieurs lights 
	return (0);
}

/*
** Recuperation d'une camera a partir de la ligne c du fichier.rt
**  tab 0		tab 1 		tab 2		tab 3
**	"c"			pos			orient		fov
**	"c"			"-40,0,30"	"-40,0,30"	 0 < 180		//	EXAMPLE //
*/

int		get_camera(char **tab)
{
	t_vec3		pos;
	t_vec3		orient;
	double		fov;

	if (tab_len(tab) < 4
		|| get_coord_from_line(&pos, tab[1])
		|| get_coord_from_line(&orient, tab[2])
		|| (fov = ft_atof(tab[3])) < 0 || fov > 180)
		file_error("CAMERA", 2);
	g_app->scene->cam = malloc_camera(fov, pos, orient);
	return (0);
}
