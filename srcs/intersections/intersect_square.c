/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:09:36 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 13:18:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**	if inter plane of square :
**	d =  pt inter - square center.(sq->pos = center of square)
** check if d inside the square
*/

double		intersect_square(t_ray *ray, t_square *sq, t_vec3 *pt_inter,
				t_vec3 *normal)
{
	t_vec3	d;
	double	middle_edge;
	double	t;

	t = intersect_plane(ray, (t_plane *)sq, pt_inter, normal);
	if (t)
	{
		d = sub_vec3(*pt_inter, sq->pos);
		middle_edge = sq->hight * 0.5;
		if (fabs(d.x) <= middle_edge && fabs(d.y) <= middle_edge &&
			fabs(d.z) <= middle_edge)
			return (t);
	}
	return (0);
}
