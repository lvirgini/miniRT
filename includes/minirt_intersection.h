/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_intersection.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:06:39 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/26 12:24:01 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_INTERSECTION_H
# define MINIRT_INTERSECTION_H

# include "minirt.h"

/*
** RAY_T_MIN : pour eviter que le rayon s'intersecte lui-même
** RAY_T_MAX : pour donner une limite de l'infini
*/

# define RAY_T_MIN	0.0001f
# define RAY_T_MAX	1.0e30f

/*
** Defini le nom t_point pour diférencier un point d'un vecteur. a voir si ca
** pose probleme par la suite.
*/

typedef	struct s_vec2		t_point2;
typedef	struct s_vec3		t_point3;
typedef struct s_ray		t_ray;

struct	s_ray
{
	t_point3	origin;
	t_vec3		direction;
	float		tmax;
};


t_ray		create_ray(t_vec3 origin, t_vec3 direction);
t_ray		*malloc_ray(t_vec3 origin, t_vec3 direction);
void		free_ray(t_ray *ray);
t_vec3		point_ray_plus_f(double point_f)

#endif
