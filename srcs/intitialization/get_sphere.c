/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 11:29:51 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/28 16:56:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere		create_sphere(t_vec3 pos, float radius, t_color color)
{
	t_sphere sphere;

	sphere.pos = pos;
	sphere.radius = radius;
	sphere.color = color;
	return(sphere);
}

t_sphere		*malloc_sphere(t_vec3 pos, float radius, t_color color)
{
	t_sphere *sphere;

		if(!(sphere = malloc(sizeof(t_sphere))))
			minirt_error(1);
		*sphere = create_sphere(pos, radius, color);
	return (sphere);
}

void			free_sphere(t_sphere *sphere)
{
	free(sphere);
}


