/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_basics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:24:37 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/03 14:12:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Renvoie a la fonction d'intersection suivant le type d'objet.
*/

static double	intersect_objects(t_ray *ray, t_obj *obj, t_vec3 *p,
	t_vec3 *normal)
{
	if (!obj)
		return (0);
	if (obj->type == SPHERE)
		return (intersect_sphere(ray, (t_sphere *)obj->shape, p, normal));
	else if (obj->type == PLANE)
		return (intersect_plane(ray, (t_plane *)obj->shape, p, normal));
	else if (obj->type == TRIANGLE)
		return (intersect_triangle(ray, (t_triangle *)obj->shape, p, normal));
	/*else if (obj->type == SQUARE)
		return (intersect_square(ray, (t_square *)obj->shape, p, normal));
	else if (obj->type == CYLINDRE)
		return (intersect_cylindre(ray, (t_cyl *)obj->shape, p, normal));*/
	return (0);
}

static void		update_ray(t_ray *ray, t_vec3 pt_inter, t_vec3 normal, int t)
{
	ray->pt_intersection = copy_vec3(pt_inter);
	ray->normal = copy_vec3(normal);
	ray->t = t;
}

/*
** Recherche la premiere intersection du rayon avec un objet.
*/

t_obj			*closest_object(t_ray *ray, t_obj *objs)
{
	t_obj	*closest_obj;
	double	t2;
	t_vec3	pt_inter;
	t_vec3	normal;

	if (!objs)
		return (NULL);
	ray->t = intersect_objects(ray, objs, &ray->pt_intersection, &ray->normal);
	if (ray->t == 0)
		return (closest_object(ray, objs->next));
	closest_obj = objs;
	while (objs->next)
	{
		t2 = intersect_objects(ray, objs->next, &pt_inter, &normal);
		if (t2 > 0 && t2 < ray->t)
		{
			closest_obj = objs->next;
			update_ray(ray, pt_inter, normal, t2);
		}
		objs = objs->next;
	}
	return (closest_obj);
}

/*
** Pour chaque pixel de l'image, recherche une intersection avec un obj
** en fonction du rayon de la camera (cam) envoyé en parametre.
*/

int				browse_image_for_intersection(t_camera *cam, int w, int h,
			t_image *img)
{
	int		x;
	int		y;
	t_obj	*closest_obj;
	t_ray	*ray;

	ray = malloc_ray(cam->pos, sub_vec3(cam->orient, cam->pos));
	x = 0;
	while (x < w)
	{
		y = 0;
		while (y < h)
		{
			ray->direction = normalize_vec3(create_vec3(x - (w / 2) + 0.5,
							y - (h / 2) + 0.5, -w / (2 * tan(cam->fov / 2))));
			closest_obj = closest_object(ray, g_scene->objs);
			if (closest_obj != NULL)
				{
					put_pixel(img, x, h - y - 1, find_pixel_color(closest_obj, ray));
				}
			ray->pt_intersection = create_vec3(0, 0, 0);
			ray->normal = create_vec3(0, 0, 0);
			y++;
		}
		x++;
	}
	free_ray(ray);
	return (0);
}
