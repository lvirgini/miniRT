/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:31:58 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/07 22:23:21 by lvirgini         ###   ########.fr       */
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
	cam->fov = fov;
	cam->pos = pos;
	cam->orient = orient;
	return (cam);
}

void		free_camera(t_camera *cam)
{
	if (cam)
		free(cam);
}
