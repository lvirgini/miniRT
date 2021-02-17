/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers_application.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:02:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/17 16:51:51 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Remplis entierement la fenetre de la couleur donnee en parametre.
*/

void	clear_application(t_color color, t_app *app)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < app->size.x)
	{
		j = 0;
		while (j < app->size.y)
		{
			put_pixel(app->img, i, j, color);
			j++;
		}
		i++;
	}
}
