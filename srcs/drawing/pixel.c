/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:22:26 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/05 12:56:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**	Colore chaque pixel de l'image
** 	un pixel contient 4 u_char : 0 = blue, 1 = green, 2 = red, 3 = alpha
**	on recupere la couleur deja presente sur l'image, puis on fusionne avec la
** 	couleur donnee en parametre.
*/

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
}


t_color		color_sphere(t_sphere *sphere)
{
		double 		intensite_pixel;
		t_color		color;
		int tmp;
		
		intensite_pixel = g_app->scene->light->ratio * ft_dot_vec3(ft_normalize_vec3(ft_sub_vec3(g_app->scene->light->pos, sphere->pt_intersection)), sphere->normal) / ft_norme2_vec3(ft_sub_vec3(g_app->scene->light->pos, sphere->pt_intersection));

		/*if (intensite_pixel > 255)
			intensite_pixel = 255;*/
		if (intensite_pixel < 0 )
			intensite_pixel = 1;
		if (sphere->color.r == 0)
			sphere->color.r ++;
		tmp = sphere->color.r * intensite_pixel / 255;
		if (tmp > 255)
			color.r = 255;
		else
			color.r = tmp;

		tmp = sphere->color.g * intensite_pixel / 255;
		if (tmp > 255)
			color.g = 255;
		else
			color.g = tmp;

		tmp = sphere->color.b * intensite_pixel / 255;
		if (tmp > 255)
			color.b = 255;
		else
			color.b = tmp;

		tmp = sphere->color.a * intensite_pixel / 255;
		if (tmp > 255)
			color.a = 255;
		else
			color.a = tmp;
		/*
		color.g = sphere->color.g * intensite_pixel / 255;
		color.b = sphere->color.b * intensite_pixel / 255;
		color.a = sphere->color.a * intensite_pixel / 255;//255; //// Suivant la transparence*/

		return (color);
}


t_color		find_pixel_color(t_obj *obj)
{
	if (obj->type == SPHERE)
		return(color_sphere((t_sphere *)obj->shape));
	/*else if (obj->type == PLANE)
		return(color_plane((t_plane *)obj->shape));
	else if (obj->type == SQUARE)
		return(color_square((t_square *)obj->shape));
	else if (obj->type == TRIANGLE)
		return(color_triangle((t_triangle *)obj->shape));
	else if (obj->type == CYLINDRE)
		return(color_triangle((t_sphere *)obj->shape));*/
	return(color_sphere((t_sphere *)obj->shape));
}

void	put_pixel(t_image *image, int x, int y, t_color color)
{
	int		pixel_index;

	if (x < 0 || y < 0 || x >= image->size.x || y >= image->size.y)
		return ;
	pixel_index = (y * g_app->size.x + x) * 4;
	image->pixels[pixel_index + RED_PIXEL] = color.r;
	image->pixels[pixel_index + GREEN_PIXEL] = color.g;
	image->pixels[pixel_index + BLUE_PIXEL] = color.b;
	image->pixels[pixel_index + ALPHA_PIXEL] = color.a;
}
