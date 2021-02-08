/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_basics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:24:37 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/08 12:13:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Renvoie a la fonction d'intersection suivant le type d'objet.
*/

static double	intersect_obj(t_ray *ray, t_obj *obj, t_vec3 *p, t_vec3 *normal)
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
	ray->pt_inter = copy_vec3(pt_inter);
	ray->normal = copy_vec3(normal);
	ray->t = t;
}

/*
** Recherche la premiere intersection du rayon avec un objet.
**	ray->t == -1 : a l'interieur d'un obj
*/

t_obj			*closest_object(t_ray *ray, t_obj *objs)
{
	t_obj	*closest_obj;
	double	t2;
	t_vec3	pt_inter;
	t_vec3	normal;

	if (!objs)
		return (NULL);
	if ((ray->t = intersect_obj(ray, objs, &ray->pt_inter, &ray->normal)) == 0)
		return (closest_object(ray, objs->next));
	if (ray->t == -1.0)
		return (NULL);
	closest_obj = objs;
	while (objs->next)
	{
		t2 = intersect_obj(ray, objs->next, &pt_inter, &normal);
		if (ray->t == -1.0)
			return (NULL);
		if (t2 != 0 && t2 < ray->t)
		{
			closest_obj = objs->next;
			update_ray(ray, pt_inter, normal, t2);
		}
		objs = objs->next;
	}
	return (closest_obj);
}

static int		free_ray_return(t_ray *ray)
{
	free(ray);
	return (-1);
}

static void		reinit_ray_pt_and_normal(t_ray *ray)
{
	ray->pt_inter = create_vec3(0, 0, 0);
	ray->normal = create_vec3(0, 0, 0);
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
	t_obj	*close_obj;
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
			if ((close_obj = closest_object(ray, g_scene->objs)) != NULL)
				put_pixel(img, x, h - y - 1, find_pixel_color(close_obj, ray));
			else if (ray->t == -1)
				return (free_ray_return(ray));
			reinit_ray_pt_and_normal(ray);
			y++;
		}
		x++;
	}
	free(ray);
	return (0);
}
