/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:26:30 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/07 23:07:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion d'un t_triangle
*/

t_triangle	*malloc_triangle(t_vec3 pos[3], t_color color, int texture)
{
	t_triangle	*triangle;

	if (!(triangle = (t_triangle *)malloc(sizeof(t_triangle))))
		return (NULL);
	triangle->a = pos[0];
	triangle->b = pos[1];
	triangle->c = pos[2];
	triangle->color = color;
	triangle->texture = texture;
	triangle->ab = sub_vec3(triangle->b, triangle->a);
	triangle->ac = sub_vec3(triangle->c, triangle->a);
	triangle->bc = sub_vec3(triangle->c, triangle->b);
	triangle->normal = normalize_vec3(cross_vec3(triangle->ab, triangle->ac));
	triangle->norme2_ab = norme2_vec3(triangle->ab);
	triangle->norme2_ac = norme2_vec3(triangle->ac);
	triangle->dot_ab_ac = dot_vec3(triangle->ab, triangle->ac);
	triangle->determinant =  (triangle->norme2_ab * triangle->norme2_ac) - (triangle->dot_ab_ac * triangle->dot_ab_ac);
	if(!(triangle->plane = malloc_plane(triangle->a, triangle->ab, triangle->color, 0)))
		return (NULL);
	return (triangle);
}

void		free_triangle(t_triangle *triangle)
{
	free_plane(triangle->plane);
	free(triangle);
}
