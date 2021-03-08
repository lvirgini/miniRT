/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:26:30 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/08 22:35:17 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion d'un t_triangle
*/

t_triangle	*malloc_triangle(t_vec3 pos[3], t_color color, int texture)
{
	t_triangle	*t;

	if (!(t = (t_triangle *)malloc(sizeof(t_triangle))))
		return (NULL);
	t->a = pos[0];
	t->color = color;
	t->texture = texture;
	t->ab = sub_vec3(pos[1], t->a);
	t->ac = sub_vec3(pos[2], t->a);
	t->normal = normalize_vec3(cross_vec3(t->ab, t->ac));
	return (t);
}

void		free_triangle(t_triangle *triangle)
{
	free(triangle);
}
