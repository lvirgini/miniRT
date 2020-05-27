/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:40:07 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/27 15:12:20 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Mise a zero d'une t_scene / cretion sans malloc
*/

t_scene		create_scene(t_camera *cam, t_obj **objs)
{
	t_scene		scene;

	ft_bzero(&scene, sizeof(scene));
	scene.cam = cam;
	scene.objs = objs;
	return (scene);
}

/*
** Creation avec Malloc d'une t_scene
*/

t_scene		*malloc_scene(t_camera *cam, t_obj **objs)
{
	t_scene		*scene;

	if (!(scene = (t_scene *)malloc(sizeof(scene))))
		minirt_error(1);
	*scene = create_scene(cam, objs);
	return (scene);
}

/*
** free du contenu d'une t_scene
*/

void		destroy_scene(t_scene to_destroy)
{
	free_camera(to_destroy.cam);
	free_all_object(to_destroy.objs);
}

/*
** free de l'integralite d'une t_scene
*/

void		free_scene(t_scene *to_free)
{
	destroy_scene(*to_free);
	free(to_free);
}
