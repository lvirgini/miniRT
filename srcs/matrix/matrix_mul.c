/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:32:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/08 10:10:03 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	m4x4_print(t_m4x4 m) //
{
	printf("[%f %f %f %f]\n", m[0][0], m[0][1], m[0][2], m[0][3]);
	printf("[%f %f %f %f]\n", m[1][0], m[1][1], m[1][2], m[1][3]);
	printf("[%f %f %f %f]\n", m[2][0], m[2][1], m[2][2], m[2][3]);
	printf("[%f %f %f %f]\n\n", m[3][0], m[3][1], m[3][2], m[3][3]);
}

/*
** Multiplication all matrix by nb
*/

void	m4x4_mul_nb(t_m4x4 m, double n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m[i][j] *= n;
	}
}

/*
** Multiplication between two matrix. a first.
*/

void		m4x4_mul_m4x4(t_m4x4 result, t_m4x4 a, t_m4x4 b)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			result[i][j] = a[i][0] * b[0][j]
						+ a[i][1] * b[1][j]
						+ a[i][2] * b[2][j]
						+ a[i][3] * b[3][j];
		}
	}
}
