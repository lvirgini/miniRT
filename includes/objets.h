/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:56:37 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/29 17:21:34 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJETS_H
# define OBJETS_H

# include "minirt.h"

typedef unsigned char		t_uchar;
typedef struct s_color		t_color;
typedef struct s_vector2	t_vector2;
typedef struct s_vector3	t_vector3;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_square		t_square;
typedef struct s_cyl		t_cyl;
typedef struct s_triangle	t_triangle;

struct s_vector2
{
	int 	x;
	int 	y;
};

struct s_vector3
{
	int 	x;
	int 	y;
	int		z;
};

struct	s_color
{
	t_uchar r;
	t_uchar g;
	t_uchar b;
	t_uchar a;
};

struct s_sphere
{
	t_vector3	pos;
	int			diameter;
	t_color		color;
};

struct s_plane
{
	t_vector3	pos;
	t_vector3	orient;
	t_color		color;
};

struct s_square
{
	t_vector3	pos;
	t_vector3	orient;
	int			hight;
	t_color		color;
};

struct s_cyl
{
	t_vector3	pos;
	t_vector3	orient;
	t_color		color;
	int			hight;
	int			diameter;
};

struct s_triange
{
	t_vector3	pos1;
	t_vector3	pos2;
	t_vector3	pos3;
	t_color		color;	
};


#endif