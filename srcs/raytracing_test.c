/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:36:18 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/27 17:43:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int 	find_sphere(void)
{
	int i;
	int j;

	double fov = 60 * PI / 180;
	t_sphere *sphere;

	sphere = malloc_sphere(create_vec3(0, 0, -55), 20, create_color(0,0,155,255));
	i = 0;
	j = 0;

	t_ray *ray;
	ray = malloc_ray(create_vec3(0, 0, 0), create_vec3(0, 0, 0));

	while (i < g_app->size.x)
	{
		while (j < g_app->size.y)
		{
			ray->direction = ft_normalize_vec3(create_vec3(j - g_app->size.x / 2, i - g_app->size.y / 2, - g_app->size.x / 2 * tan(fov/2)));
			if (intersect_sphere(*ray, *sphere) > 0)
				put_pixel(g_app->img, i, j, sphere->color);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		raytracing_test(void *param)
{

	t_color *color;
	color = ((void **)(param))[2];

	t_sphere *sphere = malloc_sphere(create_vec3(0, 0, -55), 20, create_color(0, 0, 200, 200));

	t_obj *obj = malloc_object(SPHERE, sphere);

	t_camera *cam = malloc_camera(60 * PI / 180, create_vec3(0, 0, 0), create_vec3(0, 0, 1));

	g_app->scene = malloc_scene(cam, &obj);


	clear_application(*color);

	//find_sphere();
	find_intersection(g_app->scene->cam, g_app->size.x, g_app->size.y);


	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->img->img_ptr,0, 0);

	return (0);
}
