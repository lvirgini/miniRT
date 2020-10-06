/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:44:25 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/06 16:01:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//double t = - (dot(N, origine) + D) / dot(N, dir);

/*
** Triangle pt A, B, C, normale N,  et un rayon O(origine) d(direction).
** Verifier si le rayon et le plan du triangle se touchent :
**		N.R > 0.
** Calculer l'intersection :
**		t = OC.N / N.R
**	si t < 0 : triangle derriere la camera
**	pt intersection = O + t * d;
**
*/

static double		triangle_get_beta(t_triangle *triangle, t_vec3 ab, t_vec3 ac, t_vec3 ap)
{
	double	determinant_beta;

	determinant_beta = (dot_vec3(ap, ab) * triangle->norme2_ac) - (dot_vec3(ap, ac) * triangle->dot_ab_ac);
	return (determinant_beta / triangle->determinant);
}

static double		triangle_get_gamma(t_triangle *triangle, t_vec3 ab, t_vec3 ac, t_vec3 ap)
{
	double	determinant_gamma;

	determinant_gamma = (triangle->norme2_ab * dot_vec3(ap, ac) - (triangle->dot_ab_ac * dot_vec3(ap, ab)));
	return (determinant_gamma / triangle->determinant);
}



double		intersect_triangle(t_ray *ray, t_triangle *triangle, t_vec3 *pt_intersection, t_vec3 *normal)
{
	t_plane *tri_plane;
	double 	t;
	double	gamma;
	double	beta;
	double	alpha;
	t_vec3	ap;

	tri_plane = malloc_plane(triangle->a, triangle->ab, triangle->color, 0);
	t = intersect_plane( ray, tri_plane, pt_intersection, normal);
	 if (t == 0)
	 	return (0);
	
	ap = sub_vec3(*pt_intersection, triangle->a);
	gamma = triangle_get_gamma(triangle, triangle->ab,triangle->ac, ap);
	beta = triangle_get_beta(triangle, triangle->ab,triangle->ac, ap);
	alpha = 1 - beta - gamma;
	if (gamma < 0 || gamma > 1 || beta < 0 || beta > 1 || alpha < 0 || alpha > 1)
		return (0);
	
	//printf("OK TRIANGLE t= %f\n", t);
	return (t);
}

/* OK OK 
double		intersect_triangle(t_ray *ray, t_triangle *triangle, t_vec3 *pt_intersection, t_vec3 *normal)
{
	double	n_dot_ray;
	double	t;
	double	gamma;
	double	beta;
	double	alpha;
	t_vec3	ap;

	n_dot_ray = dot_vec3(ray->direction, triangle->normal);
	if (n_dot_ray <= 0)
		return (0);
	t = dot_vec3(sub_vec3(triangle->c, ray->origin), triangle->normal) / n_dot_ray;
	if (t < RAY_T_MIN || t > RAY_T_MAX)
		return (0);
	*pt_intersection = add_vec3(ray->origin, mul_vec3(ray->direction, t));
	ap = sub_vec3(*pt_intersection, triangle->a);
	gamma = triangle_get_gamma(triangle, triangle->ab,triangle->ac, ap);
	beta = triangle_get_beta(triangle, triangle->ab,triangle->ac, ap);
	alpha = 1 - beta - gamma;
	if (gamma < 0 || gamma > 1 || beta < 0 || beta > 1 || alpha < 0 || alpha > 1)
		return (0);
	if ((dot_vec3(sub_vec3(triangle->c, ray->origin), triangle->normal)) < 0)
		*normal = triangle->normal;
	else
	{
		*normal = mul_vec3(triangle->normal, -1);
	}
	
	//printf("OK TRIANGLE t= %f\n", t);
	return (t);
}*/


/*	//d =  ft_dot_vec3( triangle->a, triangle->normal);

//	d = ft_dot_vec3(triangle->normal, ft_sub_vec3(ray->origin, triangle->a));

	d = (dot_vec3(triangle->normal, triangle->a));
	double a = dot_vec3(ray->origin, triangle->normal) - d;
	double b = dot_vec3(ray->direction, triangle->normal);
	t = - a / b;
	if (t < RAY_T_MIN || t > RAY_T_MAX)
		return (0);

	*pt_intersection = add_vec3(ray->origin, mul_vec3(ray->direction, t));
	if (dot_vec3(sub_vec3(ray->origin, triangle->a), triangle->normal) < 0)
		*normal = triangle->normal;
	else
		*normal = mul_vec3(triangle->normal, -1);
*//*

	double dot_uu = dot_vec3(triangle->vec1, triangle->vec1);
	double dot_uv = dot_vec3(triangle->vec1, triangle->vec2);
	double dot_vv = dot_vec3(triangle->vec2, triangle->vec2);
	double d2 = dot_uv * dot_uv - dot_uu * dot_vv;
	t_vec3 w = sub_vec3(*pt_intersection, triangle->a);
	double dot_wv = dot_vec3(w, triangle->vec1);
	double dot_wu = dot_vec3(w, triangle->vec2);

	double r = (dot_uv * dot_wu) - (dot_vv * dot_wv) / d2;
		if (r < 0 || r > 1)
			return (0);



	return(t);
	t_vec3 c;


	t_vec3 edge = sub_vec3(triangle->pos2, triangle->a);
	t_vec3 vp = sub_vec3(*pt_intersection, triangle->a);
	c = cross_vec3(edge, vp);
	if (dot_vec3(triangle->normal, c) < 0)
		return (0);

	edge = sub_vec3(triangle->pos3, triangle->pos2);
	vp = sub_vec3(*pt_intersection, triangle->pos2);
	c = cross_vec3(edge, vp);
	if (dot_vec3(triangle->normal, c) < 0)
		return (0);

	edge = sub_vec3(triangle->a, triangle->pos3);
	vp = sub_vec3(*pt_intersection, triangle->pos3);
	c = cross_vec3(edge, vp);
	if (dot_vec3(triangle->normal, c) < 0)
		return (0);
	return (t);
}*/