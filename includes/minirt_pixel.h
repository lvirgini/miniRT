/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_pixel.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:58:36 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 13:34:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PIXEL_H
# define MINIRT_PIXEL_H

# include "minirt.h"

/*
** Fonctions de gestion des pixels
*/

void		clear_application(t_color color, t_app *app);
void		put_pixel(t_image *image, int x, int y, t_color color);
t_color		find_pixel_color(int type, void *shape, t_ray *ray, t_app *app);

#endif
