/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:49:45 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/27 09:45:49 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_COLOR_H
# define MINIRT_COLOR_H

# include "minirt.h"

/*
**	s_color : red, green, blue, alpha
**	Les defines correspondent a l'emplacement de la couleur sur un pixel
**	un pixel contient 4 u_char : 0 = blue, 1 = green, 2 = red, 3 = alpha
*/

# define BLUE_PIXEL	 0
# define GREEN_PIXEL 1
# define RED_PIXEL	 2
# define ALPHA_PIXEL 3

typedef struct s_color		t_color;

struct		s_color
{
	uchar	r;
	uchar	g;
	uchar	b;
	uchar	a;
};

/*
**	Fonctions qui gèrent les couleurs
*/

t_color		create_color(uchar r, uchar g, uchar b, uchar a);
t_color		*malloc_color(uchar r, uchar g, uchar b, uchar a);
void		free_color(t_color *to_free);
int			fuze_color_int(int actual, int to_add); //
t_color		fuze_color(t_color actual, t_color to_add);

#endif
