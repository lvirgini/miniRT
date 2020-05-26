/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:15:40 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/26 12:40:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray		create_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray result;

	result.origin = origin;
	result.direction = direction;
	result.tmax = RAY_T_MAX;
	return(result);
}

t_ray		*malloc_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray *ray;

	if (!(ray = malloc(sizeof(ray))))
		return (NULL);
	*ray = create_ray(origin, direction);
	return(ray);
}

void		free_ray(t_ray *ray)
{
	free(ray);
}
