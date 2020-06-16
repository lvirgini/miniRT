/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:31:58 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/16 11:55:55 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion d'une t_camera : malloc et free.
*/

t_camera	*malloc_camera(double fov, t_vec3 pos, t_vec3 orient)
{
	t_camera	*cam;

	if (!(cam = malloc(sizeof(t_camera))))
		minirt_exit_on_error(1);
	cam->fov = fov;
	cam->pos = pos;
	cam->orient = ft_normalize_vec3(orient);
	return (cam);
}

void		free_camera(t_camera *cam)
{
	free(cam);
}