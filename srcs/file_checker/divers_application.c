/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers_application.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:02:24 by lvirgini          #+#    #+#             */
/*   Updated: 2020/04/30 14:28:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Remplis entierement la fenetre de la couleur donnee en parametre.
*/

void clear_application(t_color color)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < g_app->size.x)
	{
		j = 0;
		while (j < g_app->size.y)
		{
			put_pixel(g_app->img, i, j, color);
			j++;
		}
		i++;
	}
}