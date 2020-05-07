/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prototype.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:50:01 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/07 15:28:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROTOTYPE_H
# define FT_PROTOTYPE_H

# include "minirt.h"

//
int			premiers_test(void *param);


/*
** Fonctions traitant les events pour les fonctions mlx
*/

//int			 handle_key(int key, void *param);

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

t_app		create_application(int x, int y, char *title, void *test);
t_app		*malloc_application(int x, int y, char *title, void *test);
void		destroy_application(t_app to_destroy);
void		free_application(t_app *to_free);
void		application_create_content(void);
void		clear_application_int(int color);

/*
** Fonctions qui gerent la variable t_image
*/

t_image		create_image(int x, int y);
t_image		*malloc_image(int x, int y);
void		destroy_image(t_image to_destroy);
void		free_image(t_image *to_free);

/*
** Fonctions qui gerent la variable t_scene
*/

t_scene		create_scene(void);
t_scene		*malloc_scene(void);
void		destroy_scene(t_scene to_destroy);
void		free_scene(t_scene *to_free);

/*
**	Fonctions qui gèrent les couleurs
*/

t_color		create_color(uchar r, uchar g, uchar b, uchar a);
t_color		*malloc_color(uchar r, uchar g, uchar b, uchar a);
void		free_color(t_color *to_free);
int			fuze_color_int(int actual, int to_add);
t_color 	fuze_color(t_color actual, t_color to_add);

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

/*
** Fonctions de gestion du dessin
*/

void 		draw_rectangle_int(t_image *image, t_vec2 pos, t_vec2 size, 									int color);

void 		draw_rectangle(t_vec2 pos, t_vec2 size, t_color color);
void 		draw_rectangle_in_image(t_image *image, t_vec2 pos, t_vec2 size, t_color color);
void		clear_application(t_color color);
void 		put_pixel(t_image *image, int x, int y, t_color color);

/*
**	Fonctions vectorielles
*/



#endif
