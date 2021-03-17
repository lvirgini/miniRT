/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:19:10 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 14:11:34 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** INCLUDES de librairies officielles
*/

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h> //

/*
** INCLUDES de librairies internes
*/

# include "libft.h"
# include "ft_printf.h"
# include "ft_vector.h"
# include "mlx.h"
# include "mlx_int.h"

/*
** INCLUDES propre a minirt
*/

# include "minirt_matrix_4x4.h"
# include "minirt_define.h"
# include "minirt_color.h"
# include "minirt_image.h"
# include "minirt_objet.h"
# include "minirt_scene.h"
# include "minirt_application.h"
# include "minirt_intersection.h"
# include "minirt_pixel.h"
# include "minirt_parsing.h"
# include "minirt_error.h"
# include "minirt_bonus.h"

// Foncitons a supprimer : fichier print

void		print_vec3(t_vec3	v, char *name);
void		print_color(t_color color);
void		print_tab(char **tab);
void		print_all_obj(t_obj *obj);
void		print_all_cam(t_camera *cam);
void		print_all_lights(t_light *l, t_light *la);
void		print_all_scene(t_scene *scene);

t_color		find_mirroir_color(t_ray ray_incident, t_app *app);
t_color		find_good_color(t_ray *ray, t_color obj_color,
					int texture, t_app *app);



#endif
