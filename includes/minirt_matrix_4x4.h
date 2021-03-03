/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix_4x4.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:06:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/03 17:29:14 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATRIX_4X4_H
# define MINIRT_MATRIX_4X4_H

# include "minirt.h"

typedef double	t_m4x4[4][4];

/*
** The notation of each array location
**  m0	m1	m2	m3
** [00 	10 	20	30]
** [01 	11 	21	31]
** [02 	12 	22	32]
*/

void	m4x4_print(t_m4x4 m); //
void	m4x4_create(t_m4x4 res, t_vec3 a_b[2], t_vec3 c, t_vec3 d);
void	m4x4_create_invers(t_m4x4 res, t_vec3 a_b[2], t_vec3 c, t_vec3 d);
void	m4x4_mul_nb(t_m4x4 mat, double n);
t_vec3	m4x4_mul_point(t_m4x4 m, t_vec3 v);
t_vec3	m4x4_mul_vec(t_m4x4 m, t_vec3 v);

#endif
