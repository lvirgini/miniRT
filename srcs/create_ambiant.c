/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ambiant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:16:39 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/04 15:21:08 by lvirgini         ###   ########.fr       */
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
	if (str)
		;
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
