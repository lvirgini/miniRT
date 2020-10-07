/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:15:40 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/07 23:06:34 by lvirgini         ###   ########.fr       */
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
	result.t = RAY_T_MIN;
	return (result);
}

t_ray		*malloc_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	*ray;

	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		return (NULL);
	*ray = create_ray(origin, direction);
	return (ray);
}

void		free_ray(t_ray *ray)
{
	free(ray);
}
