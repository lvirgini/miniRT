/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:46:56 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/24 17:16:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** finite_cylinder : if pt inter is inside the cylinder.
**	p1 = cyl->pos
**	p2 = cyl->pos_hight
**	va = cyl->orient
**	pa = ray->origin
**
**  q = pt intersection with one t find; make for the 2 t;
**		&& (va, q- p1) > 0
**		&& (va, q- p2) < 0
*/

static double	finite_cylinder(t_ray *ray, t_cyl *cyl, double t[2], t_vec3 *p)
{
	t_vec3	q;
	t_vec3	q2;

	q = add_vec3(ray->origin, mul_vec3(ray->dir, t[0]));
	if (t[0] > RAY_T_MIN && t[0] < t[1]
		&& dot_vec3(cyl->orient, sub_vec3(q, cyl->pos)) >= 0.0
		&& dot_vec3(cyl->orient, sub_vec3(q, cyl->pos_hight)) <= 0.0)
	{
		*p = q;
		return (t[0]);
	}
	q2 = add_vec3(ray->origin, mul_vec3(ray->dir, t[1]));
	if (t[1] > RAY_T_MIN && t[0] < t[1]
		&& dot_vec3(cyl->orient, sub_vec3(q2, cyl->pos)) >= 0.0
		&& dot_vec3(cyl->orient, sub_vec3(q2, cyl->pos_hight)) <= 0.0)
	{
		*p = q2;
		return (t[1]);
	}
	return (0);
}

/*
** find a, b, c, for quadratic equation
**
**	v = ray->dir
**	va = cyl->orient
**	d = ray->origin - cyl->position
**
**	v1 = v - (v dot va) * va
**	v2 = d - (d dot va) * va
**
**	a = v1 * v1
**	b = v1 * v2
**	c = v2 * v2 - cyl->radius * cyl->radius
*/

double			intersect_cylinder(t_ray *ray, t_cyl *cyl, t_vec3 *p,
					t_vec3 *normal)
{
	double	abc[3];
	double	t[2];
	double	res;
	t_vec3	v[2];
	t_vec3	tmp;

	v[0] = sub_vec3(ray->dir, mul_vec3(cyl->orient,
			dot_vec3(ray->dir, cyl->orient)));
	tmp = sub_vec3(ray->origin, cyl->pos);
	v[1] = sub_vec3(tmp, mul_vec3(cyl->orient, dot_vec3(tmp, cyl->orient)));
	abc[0] = dot_vec3(v[0], v[0]);
	abc[1] = 2 * dot_vec3(v[0], v[1]);
	abc[2] = dot_vec3(v[1], v[1]) - pow(cyl->radius, 2);
	if ((quadratic_equation(abc[0], abc[1], abc[2], t)) == 0.0)
		return (0);
	if ((res = finite_cylinder(ray, cyl, t, p)) == 0)
		return (0);
	tmp = sub_vec3(*p, cyl->pos);
	*normal = normalize_vec3(sub_vec3(tmp, mul_vec3(cyl->orient,
				dot_vec3(cyl->orient, tmp))));
	*normal = res == t[0] ? *normal : mul_vec3(*normal, -1);
	return (res);
}
