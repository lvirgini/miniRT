/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:02:59 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/04 14:20:20 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_IMAGE_H
# define STRUCT_IMAGE_H

# include "minirt.h"

typedef struct s_app		t_app;
typedef struct s_scene		t_scene;
typedef struct s_image		t_image;

/*
**	s_image:
**		size : taille de l'image en pixel.
**		img_ptr : retour de mlx_new_image().
**		* A partir de mlx_get_data_ptr() : 
**		pixels : pointeur sur les chars composant les pixels de l'image.
**		bits_per_pixel : nbr de bits d'un pixel ( 8 x 4 ici)
**		size_line : longueur en chars d'une ligne.
**		edian : si 0 : Big endian si 1 little endian.
*/

struct	s_image
{
	t_vec2		size;
	void		*img_ptr;
	char		*pixels;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
};


struct	s_scene
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

/*
** s_app :
**		mlx_ptr : le retour de mlx_init(), correspond a un tableau de pointeur
**		des fonctions de la mlx.
**		win_ptr : retour de mlx_new_window(), correspond a la fenetre a l'ecran.
**		size : taille de la fenetre en pixel.
**		img : le contenu de la fenetre.
*/

struct	s_app
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_vec2		size;
	t_image		*img;
	//t_scene		*scene;
};

#endif
