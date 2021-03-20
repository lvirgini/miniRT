/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:31:58 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/20 11:59:34 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion d'une t_camera : malloc et free.
*/

t_camera	*malloc_camera(double fov, t_vec3 pos, t_vec3 orient)
{
	t_camera	*cam;

	if (!(cam = (t_camera *)malloc(sizeof(t_camera))))
		return (NULL);
	cam->fov = fov == 180 ? 179.9 : fov;
	cam->pos = pos;
	cam->orient = normalize_vec3(orient);
	cam->angle = fov * 0.5 * M_PI / 180;
	cam->next = NULL;
	return (cam);
}

void		free_camera(t_camera *cam, int nb_cam)
{
	t_camera	*tmp;

	while (nb_cam-- > 0)
	{
		tmp = cam->next;
		free(cam);
		cam = tmp;
	}
}
