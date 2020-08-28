/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:13:14 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/28 11:50:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Creation par malloc d'un square
*/

t_square	*malloc_square(t_vec3 pos_orient[2], double h, t_color col,
					int texture)
{
	t_square	*square;

	if (!(square = malloc(sizeof(t_square))))
		minirt_exit_on_error(1);
	square->pos = pos_orient[0];
	square->orient = pos_orient[1];
	square->hight = h;
	square->color = col;
	square->texture = texture;
	return (square);
}

void		free_square(t_square *square)
{
	free(square);
}
