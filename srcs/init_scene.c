/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:40:07 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/01 15:50:24 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene		create_scene(void)
{
	t_scene scene;
	ft_bzero(&scene, sizeof(scene));
	return (scene);
}

t_scene		*malloc_scene(void)
{
	t_scene *scene;

	if (!(scene = (t_scene *)malloc(sizeof(scene))))
		return (NULL);
	scene = create_scene;
	return (scene);
}

void		destroy_scene(t_scene to_destroy)
{
	(void)to_destroy;
}
void		free_scene(t_scene *to_free)
{
	destroy_scene(*to_free);
	free(to_free);
}