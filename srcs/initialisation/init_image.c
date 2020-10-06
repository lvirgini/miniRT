/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:56:23 by lvirgini          #+#    #+#             */
/*   Updated: 2020/09/28 11:45:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion des t_image : creation malloc et free.
*/

t_image		*malloc_image(int x, int y)
{
	t_image	*img;
	
	if (!(img = malloc(sizeof(t_image))))
		minirt_exit_on_error(1);
	img->size = malloc_vec2(x, y);
	img->img_ptr = mlx_new_image(g_app->mlx_ptr, img->size->x, img->size->y);
	img->pixels = mlx_get_data_addr(img->img_ptr,
								&(img->bits_per_pixel),
								&(img->size_line),
								&(img->endian));
	printf("END MALLOC IMAGE : \n");
	print_all_cam(g_app->scene->cam);

	return (img);
}

/*
**	Free le contenu d'une t_image.
**	Ne pas free to_destroy.pixels car ca fait planter la mlx
*/

void		destroy_image(t_image to_destroy)
{
	mlx_destroy_image(g_app->mlx_ptr, to_destroy.img_ptr);
}

/*
**	Free une t_image entierement.
*/

void		free_image(t_image *to_free)
{
	destroy_image(*to_free);
	free(to_free);
}
