/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 11:29:51 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/16 12:00:51 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion d'une t_sphere : creation, malloc et free.
*/

t_sphere	create_sphere(t_vec3 pos, double radius, t_color color, int texture)
{
	t_sphere	sphere;

	sphere.pos = pos;
	sphere.radius = radius;
	sphere.color = color;
	sphere.texture = texture;
	return(sphere);
}

t_sphere	*malloc_sphere(t_vec3 pos, double radius, t_color color, int texture)
{
	t_sphere	*sphere;

		if(!(sphere = malloc(sizeof(t_sphere))))
			minirt_exit_on_error(1);
		*sphere = create_sphere(pos, radius, color, texture);
	return (sphere);
}

void		free_sphere(t_sphere *sphere)
{
	free(sphere);
}


