/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ambiant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:16:39 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/01 19:03:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int create_resolution(char *str)
{
	if ((g_app->x) || (g_app->y))
	{
		file_error(1); // a modif erreur
		return (-1);
	}
	

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
