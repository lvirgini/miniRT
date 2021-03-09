/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_basics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:24:37 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/09 11:07:11 by lvirgini         ###   ########.fr       */
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
	else if (obj->type == SQUARE)
		return (intersect_square(ray, (t_square *)obj->shape, p, normal));
	/*else if (obj->type == CYLINDRE)
		return (intersect_cylindre(ray, (t_cyl *)obj->shape, p, normal));*/
	return (0);
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
	closest_obj = objs;
	while (objs->next)
	{
		t2 = intersect_obj(ray, objs->next, &pt_inter, &normal);
		if (t2 != 0 && t2 < ray->t)
		{
			closest_obj = objs->next;
			ray->pt_inter = pt_inter;
			ray->normal = normal;
			ray->t = t2;
		}
		objs = objs->next;
	}
	return (closest_obj);
}

/*
**   x and y + dir_std : for less calculs.
**			 	x +		- (w / 2) + 0.5
**				y + 	- (h / 2) + 0.5
**				0 + 	w / (2 * tan(cam->angle))));
*/

static void		reinit_ray_direction(t_ray *ray, t_m4x4 matrix,
					t_vec3 xy_canvas)
{
	ray->direction = normalize_vec3(add_vec3(xy_canvas, ray->dir_std));
	ray->direction = m4x4_mul_vec(matrix, ray->direction);
	ray->pt_inter = create_vec3(0, 0, 0);
	ray->normal = create_vec3(0, 0, 0);
}

static void		get_camera_matrix(t_m4x4 m, t_camera cam)
{
	t_vec3	right;
	t_vec3	up;
	t_vec3	m_ru[2];
	t_vec3	world_up;

	if (cam.orient.y == 1)
		world_up = create_vec3(0, 0, -1);
	else if (cam.orient.y == -1)
		world_up = create_vec3(0, 0, 1);
	else
		world_up = create_vec3(0, 1, 0);
	right = normalize_vec3(cross_vec3(cam.orient, world_up));
	up = normalize_vec3(cross_vec3(right, cam.orient));
	m_ru[0] = right;
	m_ru[1] = up;
	m4x4_create(m, m_ru, cam.orient, cam.pos);
	m4x4_create_invers(m, m_ru, cam.orient, create_vec3(0, 0, 0));
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
	t_ray	ray;
	t_m4x4	cam_matrix;

	get_camera_matrix(cam_matrix, *cam);
//	m4x4_print(cam_matrix);
	ray = create_ray(cam->pos, cam->orient,
		create_vec3(-(w / 2) + 0.5, -(h / 2) + 0.5, w / (2 * tan(cam->angle))));
	x = -1;
	while (++x < w)
	{
		y = -1;
		while (++y < h)
		{
			reinit_ray_direction(&ray, cam_matrix, create_vec3(x, y, 0));
			if ((close_obj = closest_object(&ray, g_scene->objs)) != NULL)
				put_pixel(img, w - x - 1, h - y - 1, find_pixel_color(
						close_obj, &ray));
			else
				put_pixel(img, w - x - 1, h - y - 1, create_color(0, 0, 0));
		}
	}
	return (0);
}
