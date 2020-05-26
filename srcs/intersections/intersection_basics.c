/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_basics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:24:37 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/26 12:55:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** En partant de l'origin du rayon, retourne l'emplacement du point lorsque
** direction * t.
** return = origin + (direction * t)
*/

t_vec3		ray_calculate_t(t_ray ray, double t)
{
	return (ft_add_vec3(ray.origin, ft_mul_vec3(ray.direction, t)));

}