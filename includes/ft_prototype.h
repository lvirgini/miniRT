/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:50:01 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/07 15:40:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPE_H
# define FT_PROTOTYPE_H

# include "minirt.h"

/*
** Fonctions de traitement du file.rt
*/

int			file_checking(int ac, char **av);
int			file_error(char *location, int error);
int			read_file(char *str);
int			line_parser(char *line);
int			line_get_float(char *str, float *result);
int			line_get_int(char *str, int *result);
int			line_get_t_color(char *s, t_color *res);

/*
** Fonction qui gerent la variable t_app
*/

t_app		create_application(void);
t_app		*malloc_application(void);
void		destroy_application(t_app to_destroy);
void		free_application(t_app *to_free);

/*
** Fonctions qui gerent les variable t_scene
*/

t_scene		create_scene(void);
t_scene		*malloc_scene(void);
void		destroy_scene(t_scene to_destroy);
void		free_scene(t_scene *to_free);

/*
** Fonctions qui récupèrent les éléments fournis dans le .rt
*/

int			get_sphere(char *str);
int			get_plane(char *str);
int			get_square(char *str);
int			get_triangle(char *str);
int			get_cyl(char *str);
int			get_resolution(char *str);
int			get_ambiant_ligth(char *str);
int			get_light(char *str);
int			get_camera(char *str);

#endif
