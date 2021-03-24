/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:14:47 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/24 17:16:36 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** intersection entre un rayon et une sphere revient a resoudre :
** a*t² + b*t + c = 0
** 		pt_inter = rayon origin + (t * rayon direction)
** 		normale = vecteur normalise (pt intersection - sphere origine)
*/

double			intersect_sphere(t_ray *ray, t_sphere *sphere,
					t_vec3 *pt_inter, t_vec3 *normal)
{
	double b;
	double c;
	double t[2];

	b = 2 * dot_vec3(ray->dir, sub_vec3(ray->origin, sphere->pos));
	c = (norme2_vec3(sub_vec3(ray->origin, sphere->pos)) -
							(sphere->radius * sphere->radius));
	if ((t[0] = quadratic_equation(1, b, c, t)) != 0)
	{
		*pt_inter = add_vec3(ray->origin, mul_vec3(ray->dir, t[0]));
		*normal = normalize_vec3(sub_vec3(*pt_inter, sphere->pos));
	}
	return (t[0]);
}
