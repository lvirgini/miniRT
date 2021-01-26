/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 11:29:51 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/07 23:06:43 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion d'une t_sphere : malloc et free.
*/

t_sphere	*malloc_sphere(t_vec3 pos, double radius, t_color col, int texture)
{
	t_sphere	*sphere;

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sphere->pos = pos;
	sphere->radius = radius;
	sphere->color = col;
	sphere->texture = texture;
	return (sphere);
}

void		free_sphere(t_sphere *sphere)
{
	if (sphere)
		free(sphere);
}
