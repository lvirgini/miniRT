/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_scene.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:02:59 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/17 17:45:56 by lvirgini         ###   ########.fr       */
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
	double		total_intens;
};

/*
** Fonctions qui gerent la variable t_scene
*/

void		init_scene(t_scene *scene);
void		destroy_scene(t_scene to_destroy);

#endif
