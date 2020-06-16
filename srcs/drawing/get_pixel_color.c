/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:57:28 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/16 15:19:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


/*
** Retourne la couleur a afficher : 
** intensité = ratio lumiere * produit scalaire (normalisé( L.pos - S.pt_inter), Normal)
*/
/*
t_color		color_sphere(t_sphere *sphere, t_ray *ray_origin)
{
		double 		intensite_pixel;
		t_color		color;
		t_vec3 		light_orient;

		color = calculate_shadow(sphere->color, ray_origin, g_app->scene->light);
		light_orient = ft_normalize_vec3(ft_sub_vec3(g_app->scene->light->pos, ray_origin->pt_intersection));
		intensite_pixel = pow(0.5 * ft_dot_vec3(light_orient, ray_origin->normal), 1/2.2);
		if (intensite_pixel > 1)
			return (color);
		if (intensite_pixel < 0)
			intensite_pixel = 0;
		color.r =  color.r * intensite_pixel;
		color.g =  color.g * intensite_pixel;
		color.b =  color.b * intensite_pixel;
		color.a =  color.a * intensite_pixel;
		return (color);
}
*/