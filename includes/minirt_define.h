/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:34:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/24 17:31:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFINE_H
# define MINIRT_DEFINE_H

/*
** Divers utils
*/

typedef	unsigned char	t_uchar;

/*
** RAY_T_MIN : pour eviter que le rayon s'intersecte lui-même
** RAY_T_MAX : pour donner une limite de l'infini
** MAX_REBOUND : rebond maximum de rayon récursif (find mirroir color)
*/

# define RAY_T_MIN		0.00001f
# define RAY_T_MAX		1.0e30f

#endif
