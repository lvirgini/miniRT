/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix_4x4.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:06:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/24 17:32:59 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATRIX_4X4_H
# define MINIRT_MATRIX_4X4_H

# include "minirt.h"

typedef double	t_m4x4[4][4];

/*
** The notation of each array location
**
** [00 01 02 03]
** [10 11 12 13]
** [20 21 22 23]
** [30 31 32 33]
*/

void	m4x4_get_identity(t_m4x4 m);
void	m4x4_init_zero(t_m4x4 m);
void	m4x4_create(t_m4x4 res, t_vec3 a_b[2], t_vec3 c, t_vec3 d);
void	m4x4_create_invers(t_m4x4 res, t_vec3 a_b[2], t_vec3 c, t_vec3 d);
void	m4x4_mul_nb(t_m4x4 m, double n);
void	m4x4_mul_m4x4(t_m4x4 result, t_m4x4 a, t_m4x4 b);
t_vec3	m4x4_mul_point(t_m4x4 m, t_vec3 v);
t_vec3	m4x4_mul_point_inverse(t_m4x4 m, t_vec3 v);
t_vec3	m4x4_mul_vec(t_m4x4 m, t_vec3 v);
t_vec3	m4x4_mul_vec_inverse(t_m4x4 m, t_vec3 v);

#endif
