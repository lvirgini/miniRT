/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_t_scene.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:02:59 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/26 11:21:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SCENE_H
# define STRUCT_SCENE_H

# include "minirt.h"

typedef struct s_scene		t_scene;


struct	s_scene
{
	t_camera	**cam;
	t_ambiant	*ambiant;
	t_light		**light;
	t_sphere	**sp;
	t_plane		**pl;
	t_square	**sq;
	t_cyl		**cyl;
	t_triangle	**tri;
};

/*
** Fonctions qui gerent la variable t_scene


t_scene		create_scene(void);
t_scene		*malloc_scene(void);
void		destroy_scene(t_scene to_destroy);
void		free_scene(t_scene *to_free);*/

#endif
