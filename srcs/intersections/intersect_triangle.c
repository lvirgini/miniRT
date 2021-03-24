/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:44:25 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/24 15:20:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Triangle pt A, B, C, normale N,  et un rayon O(origine) d(direction).
** methode moller trumbore
** Calculer si le point d'intersection se trouve a l'interieur ou a l'exterieur
** du triangle.
**						 a
**				oa/		 / \
**	 ray(o)_____________/__ \
**					   /	 \
**					  /_______\
**					b			c
*/

double		intersect_triangle(t_ray *ray, t_triangle *tri, t_vec3 *pt_inter,
				t_vec3 *normal)
{
	double	t;
	double	det;
	t_vec3	oa;
	t_vec3	vec[2];
	double	angle[2];

	vec[0] = cross_vec3(ray->dir, tri->ac);
	det = dot_vec3(tri->ab, vec[0]);
	if (fabs(det) < RAY_T_MIN)
		return (0);
	det = 1.0 / det;
	oa = sub_vec3(ray->origin, tri->a);
	angle[0] = det * (dot_vec3(oa, vec[0]));
	if (angle[0] < 0.0 || angle[0] > 1.0)
		return (0);
	vec[1] = cross_vec3(oa, tri->ab);
	angle[1] = det * dot_vec3(ray->dir, vec[1]);
	if (angle[1] < 0.0 || angle[0] + angle[1] > 1.0)
		return (0);
	t = det * dot_vec3(tri->ac, vec[1]);
	if (t < RAY_T_MIN)
		return (0);
	*pt_inter = add_vec3(ray->origin, mul_vec3(ray->dir, t));
	*normal = tri->normal;
	return (t);
}
