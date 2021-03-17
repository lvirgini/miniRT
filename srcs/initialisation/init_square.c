/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:13:14 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/16 15:08:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion d'un t_square : malloc et free
*/

t_square	*malloc_square(t_vec3 pos_orient[2], double h, t_color col,
					int texture)
{
	t_square	*square;

	if (!(square = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	square->pos = pos_orient[0];
	square->normal = normalize_vec3(pos_orient[1]);
	square->hight = h;
	square->color = col;
	square->texture = texture;
	return (square);
}

void		free_square(t_square *square)
{
	if (square)
		free(square);
}
