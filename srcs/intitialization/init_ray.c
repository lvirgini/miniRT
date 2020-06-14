/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:15:40 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/13 12:15:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray		create_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray result;

	result.origin = origin;
	result.direction = direction;
	result.pt_intersection = create_vec3(0, 0, 0);
	result.normal = create_vec3(0, 0, 0);
	result.tmax = 50000;
	return(result);
}

t_ray		*malloc_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray *ray;
	

	if (!(ray = malloc(sizeof(t_ray))))
		minirt_error(1);
	*ray = create_ray(origin, direction);
		printf("OK\n");
	return(ray);
}

void		free_ray(t_ray *ray)
{
	free(ray);
}
