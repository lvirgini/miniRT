/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:50:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/14 16:46:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

# include "minirt.h"

typedef	int	(*t_func)(t_app *, char **);

/*
** Fonctions traitant les events pour les fonctions mlx
*/

int			handle_key(int key, t_app *app);

/*
** Fonctions de traitement du file.rt
*/

int			file_checking(int ac, char **av, t_app	*app);
int			read_file(char *str, t_app *app);
/*
** Fonctions qui récupèrent les éléments fournis dans le .rt
*/

int			get_resolution(t_app *app, char **tab);
int			get_sphere(t_app *app, char **tab);
int			get_plane(t_app *app, char **tab);
int			get_square(t_app *app, char **tab);
int			get_triangle(t_app *app, char **tab);
int			get_cyl(t_app *app, char **tab);
int			get_ambiant_ligth(t_app *app, char **tab);
int			get_light(t_app *app, char **tab);
int			get_camera(t_app *app, char **tab);
/*
** Fonctions pratiques
*/

size_t		tab_len(char **tab);
void		free_tab(char **tab);
int			check_in_range(t_vec3 vec, double min, double max);
int			get_coord_from_line(t_vec3 *result, char *line);
int			get_color_from_line(t_color *result, char *line);
int			save_obj_in_scene(int type, void *shape);

#endif
