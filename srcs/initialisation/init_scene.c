/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:40:07 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/16 11:48:49 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion des t_scene : initialisation et destruction du contenu.
*/

void		init_scene(t_scene *scene)
{
	ft_bzero(scene, sizeof(t_scene));
}

void		destroy_scene(t_scene to_destroy)
{
	free_camera(to_destroy.cam);
	free_light(to_destroy.light);
	free_light(to_destroy.light_ambiant);
	free_all_objects(to_destroy.objs);
}
