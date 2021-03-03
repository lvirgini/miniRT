/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:36:56 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/03 16:36:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**	matrix =
**	[ax	ay	az	0]
**	[bx	by	bz	0]
**	[cx	cy	cz	0]
**	[dx	dy	dz	1]
*/

void	m4x4_create(t_m4x4 res, t_vec3 a_b[2], t_vec3 c, t_vec3 d)
{
	t_vec3 a;
	t_vec3 b;

	a = a_b[0];
	b = a_b[1];
	res[0][0] = a.x;
	res[0][1] = a.y;
	res[0][2] = a.z;
	res[0][3] = 0;
	res[1][0] = b.x;
	res[1][1] = b.y;
	res[1][2] = b.z;
	res[1][3] = 0;
	res[2][0] = c.x;
	res[2][1] = c.y;
	res[2][2] = c.z;
	res[2][3] = 0;
	res[3][0] = d.x;
	res[3][1] = d.y;
	res[3][2] = d.z;
	res[3][3] = 1;
}

/*
**	matrix =
** [ax	bx	cx	dx]
** [ay 	by 	cy	dy]
** [az	bz	cz	dz]
** [0	0	0	1 ]
*/

void	m4x4_create_invers(t_m4x4 res, t_vec3 a_b[2], t_vec3 c, t_vec3 d)
{
	t_vec3 a;
	t_vec3 b;

	a = a_b[0];
	b = a_b[1];
	res[0][0] = a.x;
	res[0][1] = b.x;
	res[0][2] = c.x;
	res[0][3] = d.x;
	res[1][0] = a.y;
	res[1][1] = b.y;
	res[1][2] = c.y;
	res[1][3] = d.y;
	res[2][0] = a.z;
	res[2][1] = b.z;
	res[2][2] = c.z;
	res[2][3] = d.z;
	res[3][0] = 0;
	res[3][1] = 0;
	res[3][2] = 0;
	res[3][3] = 1;
}
