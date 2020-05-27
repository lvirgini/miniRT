/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:57:28 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/04 14:28:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void draw_rectangle(t_vec2 pos, t_vec2 size, t_color color)
{
	draw_rectangle_in_image(g_app->img, pos, size, color);
}

void draw_rectangle_in_image(t_image *image, t_vec2 pos, t_vec2 size, t_color color)
{
	int	 i;
	int	 j;

	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			put_pixel(image, i + pos.x, j + pos.y, color);
			j++;
		}
		i++;
	}
}



