/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:09:36 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/09 13:09:24 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		intersect_square(t_ray *ray, t_square *sq, t_vec3 *pt_inter,
				t_vec3 *normal)
{
	t_vec3	d;
	double	middle_edge;
	double	t;

	t = intersect_plane(ray, (t_plane *)sq, pt_inter, normal);
	if (t)
	{
		middle_edge = sq->hight * 0.5;
		d = sub_vec3(*pt_inter, sq->pos);
		if (fabs(d.x) <= middle_edge && fabs(d.x) <= middle_edge &&
			fabs(d.z) <= middle_edge)
			return (t);
	}
	return (0);
}
