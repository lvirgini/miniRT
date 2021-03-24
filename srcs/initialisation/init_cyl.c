/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cyl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:33:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/24 16:41:12 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cyl	*malloc_cyl(t_vec3 pos_orient[2], double radius_hight[2], t_color col,
				int texture)
{
	t_cyl	*cyl;

	if (!(cyl = (t_cyl *)malloc(sizeof(t_cyl))))
		return (NULL);
	cyl->pos = pos_orient[0];
	cyl->orient = normalize_vec3(pos_orient[1]);
	cyl->radius = radius_hight[0];
	cyl->hight = radius_hight[1];
	cyl->pos_hight = add_vec3(cyl->pos, mul_vec3(cyl->orient, cyl->hight));
	cyl->color = col;
	cyl->texture = texture;
	return (cyl);
}

void	free_cyl(t_cyl *cyl)
{
	if (cyl)
		free(cyl);
}
