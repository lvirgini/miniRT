/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_basics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:24:37 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/27 20:31:34 by lvirgini         ###   ########.fr       */
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

/*
** Recherche par type d'objet les intersecition avec le rayon
*/


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
** Recherche la premiere intersection avec un objet.
*/

t_obj		*find_first_intersection(t_ray *ray, t_obj *objs)
{
	double	t1;
	double	t2;
	t_obj	*first_obj;
	
	if (!objs || (t1 = intersect_objects(ray, objs) == 0))
		return (NULL);
	first_obj = objs;
	while (objs->next)
	{
		objs = objs->next;
		t2 = intersect_objects(ray, objs);
		if (t2 < t1)
			first_obj = objs;
	}
	return (first_obj);
}


void		print_object(t_obj *obj, int x, int y)
{
	t_sphere *sphere;

	if (obj->type == SPHERE)
	{
		sphere = (t_sphere *)obj->shape;
		put_pixel(g_app->img, x, y, sphere->color);
	}
		

}
/*
** Pour chaque pixel de l'image, recherche une intersection avec un obj en fonction du rayon de la camera (cam) envoyé en parametre.
*/

int			browse_image_for_intersection(t_camera *cam, int win_x, int win_y)
{
	int		i;
	int		j;
	t_obj	*first_obj;

	i = 0;
	j = 0;

	t_ray *ray;
	ray = malloc_ray(create_vec3(0, 0, 0), create_vec3(0, 0, 0));

	while (i < win_x)
	{
		while (j < win_y)
		{
			ray->direction = ft_normalize_vec3(create_vec3(j - win_x / 2, i - win_y / 2, - win_x / 2 * tan(cam->fov/2)));
			first_obj = find_first_intersection(ray, *g_app->scene->objs);
			if (first_obj != NULL)
				print_object(first_obj, i, j);
/*
			if (intersect_objects(ray, *g_app->scene->objs) > 0)
				put_pixel(g_app->img, i, j, create_color(0,0,155,255));*/
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
