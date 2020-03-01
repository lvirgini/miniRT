/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:50:01 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/01 17:57:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPE_H
# define FT_PROTOTYPE_H

# include "minirt.h"

/*
** Fonctions de traitement du file.rt
*/

int			file_checking(int ac, char **av);
int			file_type(char *str);
int			file_error(int error);
int			read_file(char *str);
int			line_parser(char *line);
int			index_set(char *s);
t_func		*set_functions(t_func *f);
int			check_file_is_complete(void);

/*
** Fonction qui gerent la variable t_app
*/

t_app	create_application(void);
t_app	 *malloc_application(void);
void	destroy_application(t_app to_destroy);
void 	free_application(t_app *to_free);

/*
** Fonctions qui gerent les variable t_scene
*/

t_scene		create_scene(void);
t_scene		*malloc_scene(void);
void		destroy_scene(t_scene to_destroy);
void		free_scene(t_scene *to_free);

/*
** Fonctions qui creent une donnee d'un objet
*/

int 		create_sphere(char *str);
int 		create_plane(char *str);
int 		create_square(char *str);
int 		create_triangle(char *str);
int 		create_cyl(char *str);

/*
** Fonctions qui creent les elements indispensables d'une scene.
*/

int 		create_resolution(char *str);
int 		create_ambiant_ligth(char *str);
int 		create_light(char *str);
int 		create_camera(char *str);


#endif