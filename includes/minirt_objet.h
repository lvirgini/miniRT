/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_objet.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:56:37 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/30 15:03:58 by lvirgini         ###   ########.fr       */
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
# define TEXTURE_REFLE

typedef	int					(*t_func)(char *);

typedef struct s_obj		t_obj;

typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_square		t_square;
typedef struct s_cyl		t_cyl;
typedef struct s_triangle	t_triangle;

/*
** Defini le nom t_point pour diférencier un point d'un vecteur. a voir si ca
** pose probleme par la suite.
*/

typedef	struct s_vec2		t_point2;
typedef	struct s_vec3		t_point3;
typedef struct s_ray		t_ray;

/*
** Rayon avec un point origine, un vecteur de direction, si intersection : 
** pt_intersection sur un objet, et la normal a ce pt d'intersection.
*/

struct	s_ray
{
	t_point3	origin;
	t_vec3		direction;
	t_vec3		pt_intersection;
	t_vec3		normal;
	double		t;
	double		tmax;
};

/*
** type compris entre 1 et 5 et correspond au une forme.
** voir defines plus haut.
** *shape est un pointeur sur une t_ forme.
*/

struct s_obj
{
	int		type;
	void	*shape;
	t_obj 	*next;
};


struct	s_camera
{
	double		fov; //compris entre 0 et 180
	t_vec3		pos;
	t_vec3		orient;
};

struct	s_light
{
	double		ratio;
	t_vec3		pos;
	t_color		color;
};

struct	s_sphere
{
	t_vec3		pos;
	double		radius;
	t_color		color;
	int			texture;
};

struct	s_plane
{
	t_vec3		pos;
	t_vec3		normal;
	t_color		color;
	int			texture;
};

struct	s_square
{
	t_vec3		pos;
	t_vec3		orient;
	float		hight;
	t_color		color;
};

struct	s_cyl
{
	t_vec3		pos;
	t_vec3		orient;
	t_color		color;
	float		hight;
	float		diameter;
};

struct	s_triangle
{
	t_vec3		pos1;
	t_vec3		pos2;
	t_vec3		pos3;
	t_vec3		normal;
	t_color		color;
	int			texture;
};

/*
** Fonctions initialisation de la liste d'object
*/

t_obj		create_object(int type, void *shape);
t_obj 		*malloc_object(int type, void *shape);
void		destroy_object(t_obj obj);
void		free_object(t_obj *obj);
void		free_all_object(t_obj *obj);

/*
** Fonctions initialisation des objets
*/

t_sphere	create_sphere(t_vec3 pos, double radius, t_color color, int texture);
/*
t_square	create_square(t_vec3 pos, t_vec3 orient, double hight, t_color color);
t_cyl		create_cylindre(t_vec3 pos, t_vec3 orient, double hight, double diameter, t_color color);
t_triangle	create_triange(t_vec3 pos1, t_vec3 pos2, t_vec3 pos3, t_color color);*/


t_sphere	*malloc_sphere(t_vec3 pos, double radius, t_color color, int texture);
t_plane		*malloc_plane(t_vec3 pos, t_vec3 orient, t_color color, int texture);/*
t_square	malloc_square(t_vec3 pos, t_vec3 orient, double hight, t_color color);
t_cyl		malloc_cylindre(t_vec3 pos, t_vec3 orient, double hight, double diameter, t_color color);*/
t_triangle		*malloc_triangle(t_vec3 pos[3], t_color color, int texture);


void		free_sphere(t_sphere *sphere);
void		free_plane(t_plane *plane);/*
void		free_square(t_square *square);
void		free_cylindre(t_cyl *cylindre)*/
void		free_triange(t_triangle *triange);


t_camera	*malloc_camera(double fov, t_vec3 pos, t_vec3 orient);
void		free_camera(t_camera *cam);


t_light		create_light(t_vec3 pos, double ratio, t_color color);
t_light		*malloc_light(t_vec3 pos, double ratio, t_color color);
void		free_light(t_light *light);


t_color		find_pixel_color(t_obj *obj, t_ray *ray_origin);
#endif
