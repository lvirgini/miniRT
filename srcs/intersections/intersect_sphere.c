/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:14:47 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/08 14:13:55 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** intersection entre un rayon et une sphere revient a resoudre :
** a*t² + b*t + c = 0
** delta = b² - 4ac
** si delta < 0 pas d'intersection.
** t1 = -b - racine(delta) / 2a  -> plus proche
** t2 = -b + racine(delta) / 2a  -> plus loin
**
** retourne la longueur la plus petite ou 0 si pas d'intersection.
** modifie le pt_inter = rayon origin + (t * rayon direction)
** la normale = vecteur normalise (pt intersection - sphere origine)
*/

// if if (t[0] < RAY_T_MIN && t[1] > RAY_T_MIN && t[1] < RAY_T_MAX
//	return t[1] interieur sphere 

double		intersect_sphere(t_ray *ray, t_sphere *sphere,
				t_vec3 *pt_inter, t_vec3 *normal)
{
	double b;
	double c;
	double delta;
	double t[2];

	b = 2 * dot_vec3(ray->direction, sub_vec3(ray->origin, sphere->pos));
	c = (norme2_vec3(sub_vec3(ray->origin, sphere->pos)) -
							(sphere->radius * sphere->radius));
	if ((delta = (b * b) - (4 * 1.0 * c)) < 0)
		return (0);
	t[0] = (-b - sqrt(delta)) / (2 * 1.0);
	t[1] = (-b + sqrt(delta)) / (2 * 1.0);
	if (t[1] < RAY_T_MIN)
		return (0);
	if (t[0] > RAY_T_MIN && t[0] < RAY_T_MAX)
	{
		*pt_inter = add_vec3(ray->origin, mul_vec3(ray->direction, t[0]));
		*normal = normalize_vec3(sub_vec3(*pt_inter, sphere->pos));
		return (t[0]);
	}
	if (t[0] < RAY_T_MIN && t[1] > RAY_T_MIN && (ray->t = -1.0) == -1.0)
		return (ray->t);
	return (0);
}
