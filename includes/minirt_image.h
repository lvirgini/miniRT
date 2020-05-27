/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:46:57 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/26 11:15:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_IMAGE_H
# define MINIRT_IMAGE_H

# include "minirt.h"

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

typedef struct s_image		t_image;

struct		s_image
{
	t_vec2		size;
	void		*img_ptr;
	char		*pixels;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
};

/*
** Fonctions qui gerent la variable t_image
*/

t_image		create_image(int x, int y);
t_image		*malloc_image(int x, int y);
void		destroy_image(t_image to_destroy);
void		free_image(t_image *to_free);

#endif
