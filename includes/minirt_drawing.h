/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_drawing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:58:36 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/13 14:42:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DRAWING_H
# define MINIRT_DRAWING_H

# include "minirt.h"

/*
** Fonctions de gestion du dessin
*/

void		clear_application(t_color color, t_app *app);
void		put_pixel(t_image *image, int x, int y, t_color color);
t_color		find_pixel_color(t_obj *obj, t_ray *ray_origin);

#endif
