/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:40:07 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/04 15:15:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Mise a zero d'une t_scene / cretion sans malloc
*/

t_scene		create_scene(void)
{
	t_scene		scene;

	ft_bzero(&scene, sizeof(scene));
	return (scene);
}

/*
** Creation avec Malloc d'une t_scene
*/

t_scene		*malloc_scene(void)
{
	t_scene		*scene;

	if (!(scene = (t_scene *)malloc(sizeof(scene))))
		return (NULL);
	*scene = create_scene();
	return (scene);
}

/*
** free du contenu d'une t_scene
*/

void		destroy_scene(t_scene to_destroy)
{
	(void)to_destroy;
}

/*
** free de l'integralite d'une t_scene
*/

void		free_scene(t_scene *to_free)
{
	destroy_scene(*to_free);
	free(to_free);
}
