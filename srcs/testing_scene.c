/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:12:51 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/27 09:53:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		premiers_test(void *param)
{
	/*
	clear_application(fuze_color(create_color(255,0, 50, 255), create_color(0, 255, 0, 100)));
	draw_rectangle(create_vec2(130,180), create_vec2(160,400), create_color(0,0,0,100));
	draw_rectangle(create_vec2(150,150), create_vec2(200,200), create_color(255,0,0,100));
	draw_rectangle(create_vec2(180,180), create_vec2(250,250), create_color(0x33,0x33,0x66,150));
	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->img->img_ptr,0, 0);
*/

/*
	clear_application(create_color(255, 255, 255, 255));
	
	for (int i = - 100; i < 800; i += 1)
	{
		if (i < 255)
			draw_rectangle(create_vec2(i, i), create_vec2(150, 150), create_color(i, 0, 0, 1));
		else if (i >= 255 && i < 510)
			draw_rectangle(create_vec2(i, i), create_vec2(150, 150), create_color(255, 0, i - 255, 1));
		else
			draw_rectangle(create_vec2(i, i), create_vec2(150, 150), create_color(255, i - 510 , 255, 1));
	}*//*
	draw_rectangle(create_vec2(50, 50), create_vec2(100, 100), create_color(255, 0 , 0, 150));
	draw_rectangle(create_vec2(90, 90), create_vec2(150, 150), create_color(0, 255 , 0, 150));
	draw_rectangle(create_vec2(140, 140), create_vec2(200, 200), create_color(0, 0 ,255, 150));

		for (int i = - 100; i < 800; i += 1)
	{
		draw_rectangle(create_vec2(i, i + 100), create_vec2(150, 150), create_color(255, 0, 0, 1));
	}

		for (int i = - 100; i < 800; i += 1)
	{
		draw_rectangle(create_vec2(i, i + 200), create_vec2(150, 150), create_color(0, 255, 0, 1));
	}

			for (int i = - 100; i < 800; i += 1)
	{
		draw_rectangle(create_vec2(i, i + 350), create_vec2(150, 150), create_color(0, 0, 255, 1));
	}
	draw_rectangle(create_vec2(0,0), create_vec2(450,150), create_color(150,0,100,200));
	draw_rectangle(create_vec2(400,70), create_vec2(600,200), create_color(50,0,100,200));

	*/
	t_color *color;
	//t_color *color2;


	color = ((void **)(param))[0];
	//color2 = ((void **)(param))[1];

	clear_application(*color);
	draw_rectangle(create_vec2(130,180), create_vec2(160,400), create_color(0,0,0,100));
	draw_rectangle(create_vec2(150,150), create_vec2(200,200), create_color(255,0,0,100));
	draw_rectangle(create_vec2(180,180), create_vec2(250,250), create_color(0x33,0x33,0x66,150));
	
	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->img->img_ptr,0, 0);
	
	return (0);
}