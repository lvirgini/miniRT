/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:36:18 by lvirgini          #+#    #+#             */
/*   Updated: 2020/09/21 11:35:24 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Mise en place du raytracing
**	- clear_application = couleur de fond
** 	- parcours l'image pour modifier la couleur de chaque pixel s'il y a intersection
**	- affiche l'image resultante sur la fenetre.
*/

int		raytracing_test(void *param) // param a determier
{
	(void)param;

	clear_application(create_color(25, 25, 25, 255)); // a determiner
	
	browse_image_for_intersection(g_app->scene->cam, g_app->size.x, g_app->size.y);
	printf("OK\n");
	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->img->img_ptr, 0, 0);
	printf("OK\n");
	return (0);
}
