/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:19:10 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/07 23:03:29 by lvirgini         ###   ########.fr       */
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

# include "minirt_define.h"
# include "minirt_color.h"
# include "minirt_image.h"
# include "minirt_objet.h"
# include "minirt_scene.h"
# include "minirt_application.h"
# include "minirt_intersection.h"
# include "minirt_drawing.h"
# include "minirt_parsing.h"

/*
** Fonctions a ranger
*/

int			malloc_error(void);
int			file_error(char *location, int error);
void		exit_free_minirt(t_app *app, int if_error);
int			handle_mouse(int button, int x, int y, void *param);
int			generate_raytracing(void *param);
int			generate_content(t_app *app);
int			run_application(t_app *app);

//
// Foncitons a supprimer : fichier print
//

void		print_vec3(t_vec3	v, char *name);
void		print_color(t_color color);
void		print_tab(char **tab);
void		print_all_obj(t_obj *obj);
void		print_all_cam(t_camera *cam);
void		print_all_lights(t_light *l, t_light *la);
void		print_all_scene(t_scene *scene);

extern		t_scene	*g_scene;

#endif
