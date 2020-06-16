/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_objet.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:56:37 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/16 11:42:33 by lvirgini         ###   ########.fr       */
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

# define TEXTURE_MIRROIR 1

typedef	int					(*t_func)(char *);

typedef struct s_obj		t_obj;

typedef struct s_camera		t_camera;
typedef struct s_ambiant	t_ambiant;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_square		t_square;
typedef struct s_cyl		t_cyl;
typedef struct s_triangle	t_triangle;

/*
** RAY_T_MIN : pour eviter que le rayon s'intersecte lui-même
** RAY_T_MAX : pour donner une limite de l'infini
*/

# define RAY_T_MIN	0.0001f
# define RAY_T_MAX	1.0e30f

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

struct	s_ambiant
{
	float		ratio;
	t_color		color;
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
	t_vec3		orient;
	t_vec3		normal;
	t_color		color;
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

struct	s_triange
{
	t_vec3		pos1;
	t_vec3		pos2;
	t_vec3		pos3;
	t_color		color;
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

t_sphere	create_sphere(t_vec3 pos, double rayon, t_color color, int texture);
/*t_plane	create_plane(t_vec3 pos, t_vec3 orient, t_color color);
t_square	create_square(t_vec3 pos, t_vec3 orient, double hight, t_color color);
t_cyl		create_cylindre(t_vec3 pos, t_vec3 orient, double hight, double diameter, t_color color);
t_triangle	create_triange(t_vec3 pos1, t_vec3 pos2, t_vec3 pos3, t_color color);*/


t_sphere	*malloc_sphere(t_vec3 pos, double rayon, t_color color, int texture);/*
t_plane		malloc_plane(t_vec3 pos, t_vec3 orient, t_color color);
t_square	malloc_square(t_vec3 pos, t_vec3 orient, double hight, t_color color);
t_cyl		malloc_cylindre(t_vec3 pos, t_vec3 orient, double hight, double diameter, t_color color);
t_triangle	malloc_triange(t_vec3 pos1, t_vec3 pos2, t_vec3 pos3, t_color color);*/


void		free_sphere(t_sphere *sphere);/*
void		free_plane(t_plane *plane);
void		free_square(t_square *square);
void		free_triange(t_triangle *triange);
void		free_cylindre(t_cyl *cylindre)*/


t_color		color_sphere(t_sphere *sphere,t_ray *ray_origin);/*
t_color		color_plane(t_sphere *plane);
t_color		color_square(t_sphere *square);
t_color		color_triangle(t_sphere *triangle);
t_color		color_cylindre(t_sphere *cylindre);*/


t_camera	*malloc_camera(double fov, t_vec3 pos, t_vec3 orient);
void		free_camera(t_camera *cam);


t_light		create_light(t_vec3 pos, double ratio, t_color color);
t_light		*malloc_light(t_vec3 pos, double ratio, t_color color);
void		free_light(t_light *light);


t_color		find_pixel_color(t_obj *obj, t_ray *ray_origin);
#endif
