/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ambiant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:16:39 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/04 17:31:14 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Recuperation de la resolution a partir de la ligne R du fichier.rt
*/

int		create_resolution(char *str)
{
	int		i;

	if ((g_app->x) || (g_app->y))
		return (file_error("RESOLUTION : definit deux fois dans le fichier"));
	if ((i = line_recup_number_int(str, &(g_app->x))) < 0
		|| (i = line_recup_number_int(str + i, &(g_app->y))) < 0)
		return (file_error("RESOLUTION : tailles mal definies"));
	if (g_app->x == -1 || g_app->y == -1)
		return (file_error("RESOLUTION : resolution impossible"));
	return (0);
}

int		create_ambiant_ligth(char *str)
{
	int 		i;
	t_ambiant 	*l_ambiant;

	i = line_recup_number_float(str, &(l_ambiant->ratio));
	if (i < 0 || l_ambiant->ratio < 0 || l_ambiant->ratio > 1)
		return (file_error("AMBIANT LIGHT : le ratio doit etre compris entre 0 et 1"));
	i = line_recup_t_color(str + i, &(l_ambiant->color));
	if (i < 0)
		return (file_error("AMBIANT LIGHT : les couleurs doivent etre comprise entre 0 et 255"));
	g_app->scene->ambiant = l_ambiant;
	return (0);
}

int		create_light(char *str)
{
	if (str)
		;
	return (0);
}

int		create_camera(char *str)
{
	if (str)
		;
	return (0);
}
