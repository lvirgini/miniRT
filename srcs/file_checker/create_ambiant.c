/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ambiant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:16:39 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/07 15:36:43 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Recuperation de la resolution a partir de la ligne R du fichier.rt
*/

int		get_resolution(char *str)
{
	int		i;

	if ((g_app->x) || (g_app->y))
		return (file_error("RESOLUTION", 1));
	if (!(i = line_get_int(str, &(g_app->x)))
		|| !(i = line_get_int(str + i, &(g_app->y))) 
		|| g_app->x < 0 || g_app->y < 0) 
		return (file_error("RESOLUTION", 2));
	return (0);
}

int		get_ambiant_ligth(char *str)
{
	int 		i;
	t_ambiant 	*l_ambiant;

	if (g_app->scene->ambiant)
		return (file_error("AMBIANT LIGHT", 1));
	if (!(i = line_get_float(str, &(l_ambiant->ratio)))
		|| l_ambiant->ratio < 0 || l_ambiant->ratio > 1
		|| !(i = line_get_t_color(str + i, &(l_ambiant->color))))
		return (file_error("AMBIANT LIGHT", 2));
	g_app->scene->ambiant = l_ambiant;
	return (0);
}

int		get_light(char *str)
{
	if (str)
		;
	return (0);
}

int		get_camera(char *str)
{
	if (str)
		;
	return (0);
}
