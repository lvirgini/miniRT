/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_objet.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:56:37 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/04 14:12:05 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_OBJET_H
# define STRUCT_OBJET_H

# include "minirt.h"

typedef	int					(*t_func)(char *);

typedef struct s_color		t_color;
typedef struct s_camera		t_camera;
typedef struct s_ambiant	t_ambiant;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_square		t_square;
typedef struct s_cyl		t_cyl;
typedef struct s_triangle	t_triangle;


/*
**	s_color : red, green, blue, alpha
*/

struct	s_color
{
	uchar 	r;
	uchar 	g;
	uchar 	b;
	uchar	a;
};

struct	s_camera
{
	int			fov; //compris entre 0 et 180
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
	float		ratio;
	t_vec3		pos;
	t_color		color;
};

struct	s_sphere
{
	t_vec3		pos;
	float		diameter;
	t_color		color;
};

struct	s_plane
{
	t_vec3		pos;
	t_vec3		orient;
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
	t_vec3	pos1;
	t_vec3	pos2;
	t_vec3	pos3;
	t_color		color;
};

#endif
