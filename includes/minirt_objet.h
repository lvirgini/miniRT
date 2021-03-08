/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_objet.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:56:37 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/08 22:35:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_OBJET_H
# define MINIRT_OBJET_H

# include "minirt.h"

# define SPHERE		1
# define PLANE		2
# define SQUARE		3
# define CYLINDRE	4
# define TRIANGLE	5

# define TEXTURE_DIFFUS		0
# define TEXTURE_MIRROIR	1
# define TEXTURE_REFLEX		2

typedef struct s_obj		t_obj;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_square		t_square;
typedef struct s_cyl		t_cyl;
typedef struct s_triangle	t_triangle;
typedef struct s_disc		t_disc;

/*
** type compris entre 1 et 5 et correspond au une forme.
** voir defines plus haut.
** *shape est un pointeur sur une t_ forme.
*/

struct		s_obj
{
	int		type;
	void	*shape;
	t_obj	*next;
};

struct		s_camera
{
	double		fov;
	double		angle;
	t_vec3		pos;
	t_vec3		orient;
	t_camera	*next;
};

struct		s_light
{
	double		ratio;
	t_vec3		pos;
	t_color		color;
	t_light		*next;
};

struct		s_sphere
{
	t_vec3		pos;
	double		radius;
	t_color		color;
	int			texture;
};

struct		s_plane
{
	t_vec3		pos;
	t_vec3		normal;
	t_color		color;
	int			texture;
};

struct		s_disc
{
	t_vec3		pos;
	t_vec3		normal;
	t_color		color;
	int			texture;
	double		radius2;
};

struct		s_square
{
	t_vec3		pos;
	t_vec3		orient;
	double		hight;
	t_color		color;
	int			texture;
};

struct		s_cyl
{
	t_vec3		pos;
	t_vec3		orient;
	t_color		color;
	double		hight;
	double		radius;
	int			texture;
};

struct		s_triangle
{
	t_vec3		a;
	t_vec3		ab;
	t_vec3		ac;
	t_plane		*plane;
	t_vec3		normal;
	t_color		color;
	int			texture;
};

/*
** Fonctions initialisation de la liste d'object
*/

t_obj		*malloc_object(int type, void *shape);
void		free_object_shape(void *shape, int type);
void		free_all_objects(t_obj *obj);

/*
** Fonctions initialisation malloc des objets
*/

t_sphere	*malloc_sphere(t_vec3 pos, double radius, t_color col, int texture);
t_plane		*malloc_plane(t_vec3 pos, t_vec3 orient, t_color col, int texture);
t_triangle	*malloc_triangle(t_vec3 pos[3], t_color col, int texture);
t_square	*malloc_square(t_vec3 pos_orient[2], double h, t_color col,
				int texture);
t_cyl		*malloc_cyl(t_vec3 pos_orient[2], double radius_hight[2],
				t_color col, int texture);

/*
** Fonctions free des objs
*/

void		free_sphere(t_sphere *sphere);
void		free_plane(t_plane *plane);
void		free_triangle(t_triangle *triange);
void		free_square(t_square *square);
void		free_cyl(t_cyl *cyl);

/*
** Camera
*/

t_camera	*malloc_camera(double fov, t_vec3 pos, t_vec3 orient);
void		free_camera(t_camera *cam, int nb_cam);

/*
** Light
*/

t_light		*malloc_light(t_vec3 pos, double ratio, t_color color);
void		free_light(t_light *light);

/*
** Fonctions utiles
*/

t_obj		*find_last_obj(t_obj *obj);

#endif
