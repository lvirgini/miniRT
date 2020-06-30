/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:50:01 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/29 13:54:56 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

# include "minirt.h"

int			premiers_test(void *param);
int			raytracing_test(void *param);

/*
** Fonctions traitant les events pour les fonctions mlx
*/

int 		handle_key(int key, void **param);

/*
** Fonctions de traitement du file.rt
*/

int			file_checking(int ac, char **av);
int			file_error(char *location, int error);
int			read_file(char *str);
int			line_parser(char *line);
int			line_get_double(char *str, double *result);
int			line_get_int(char *str, int *result);
int			line_get_t_color(char *s, t_color *res);

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
