/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:15:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/02 15:18:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion des t_ray : creation, malloc et free.
*/

t_ray		create_ray(t_vec3 origin, t_vec3 direction, t_vec3 dir_std)
{
	t_ray	result;

	result.origin = origin;
	result.direction = direction;
	result.dir_std = dir_std;
	result.pt_inter = create_vec3(0, 0, 0);
	result.normal = create_vec3(0, 0, 0);
	result.t = RAY_T_MIN;
	return (result);
}

void		free_ray(t_ray *ray)
{
	free(ray);
}
