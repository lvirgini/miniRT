/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:02:59 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/03 15:01:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_IMAGE_H
# define STRUCT_IMAGE_H

# include "minirt.h"

typedef struct s_img 		t_img;
typedef struct s_app		t_app;
typedef struct s_scene		t_scene;

struct 	s_img
{
	t_vector2	size;
	void		*img_ptr;
	char		*pixels;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
};

struct s_scene
{
	t_camera	**cam;
	t_ambiant	*ambiant;
	t_light		**light;
	t_sphere	**sp;
	t_plane		**pl;
	t_square	**sq;
	t_cyl		**cyl;
	t_triangle	**tri;
};

struct 	s_app
{
	int 	x;
	int 	y;
	//t_img	*img;
	t_scene	*scene;
};
#endif