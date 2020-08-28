/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 11:29:51 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/28 11:23:47 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion d'une t_sphere : creation, malloc et free.
*/

t_sphere	*malloc_sphere(t_vec3 pos, double radius, t_color col, int texture)
{
	t_sphere	*sphere;

	if (!(sphere = malloc(sizeof(t_sphere))))
		minirt_exit_on_error(1);
	sphere->pos = pos;
	sphere->radius = radius;
	sphere->color = col;
	sphere->texture = texture;
	return (sphere);
}

void		free_sphere(t_sphere *sphere)
{
	free(sphere);
}
