/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:02:59 by lvirgini          #+#    #+#             */
/*   Updated: 2020/09/27 13:56:42 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_SCENE_H
# define MINIRT_SCENE_H

# include "minirt.h"

typedef struct s_scene	t_scene;

struct		s_scene
{

	t_camera	*cam;
	int			nb_obj;  //// ICI CEST L'ADRESSE DE LA SCENE WHY ??????????
	t_light		*light_ambiant;
	t_light		*light;
	t_obj		*objs;
};

/*
** Fonctions qui gerent la variable t_scene
*/

t_scene		*create_scene(t_camera *cam, t_obj *objs, t_light *light,
						t_light *ambiant);
t_scene		*malloc_scene(void);
void		destroy_scene(t_scene to_destroy);
void		free_scene(t_scene *to_free);

#endif
