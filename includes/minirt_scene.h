/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:02:59 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/27 10:55:05 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_SCENE_H
# define MINIRT_SCENE_H

# include "minirt.h"

typedef struct s_scene	t_scene;

struct		s_scene
{
	t_camera	*cam;
	t_light		*light_ambiant;
	t_light		*light;
	t_obj		*objs;
};

/*
** Fonctions qui gerent la variable t_scene
*/

t_scene		*malloc_scene();
void		destroy_scene(t_scene to_destroy);
void		free_scene(t_scene *to_free);

#endif
