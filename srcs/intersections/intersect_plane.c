/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:17:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/18 11:57:36 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** recherche l'intersection avec un plan, renvoi la distance t ou 0 si pas
** d'intersection.
*/

double		intersect_plane(t_ray *ray, t_plane *plane, t_vec3 *pt_inter,
				t_vec3 *normal)
{
	double n_dot_ray;
	double d;
	double t;

	n_dot_ray = dot_vec3(ray->direction, plane->normal);
	if (n_dot_ray <= 0)
		return (0);
	d = dot_vec3(plane->normal, sub_vec3(ray->origin, plane->pos));
	t = -d / n_dot_ray;
	if (t < RAY_T_MIN || t > RAY_T_MAX)
		return (0);
	*pt_inter = add_vec3(ray->origin, mul_vec3(ray->direction, t));
	if (dot_vec3(sub_vec3(plane->pos, ray->origin), plane->normal) < 0)
		*normal = plane->normal;
	else
		*normal = mul_vec3(plane->normal, -1);
	return (t);
}
