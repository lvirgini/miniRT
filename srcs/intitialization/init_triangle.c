/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:26:30 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/30 16:00:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion d'un t_triangle
*/

t_triangle	*malloc_triangle(t_vec3 pos[3], t_color color, int texture)
{
	t_triangle	*triangle;
	t_vec3 		v0;
	t_vec3 		v1;

	if (!(triangle = malloc(sizeof(t_triangle))))
		minirt_exit_on_error(1);
	triangle->pos1 = pos[0];
	triangle->pos2 = pos[1];
	triangle->pos3 = pos[2];
	triangle->color = color;
	triangle->texture = texture;
	v0 = ft_sub_vec3(triangle->pos2, triangle->pos1);
	v1 = ft_sub_vec3(triangle->pos3, triangle->pos1);
	triangle->normal = ft_normalize_vec3(ft_cross_vec3(v0, v1));
	return(triangle);
}

void		free_triangle(t_triangle *triangle)
{
	free(triangle);
}