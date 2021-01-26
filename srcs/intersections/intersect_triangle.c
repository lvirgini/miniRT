/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:44:25 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/06 16:14:49 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Triangle pt A, B, C, normale N,  et un rayon O(origine) d(direction).
** Verifier si le rayon et le plan du triangle se touchent :
**		N.R > 0.
** Calculer si le point d'intersection se trouve a l'interieur ou a l'exterieur du triangle.
**
*/

double		intersect_triangle(t_ray *ray, t_triangle *triangle, t_vec3 *pt_intersection, t_vec3 *normal)
{
	double 	t;
	double	gamma;
	double	beta;
	double	alpha;
	t_vec3	ap;

	t = intersect_plane( ray, triangle->plane, pt_intersection, normal);
	if (t == 0)
		return (0);
	ap = sub_vec3(*pt_intersection, triangle->a);
	gamma = ((triangle->norme2_ab * dot_vec3(ap, triangle->ac)) - (triangle->dot_ab_ac * dot_vec3(ap, triangle->ab))) / triangle->determinant;
	beta = ((dot_vec3(ap, triangle->ab) * triangle->norme2_ac) - (dot_vec3(ap, triangle->ac) * triangle->dot_ab_ac)) / triangle->determinant;
	alpha = 1 - beta - gamma;
	if (gamma < 0 || gamma > 1 || beta < 0 || beta > 1 || alpha < 0 || alpha > 1)
		return (0);
	return (t);
}
