/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:49:45 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/09 08:56:55 by lvirgini         ###   ########.fr       */
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

typedef struct s_color	t_color;

struct	s_color
{
	double r;
	double g;
	double b;
};

/*
**	Fonctions qui gèrent les couleurs
*/

t_color	create_color(t_uchar r, t_uchar g, t_uchar b);
t_color	mul_color(t_color a, t_color b);
t_color	add_color(t_color a, t_color b);
void	add_color_light(t_color *res, t_color l_color, double ratio);
t_color	mul_color_ratio(t_color color, double ratio);
t_color	adjust_final_color(t_color final_color, t_color obj_color);

#endif
