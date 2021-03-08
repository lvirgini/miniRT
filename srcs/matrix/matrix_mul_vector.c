/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mul_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:36:37 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/08 10:13:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 		mat		 *	point 	=
** [00 01 02 03]	[x]	 	x*00 + y*10 + z*20 + 30
** [10 11 12 13]    [y]		x*01 + y*11 + z*21 + 31
** [20 21 22 23]	[z]		x*02 + y*12 + z*22 + 32
** [30 31 32 33]	[1]		x*03 + y*13 + z*23 + 33
*/

t_vec3		m4x4_mul_point_inverse(t_m4x4 m, t_vec3 v)
{
	double	x;
	double	y;
	double	z;
	double	w;

	x = (v.x * m[0][0]) + (v.y * m[1][0]) + (v.z * m[2][0]) + m[3][0];
	y = (v.x * m[0][1]) + (v.y * m[1][1]) + (v.z * m[2][1]) + m[3][1];
	z = (v.x * m[0][2]) + (v.y * m[1][2]) + (v.z * m[2][2]) + m[3][2];
	w = (v.x * m[0][3]) + (v.y * m[1][3]) + (v.z * m[2][3]) + m[3][3];
	if (w != 1 && w != 0)
	{
		x /= w;
		y /= w;
		z /= w;
	}
	return (create_vec3(x, y, z));
}

/*
** 		mat		 *	point 	=
** [00 01 02 03]	[x]	 	x*00 + y*01 + z*02 + 03
** [10 11 12 13]    [y]		x*10 + y*11 + z*12 + 13
** [20 21 22 23]	[z]		x*20 + y*21 + z*22 + 23
** [30 31 32 33]	[1]		x*30 + y*31 + z*32 + 33
*/

t_vec3		m4x4_mul_point(t_m4x4 m, t_vec3 v)
{
	double	x;
	double	y;
	double	z;
	double	w;

	x = (v.x * m[0][0]) + (v.y * m[0][1]) + (v.z * m[0][2]) + m[0][3];
	y = (v.x * m[1][0]) + (v.y * m[1][1]) + (v.z * m[1][2]) + m[1][3];
	z = (v.x * m[2][0]) + (v.y * m[2][1]) + (v.z * m[2][2]) + m[2][3];
	w = (v.x * m[3][0]) + (v.y * m[3][1]) + (v.z * m[3][2]) + m[3][3];
	if (w != 1 && w != 0)
	{
		x /= w;
		y /= w;
		z /= w;
	}
	return (create_vec3(x, y, z));
}

/*
** 		mat		 *	vector 	=
** [00 01 02 03]	[x]	 	x*00 + y*01 + z*02 + 03
** [10 11 12 13]    [y]		x*10 + y*11 + z*12 + 13
** [20 21 22 23]	[z]		x*20 + y*21 + z*22 + 23
*/

t_vec3		m4x4_mul_vec(t_m4x4 m, t_vec3 v)
{
	double	x;
	double	y;
	double	z;

	x = (v.x * m[0][0]) + (v.y * m[0][1]) + (v.z * m[0][2]) + m[0][3];
	y = (v.x * m[1][0]) + (v.y * m[1][1]) + (v.z * m[1][2]) + m[1][3];
	z = (v.x * m[2][0]) + (v.y * m[2][1]) + (v.z * m[2][2]) + m[2][3];
	return (create_vec3(x, y, z));
}

/*
** 		mat		 *	vector	=
** [00 01 02 03]	[x]	 	x*00 + y*10 + z*20 + 30
** [10 11 12 13]    [y]		x*01 + y*11 + z*21 + 31
** [20 21 22 23]	[z]		x*02 + y*12 + z*22 + 32
*/

t_vec3		m4x4_mul_vec_inverse(t_m4x4 m, t_vec3 v)
{
	double	x;
	double	y;
	double	z;
	double	w;

	x = (v.x * m[0][0]) + (v.y * m[1][0]) + (v.z * m[2][0]) + m[3][0];
	y = (v.x * m[0][1]) + (v.y * m[1][1]) + (v.z * m[2][1]) + m[3][1];
	z = (v.x * m[0][2]) + (v.y * m[1][2]) + (v.z * m[2][2]) + m[3][2];
	return (create_vec3(x, y, z));
}
