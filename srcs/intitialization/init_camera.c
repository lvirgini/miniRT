/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:31:58 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/29 10:32:59 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



t_camera		*malloc_camera(double fov, t_vec3 pos,	t_vec3 orient)
{
	t_camera *cam;

	if (!(cam = malloc(sizeof(t_camera))))
		minirt_error(1);
	cam->fov = fov;
	cam->pos = pos;
	cam->orient = ft_normalize_vec3(orient);
	return (cam);
}

void			free_camera(t_camera *cam)
{
	free(cam);
}