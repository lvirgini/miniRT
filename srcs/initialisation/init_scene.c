/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:40:07 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/27 11:59:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion des t_scene : creation, malloc, destroy et free.
*/

t_scene		*create_scene(t_camera *cam, t_obj *objs, t_light *light,
						t_light *ambiant)
{
	t_scene		*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		minirt_exit_on_error(1);
	scene->cam = cam;
	scene->objs = objs;
	scene->light = light;
	scene->light_ambiant = ambiant;
	return (scene);
}

t_scene		*malloc_scene(void)
{
	t_scene		*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		minirt_exit_on_error(1);
	ft_bzero(scene, sizeof(scene));
	scene->objs = NULL;
	return (scene);
}

/*
** free du contenu d'une t_scene
*/

void		destroy_scene(t_scene to_destroy)
{
	free_camera(to_destroy.cam);
	free_light(to_destroy.light);
	free_light(to_destroy.light_ambiant);
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
