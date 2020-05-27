/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:14:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/27 17:10:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** interesction entre un rayon et une sphere revient a resoudre : 
** 2a + b2 + c = 0
*/

double		intersect_sphere(t_ray ray, t_sphere sphere)
{
	double a;
	double b;
	double c;
	double delta;
	double t[2];

	a = 1;
	b = 2 * ft_dot_vec3(ray.direction, ft_sub_vec3(ray.origin, sphere.pos));
	c = (ft_norme2_vec3(ft_sub_vec3(ray.origin, sphere.pos)) - sphere.radius * sphere.radius);
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return (0);
	t[0] = (-b + sqrt(delta)) / (2 * a);
	t[1] = (-b + sqrt(delta)) / (2 * a);
	if (t[1] > 0)
		return (t[1]);
	return (0);
}