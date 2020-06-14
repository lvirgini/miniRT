/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:38:26 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/13 12:23:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int handle_key(int key, void **param)
{
	(void)param;

	printf("key = %d\n", key);
	
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_SPACE)
			;
	else if (key == 65361) // fleche gauche
		g_app->scene->light->pos.x -= 10;
	else if (key == 65363) // fleche droite
		g_app->scene->light->pos.x += 10;
	else if (key == 65362) // fleche haut
		g_app->scene->light->pos.y += 10;
	else if (key == 65364) // fleche bas
		g_app->scene->light->pos.y -= 10;
	else if (key == 65451) // +
		g_app->scene->light->pos.z -= 10;
	else if (key == 65453) // -
		g_app->scene->light->pos.z += 10;
	raytracing_test(param);
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
	t_obj		*first_obj;
	sphere = g_app->scene->objs->shape;

	/*printf("%p g_app->scene->obj->shape\n", g_app->scene->objs->shape);
	printf("%p sphere\n", sphere);
	printf("radius = %f\n", sphere->radius);
*/


	ray = malloc_ray(create_vec3(0, 0, 0), create_vec3(0, 0, 0));

	ray->direction = ft_normalize_vec3(create_vec3(y - g_app->size.x / 2, x - g_app->size.y / 2, - g_app->size.x / (2 * tan(g_app->scene->cam->fov/2))));
	first_obj = find_first_intersection(ray, g_app->scene->objs);

	if (first_obj)
	{
		sphere = first_obj->shape;
		if (button == 4)
			sphere->radius += 1;
		if (button == 5 && sphere->radius > 1)
			sphere->radius -= 1;
		if (button == 1)
		{
			t_color color = find_pixel_color(first_obj, ray);
			printf("r = %d\ng = %d\nb = %d\na = %d\n\n", color.r, color.b, color.b, color.a);
		}
			
		raytracing_test(param);
	}	


	

	return (0);
}
