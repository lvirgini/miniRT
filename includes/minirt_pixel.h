/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_pixel.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:58:36 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/24 17:13:35 by lvirgini         ###   ########.fr       */
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
t_color		find_mirroir_color(t_ray ray_incident, t_app *app);
t_color		find_good_color(t_ray *ray, t_color obj_color,
					int texture, t_app *app);
int			check_if_shadow(t_ray *ray_origin, t_light *light, t_obj *objs);
t_color		calculate_shadow(t_color color, t_ray *ray_origin, t_light *light);
#endif
