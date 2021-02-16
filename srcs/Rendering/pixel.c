/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:22:26 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/16 09:19:22 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Inscrit sur l'image la couleur donnée sur le pixel de coordonnees x, y.
*/

void		put_pixel(t_image *image, int x, int y, t_color color)
{
	int		pixel_index;

	if (x < 0 || y < 0 || x >= image->size.x || y >= image->size.y)
		return ;
	pixel_index = (y * image->size.x + x) * 4;
	image->pixels[pixel_index + RED_PIXEL] = (char)color.r;
	image->pixels[pixel_index + GREEN_PIXEL] = (char)color.g;
	image->pixels[pixel_index + BLUE_PIXEL] = (char)color.b;
	image->pixels[pixel_index + ALPHA_PIXEL] = 0;
}

/*
t_color		color_sphere(t_sphere *sphere, t_ray *ray_origin)
{
	double		intensite_pixel;
	t_color		color;
	t_vec3		light_orient;

	color = calculate_shadow(sphere->color, ray_origin, g_scene->light);
	light_orient = normalize_vec3(sub_vec3(g_scene->light->pos, ray_origin->pt_inter));
	intensite_pixel = pow(0.9 * dot_vec3(light_orient, ray_origin->normal), 1 / 2.2);
	if (intensite_pixel > 1)
		return (color);
	if (intensite_pixel < 0)
		intensite_pixel = 0;
	color.r = color.r * intensite_pixel;
	color.g = color.g * intensite_pixel;
	color.b = color.b * intensite_pixel;
	color.a = color.a * intensite_pixel;
	return (color);
}*/

/*
**	Colore chaque pixel de l'image
** 	un pixel contient 4 u_char : 0 = blue, 1 = green, 2 = red, 3 = alpha
**	on recupere la couleur deja presente sur l'image, puis on fusionne avec la
** 	couleur donnee en parametre.


void	put_pixel2(t_image *image, int x, int y, t_color color)
{
	t_color	actual;
	t_color	tmp;
	int		pixel_index;

	if (x < 0 || y < 0 || x >= image->size.x || y >= image->size.y)
		return ;
	pixel_index = (y * g_app->size.x + x) * 4;
	pixel_index = ((g_app->size.y - y - 1) * g_app->size.x + x) * 4;
	actual = create_color(image->pixels[pixel_index + RED_PIXEL],
							image->pixels[pixel_index + GREEN_PIXEL],
							image->pixels[pixel_index + BLUE_PIXEL],
							255);
	tmp = fuze_color(actual, color);
	image->pixels[pixel_index + RED_PIXEL] = tmp.r;
	image->pixels[pixel_index + GREEN_PIXEL] = tmp.g;
	image->pixels[pixel_index + BLUE_PIXEL] = tmp.b;
}*/

t_vec3		ft_mul2_vec3(t_vec3 a, t_vec3 b)
{
	return (create_vec3(a.x * b.x, a.y * b.y, a.z * b.z));
}

/*		intensite_pixel = g_scene->light->ratio * ft_dot_vec3(ft_normalize_vec3(ft_sub_vec3(g_scene->light->pos, ray_origin->pt_inter)), ray_origin->normal) / ft_norme2_vec3(ft_sub_vec3(g_scene->light->pos, ray_origin->pt_inter));
*/

	//light_orient = create_vec3(0, 0, 0);
	/*NON
	color.r =  pow(sphere->color.r *intensite_pixel, 1/2.2) * 256;
	color.g =  pow(sphere->color.g *intensite_pixel, 1/2.2) * 256;
	color.b =  pow(sphere->color.b *intensite_pixel, 1/2.2) * 256;
	color.a =  pow(sphere->color.a *intensite_pixel, 1/2.2) * 256;//255; //// Suivant la transparence*/
	// 1/2.2 Correction GAMMA*/

	/*color.r =  sphere->color.r * intensite_pixel;
	color.g =  sphere->color.g * intensite_pixel;
	color.b =  sphere->color.b * intensite_pixel;
	color.a =  sphere->color.a * intensite_pixel;//255 ?*/

	/*color.r =  pow(sphere->color.r *intensite_pixel, 1/2.2);
	color.g =  pow(sphere->color.g *intensite_pixel, 1/2.2);
	color.b =  pow(sphere->color.b *intensite_pixel, 1/2.2);
	color.a =  255;//255; //// Suivant la transparence*/

	/*color.r = 1 * intensite_pixel;
	color.g = 0 * intensite_pixel;
	color.b = 0 * intensite_pixel;
	color.a = intensite_pixel;*/
