/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:32:56 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/30 15:05:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion d'une t_sphere : creation, malloc et free.
*/

t_plane		*malloc_plane(t_vec3 pos, t_vec3 orient, t_color color, int texture)
{
	t_plane		*plane;

	if(!(plane = malloc(sizeof(t_plane))))
		minirt_exit_on_error(1);
	plane->pos = pos;
	plane->normal = ft_normalize_vec3(ft_add_vec3(pos, orient));
	plane->color = color;
	plane->texture = texture;
	return (plane);
}

void		free_plane(t_plane *plane)
{
	free(plane);
}
