/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:56:23 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/21 11:00:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion des t_image : creation malloc et free.
*/

t_image		*malloc_image(int x, int y, void *mlx_ptr)
{
	t_image	*img;

	if (!(img = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	img->size = create_vec2(x, y);
	img->img_ptr = mlx_new_image(mlx_ptr, img->size.x, img->size.y);
	img->pixels = mlx_get_data_addr(img->img_ptr,
								&(img->bits_per_pixel),
								&(img->size_line),
								&(img->endian));
	img->sepia = NULL;
	img->black = NULL;
	return (img);
}

/*
**	Free une t_image entierement.
*/

void		free_image(t_image *to_free, void *mlx_ptr, int nb_img)
{
	t_image	*tmp;

	while (nb_img--)
	{
		tmp = to_free->next;
		mlx_destroy_image(mlx_ptr, to_free->img_ptr);
		if (to_free->sepia)
			mlx_destroy_image(mlx_ptr, to_free->sepia->img_ptr);
		if (to_free->black)
			mlx_destroy_image(mlx_ptr, to_free->black->img_ptr);
		free(to_free);
		to_free = tmp;
	}
}
