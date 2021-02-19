/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:22:26 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/18 14:04:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Inscrit sur l'image la couleur donnée sur le pixel de coordonnees x, y.
*/

void		put_pixel(t_image *image, int x, int y, t_color color)
{
	int		pixel_index;

	if (x < 0 || y < 0 || x >= image->size.x || y >= image->size.y)
		return ;
	pixel_index = (y * image->size.x + x) * 4;
	image->pixels[pixel_index + RED_PIXEL] = (char)color.r;
	image->pixels[pixel_index + GREEN_PIXEL] = (char)color.g;
	image->pixels[pixel_index + BLUE_PIXEL] = (char)color.b;
	image->pixels[pixel_index + ALPHA_PIXEL] = 0;
}
