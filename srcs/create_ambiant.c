/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ambiant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:16:39 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/03 15:01:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Recuperation de la resolution a partir de la ligne R du fichier.rt
*/

int create_resolution(char *str)
{
	if ((g_app->x) || (g_app->y))
		return (file_error("RESOLUTION : definit deux fois dans le fichier"));
	if(line_recup_number_int(str, &(g_app->x)) 
		|| line_recup_number_int(str, &(g_app->y)))
		return (file_error("RESOLUTION : pas de tailles definies dans le fichier"));
	if (g_app->x == -1 || g_app->y == -1)
		return (file_error("RESOLUTION : resolution impossible"));
	return(0);
}

int create_ambiant_ligth(char *str)
{
	return(0);
}

int create_light(char *str)
{
	return(0);
}

int create_camera(char *str)
{
	return(0);
}
