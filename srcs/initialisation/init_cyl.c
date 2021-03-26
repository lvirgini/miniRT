/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cyl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:33:24 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/26 10:44:55 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** For caps in the TOP && Bottom cylinder if bonus
*/

static t_disc	*malloc_disc(t_cyl *cyl, t_vec3 pos)
{
	t_disc	*d;

	if (!(d = (t_disc *)malloc(sizeof(t_disc))))
		return (NULL);
	d->pos = pos;
	d->normal = cyl->orient;
	d->radius2 = cyl->radius2;
	d->texture = cyl->texture;
	d->color = cyl->color;
	return (d);
}

int				malloc_caps_cylinder(t_cyl *cyl, t_app *app)
{
	if (!(cyl->disc = malloc_disc(cyl, cyl->pos))
		|| (!(cyl->disc2 = malloc_disc(cyl, cyl->pos_hight)))
		|| save_obj_in_scene(app->scene, DISC, cyl->disc) != 0
		|| save_obj_in_scene(app->scene, DISC, cyl->disc2) != 0)
		exit_free_minirt(app, "CYLINDER_CAPS", ERR_MALLOC);
	return (0);
}

t_cyl			*malloc_cyl(t_vec3 pos_orient[2], double radius_hight[2],
				t_color col, int texture)
{
	t_cyl	*cyl;

	if (!(cyl = (t_cyl *)malloc(sizeof(t_cyl))))
		return (NULL);
	cyl->pos = pos_orient[0];
	cyl->orient = normalize_vec3(pos_orient[1]);
	cyl->radius2 = pow(radius_hight[0], 2);
	cyl->hight = radius_hight[1];
	cyl->pos_hight = add_vec3(cyl->pos, mul_vec3(cyl->orient, cyl->hight));
	cyl->color = col;
	cyl->texture = texture;
	cyl->disc = NULL;
	cyl->disc2 = NULL;
	return (cyl);
}

void			free_cyl(t_cyl *cyl)
{
	if (cyl)
	{
		if (cyl->disc)
			free(cyl->disc);
		if (cyl->disc2)
			free(cyl->disc2);
		free(cyl);
	}
}
