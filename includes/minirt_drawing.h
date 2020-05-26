/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_drawing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:58:36 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/26 11:15:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DRAWING_H
# define MINIRT_DRAWING_H

# include "minirt.h"

/*
** Fonctions de gestion du dessin
*/

void	raw_rectangle_int(t_image *image, t_vec2 pos, t_vec2 size, int color);
void	draw_rectangle(t_vec2 pos, t_vec2 size, t_color color);
void	draw_rectangle_in_image(t_image *image, t_vec2 pos, t_vec2 size,
	t_color color);
void	clear_application(t_color color);
void	put_pixel(t_image *image, int x, int y, t_color color);

#endif
