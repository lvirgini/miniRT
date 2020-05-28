/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:38:26 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/28 16:56:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int handle_key(int key, void **param)
{
	//t_color *color;
	//t_color *color;

	//color = ((void **)(param))[0];
	//color = ((void **)(param))[1];

	(void **)param;
	t_color *color =  malloc_color(200, 50, 70, 255);

	printf("key = %d\n", key);
	//printf("param = %p\n", param);
	//printf("param[0] = %p\n", param + 1);
	
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_SPACE)
			;
	else if (key == KEY_R)
		color->r = color->r < 245 ? color->r + 10 : 255;
	else if (key == KEY_G)
		color->g = color->g < 245 ? color->g + 10 : 255;
	else if (key == KEY_B)
		color->b = color->b < 245 ? color->b + 10 : 255;
	return (0);
}


/*
** 1 = clic gauche
** 2 = clic molette
** 3 = clic droit
** 4 = molette vers le haut
** 5 molette vers le bas.
*/


int		handle_mouse(int button, int x,int y, void *param)
{	
	printf("button = %d		x = %d	y = %d\n", button, x, y);
	
	t_ray 		*ray;
	t_sphere 	*sphere;

	sphere = g_app->scene->objs->shape;

	/*printf("%p g_app->scene->obj->shape\n", g_app->scene->objs->shape);
	printf("%p sphere\n", sphere);
	printf("radius = %f\n", sphere->radius);
*/


	//ray = malloc_ray(create_vec3(0, 0, 0), create_vec3(0, 0, 0));

	/*ray->direction = ft_normalize_vec3(create_vec3(y - g_app->size.x / 2, x - g_app->size.y / 2, - g_app->size.x / 2 * tan(g_app->scene->cam->fov/2))); //
	first_obj = find_first_intersection(ray, *g_app->scene->objs);*/

	/*printf("%d get sphere *gapp\n", *g_app->scene->objs);
	printf("%d get sphere *gapp\n", *(**g_app->scene->objs)->shape);
	first_obj = *(g_app->scene)->objs;
	printf("%d = first obj ",first_obj);
	sphere = (first_obj)->shape;*/


	if (button == 4)
		sphere->radius += 1;
	if (button == 5)
		sphere->radius -= 1;
	raytracing_test(param);
	return (0);
}
