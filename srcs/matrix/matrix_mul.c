/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:32:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 14:42:17 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	m4x4_mul_m4x4(t_m4x4 result, t_m4x4 a, t_m4x4 b)
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
