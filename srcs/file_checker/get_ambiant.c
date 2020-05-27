/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambiant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:16:39 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/04 14:34:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Recuperation de la resolution a partir de la ligne R du fichier.rt
*/

int		get_resolution(char *str)
{
	/*int		i;

	if ((g_app->size.x) || (g_app->size.y))
		return (file_error("RESOLUTION", 1));
	if (!(i = line_get_int(str, &(g_app->size.x)))
		|| !(i = line_get_int(str + i, &(g_app->size.y))) 
		|| g_app->size.x <= 0 || g_app->size.y<= 0) 
		return (file_error("RESOLUTION", 2));
	g_app->size.x = g_app->size.x > RES_X_MAX ? RES_X_MAX : g_app->size.x ;
	g_app->size.y= g_app->size.y> RES_Y_MAX ? RES_Y_MAX : g_app->size.y;
*/
		if (str)
		return (0);
	return (0);
}


int		get_ambiant_ligth(char *str)
{/*
	int 		i;
	t_ambiant 	*l_ambiant;

	if (g_app->scene->ambiant)
		return (file_error("AMBIANT LIGHT", 1));
	if (!(i = line_get_float(str, &(l_ambiant->ratio)))
		|| l_ambiant->ratio < 0 || l_ambiant->ratio > 1
		|| !(i = line_get_t_color(str + i, &(l_ambiant->color))))
		return (file_error("AMBIANT LIGHT", 2));
	g_app->scene->ambiant = l_ambiant;*/
		if (str)
		return (0);
	return (0);
}


int		get_light(char *str)
{
	if (str)
		return (0);
	return (0);
}

int		get_camera(char *str)
{
	if (str)
		return (0);
	return (0);
}
