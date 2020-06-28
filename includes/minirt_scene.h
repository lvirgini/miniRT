/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:02:59 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/26 21:44:36 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SCENE_H
# define STRUCT_SCENE_H

# include "minirt.h"

typedef struct s_scene		t_scene;

struct	s_scene
{
	t_camera	*cam;
	t_obj		*objs;
	t_light		*light;
	t_light		*light_ambiant;
};

/*
** Fonctions qui gerent la variable t_scene
*/

t_scene		*malloc_scene(t_camera *cam, t_obj *objs, t_light *light, t_light *ambiant);
void		destroy_scene(t_scene to_destroy);
void		free_scene(t_scene *to_free);

#endif
