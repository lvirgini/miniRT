/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:15:40 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/27 11:58:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion des t_ray : creation, malloc et free.
*/

t_ray		create_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	result;

	result.origin = origin;
	result.direction = direction;
	result.pt_intersection = create_vec3(0, 0, 0);
	result.normal = create_vec3(0, 0, 0);
	result.tmax = RAY_T_MAX;
	result.t = RAY_T_MIN;
	return (result);
}

t_ray		*malloc_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	*ray;

	if (!(ray = malloc(sizeof(t_ray))))
		minirt_exit_on_error(1);
	*ray = create_ray(origin, direction);
	return (ray);
}

void		free_ray(t_ray *ray)
{
	free(ray);
}
