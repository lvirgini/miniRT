/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:50:01 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/27 11:43:27 by lvirgini         ###   ########.fr       */
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

int			handle_key(int key, void **param);

/*
** Fonctions de traitement du file.rt
*/

int			file_checking(int ac, char **av);
void		file_error(char *location, int error);
int			read_file(char *str);
/*
** Fonctions qui récupèrent les éléments fournis dans le .rt
*/

int			get_coord_from_line(t_vec3 *result, char *line);
int			get_color_from_line(t_color *result, char *line);
int			get_sphere(char **tab);
int			get_plane(char **tab);
int			get_square(char **tab);
int			get_triangle(char **tab);
int			get_cyl(char **tab);
int			get_resolution(char **tab);
int			get_ambiant_ligth(char **tab);
int			get_light(char **tab);
int			get_camera(char **tab);

/*
** Fonctions pratiques
*/

size_t		tab_len(char **tab);
void		free_tab(char **tab);
void		print_tab(char **tab); //

#endif
