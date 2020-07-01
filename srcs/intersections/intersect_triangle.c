/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:44:25 by lvirgini          #+#    #+#             */
/*   Updated: 2020/07/01 15:47:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//float D = dotProduct(N, v0); 
//float t = - (dot(N, orig) + D) / dot(N, dir); 
/*
** Triangle pt A, B, C, normale N,  et rayon O(origine) R(direction).
** Verifier si le rayon et le plan du triangle se touchent : 
**		N.R > 0.
** Calculer l'intersection : 
**		t = - (O.N - N.A) / (N.R)
*/

/*double		intersect_triangle(t_ray *ray, t_triangle *triangle, t_vec3 *pt_intersection, t_vec3 *normal)
{
	double	n_dot_ray;
	double	d;
	double	t;

	n_dot_ray = dot_vec3(ray->direction, triangle->normal);
	if (n_dot_ray < RAY_T_MIN)
		return (0);
	//d =  ft_dot_vec3( triangle->pos1, triangle->normal);

//	d = ft_dot_vec3(triangle->normal, ft_sub_vec3(ray->origin, triangle->pos1));

	d = (dot_vec3(triangle->normal, triangle->pos1));
	double a = dot_vec3(ray->origin, triangle->normal) - d;
	double b = dot_vec3(ray->direction, triangle->normal);
	t = - a / b;
	if (t < RAY_T_MIN || t > RAY_T_MAX)
		return (0);

	*pt_intersection = add_vec3(ray->origin, mul_vec3(ray->direction, t));
	*//*if (dot_vec3(sub_vec3(ray->origin, triangle->pos1), triangle->normal) < 0)
		*normal = triangle->normal;
	else
		*normal = mul_vec3(triangle->normal, -1);*/
/*

	double dot_uu = dot_vec3(triangle->vec1, triangle->vec1);
	double dot_uv = dot_vec3(triangle->vec1, triangle->vec2);
	double dot_vv = dot_vec3(triangle->vec2, triangle->vec2);
	double d2 = dot_uv * dot_uv - dot_uu * dot_vv;
	t_vec3 w = sub_vec3(*pt_intersection, triangle->pos1);
	double dot_wv = dot_vec3(w, triangle->vec1);
	double dot_wu = dot_vec3(w, triangle->vec2);

	double r = (dot_uv * dot_wu) - (dot_vv * dot_wv) / d2;
		if (r < 0 || r > 1)
			return (0);



	return(t);
	t_vec3 c;


	t_vec3 edge = sub_vec3(triangle->pos2, triangle->pos1);
	t_vec3 vp = sub_vec3(*pt_intersection, triangle->pos1);
	c = cross_vec3(edge, vp);
	if (dot_vec3(triangle->normal, c) < 0)
		return (0);
	

	edge = sub_vec3(triangle->pos3, triangle->pos2);
	vp = sub_vec3(*pt_intersection, triangle->pos2);
	c = cross_vec3(edge, vp);
	if (dot_vec3(triangle->normal, c) < 0)
		return (0);


	edge = sub_vec3(triangle->pos1, triangle->pos3);
	vp = sub_vec3(*pt_intersection, triangle->pos3);
	c = cross_vec3(edge, vp);
	if (dot_vec3(triangle->normal, c) < 0)
		return (0);
	return (t);
}*/