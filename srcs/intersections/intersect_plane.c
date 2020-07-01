/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:17:28 by lvirgini          #+#    #+#             */
/*   Updated: 2020/07/01 11:03:14 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** recherche l'intersection avec un plan, renvoi la distance t ou 0 si pas
** d'intersection.
*/

double		intersect_plane(t_ray *ray, t_plane *plane, t_vec3 *pt_intersection, t_vec3 *normal)
{
	double m;
	double d;
	double t;

	m = dot_vec3(ray->direction, plane->normal);
	//printf("m = %f\n", m);
	if (m < 0)
		return (0);
	d = dot_vec3(plane->normal, sub_vec3(ray->origin, plane->pos));
	t = -d / m;

	if (t < RAY_T_MIN || t > RAY_T_MAX)
		return (0);
	*pt_intersection = add_vec3(ray->origin, mul_vec3(ray->direction, t));
	if (dot_vec3(sub_vec3(plane->pos, ray->origin), plane->normal) < 0)
		*normal = plane->normal;
	else
		*normal = mul_vec3(plane->normal, -1);
	return (t);
}