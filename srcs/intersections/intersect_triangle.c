/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:44:25 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/30 15:55:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//float D = dotProduct(N, v0); 
//float t = - (dot(N, orig) + D) / dot(N, dir); 

double		intersect_triangle(t_ray *ray, t_triangle *triangle, t_vec3 *pt_intersection, t_vec3 *normal)
{

	double n_dot_ray = ft_dot_vec3(ray->direction, triangle->normal);
	if (n_dot_ray < RAY_T_MIN)
		return (0);

	double d = ft_dot_vec3(triangle->normal, triangle->pos1);

	double t = - (ft_dot_vec3(triangle->normal, ray->origin) + d) / n_dot_ray;
	if (t < RAY_T_MIN || t > RAY_T_MAX)
		return (0);
	*pt_intersection = ft_add_vec3(ray->origin, ft_mul_vec3(ray->direction, t));
	/*if (ft_dot_vec3(ft_sub_vec3(triangle->pos1, ray->origin), triangle->normal) < 0)*/
		*normal = triangle->normal;
	/*else
		*normal = ft_mul_vec3(triangle->normal, -1);*/
	return (t);
}