/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_basics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:24:37 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/27 17:51:45 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** En partant de l'origin du rayon, retourne l'emplacement du point lorsque
** direction * t.
** return = origin + (direction * t)
*/

t_vec3		ray_calculate_t(t_ray ray, double t)
{
	return (ft_add_vec3(ray.origin, ft_mul_vec3(ray.direction, t)));
}




double		intersect_objects(t_ray *ray, t_obj *objs)
{
	double t;

	t = 0;
	while (objs)
	{
		//printf("obj = %d\n", objs->type);
		if (objs->type == SPHERE)
			t = intersect_sphere(*ray, *(t_sphere *)objs->shape);
		/*else if (objs->type == PLANE)
			intersect_plane(ray, *objs);
		else if (objs->type == SQUARE)
			intersect_square(ray, *objs);
		else if (objs->type == CYLINDRE)
			intersect_cylindre(ray, *objs);
		else if (objs->type == TRIANGLE)
			intersect_triange(ray, *objs);*/
		objs = objs->next;
	}
	return (t);
}



/*
** Pour chaque pixel de l'image, recherche une intersection avec un obj
*/

/*
int			find_intersection(t_camera *cam, int win_x, int win_y)
{
	int		i;
	int		j;
	int		t;
	
	double fov = 60 * PI / 180;
	
	i = 0;
	j = 0;

	t_sphere *sphere;

	sphere = malloc_sphere(create_vec3(0, 0, -55), 20, create_color(0,0,155,255));
	t_ray *ray;
	ray = malloc_ray(create_vec3(0, 0, 0), create_vec3(0, 0, 0));

	while (i < win_x)
	{
		while (j < win_y)
		{
			ray->direction = ft_normalize_vec3(create_vec3(j - win_x / 2, i - win_y / 2, - win_x / 2 * tan(fov/2)));

			if (intersect_sphere(*ray, *sphere) == True)
				put_pixel(g_app->img, i, j, sphere->color);


			//t = intersect_objects(ray, *(g_app)->scene->objs);
			//if (t > 0)
			//	put_pixel(g_app->img, i, j, create_color(0,0,155,255)); 
			//j++;
		}
		j = 0;
		i++;
	}
	return (0);
}*/



int			find_intersection(t_camera *cam, int win_x, int win_y)
{
	int i;
	int j;

	double fov = 60 * PI / 180;
	printf("fov = %f et cam fov = %f\n", fov, cam->fov);
	t_sphere *sphere;

	sphere = malloc_sphere(create_vec3(0, 0, -55), 20, create_color(0,0,155,255));
	i = 0;
	j = 0;

	t_ray *ray;
	ray = malloc_ray(create_vec3(0, 0, 0), create_vec3(0, 0, 0));

	while (i < win_x)
	{
		while (j < win_y)
		{
			ray->direction = ft_normalize_vec3(create_vec3(j - win_x / 2, i - win_y / 2, - win_x / 2 * tan(cam->fov/2)));
			/// ICI A FAIRE COMME A DESSUS
			if (intersect_sphere(*ray, *sphere) > 0)
				put_pixel(g_app->img, i, j, sphere->color);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
