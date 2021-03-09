/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:17:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/09 12:34:59 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** recherche l'intersection avec un plan, renvoi la distance t ou 0 si pas
** d'intersection.
**
**		(o)ray
**		| \
**		|  \
**	  v |   \ _ray_dot_pl
** _____|____\_)_________________
**			  P
*/

double		intersect_plane(t_ray *ray, t_plane *plane, t_vec3 *pt_inter,
				t_vec3 *normal)
{
	double	ray_dot_pl;
	double	t;
	t_vec3	v;

	ray_dot_pl = dot_vec3(plane->normal, ray->direction);
	if (fabs(ray_dot_pl) < RAY_T_MIN)
		return (0);
	v = sub_vec3(plane->pos, ray->origin);
	t = dot_vec3(v, plane->normal) / ray_dot_pl;
	if (t < RAY_T_MIN || t > RAY_T_MAX)
		return (0);
	*pt_inter = add_vec3(ray->origin, mul_vec3(ray->direction, t));
	if (dot_vec3(v, plane->normal) < 0)
		*normal = plane->normal;
	else
		*normal = mul_vec3(plane->normal, -1);
	return (t);
}

double		intersect_disc(t_ray *ray, t_disc *disc, t_vec3 *pt_inter,
				t_vec3 *normal)
{
	t_vec3	distance;
	double	ray_dot_pl;
	double	t;
	t_vec3	v;

	t = intersect_plane(ray, (t_plane *)disc, pt_inter, normal);
/*	ray_dot_pl = dot_vec3(disc->normal, ray->direction);
	if (fabs(ray_dot_pl) < RAY_T_MIN)
		return (0);
	v = sub_vec3(disc->pos, ray->origin);
	t = dot_vec3(v, disc->normal) / ray_dot_pl;
	if (t < RAY_T_MIN || t > RAY_T_MAX)
		return (0);*/
	distance = sub_vec3(*pt_inter, disc->pos);
	if (sqrt(dot_vec3(distance, distance)) > disc->radius2)
		return (0);
	*pt_inter = add_vec3(ray->origin, mul_vec3(ray->direction, t));
	if (dot_vec3(v, disc->normal) < 0)
		*normal = disc->normal;
	else
		*normal = mul_vec3(disc->normal, -1);
	return (t);
}
