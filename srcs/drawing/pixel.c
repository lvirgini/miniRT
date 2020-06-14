/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:22:26 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/14 14:25:11 by lvirgini         ###   ########.fr       */
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

t_vec3		ft_mul2_vec3(t_vec3 a, t_vec3 b)
{
	return (create_vec3(a.x * b.x, a.y * b.y, a.z * b.z));
}
/*
** Retourne la couleur a afficher : 
** intensité = ratio lumiere * produit scalaire (normalisé( L.pos - S.pt_inter), Normal)
*/

t_color		color_sphere(t_sphere *sphere, t_ray *ray_origin)
{
		double 		intensite_pixel;
		t_color		color;
		double		tmp;
	
		double		d_light2;
		t_vec3		lp;
		
		/// SHADOW
		t_vec3 lumiere_pt_inter = ft_sub_vec3(g_app->scene->light->pos, ray_origin->pt_intersection);
		t_vec3 P = ft_mul2_vec3(ray_origin->pt_intersection, ft_mul_vec3(ray_origin->normal, 0.01));

		
		t_ray ray_light = create_ray(ft_add_vec3(ray_origin->pt_intersection, ft_mul_vec3(ray_origin->normal, 0.01)), ft_normalize_vec3((lumiere_pt_inter)));
		ray_light.t = 0;
		if (find_first_intersection(&ray_light, g_app->scene->objs) != NULL)
		{
			
			d_light2 = ft_norme2_vec3(lumiere_pt_inter);
			if (ray_light.t * ray_light.t < d_light2) // SI CEST DANS L'OMBRE
			{
				intensite_pixel = 0;
				color.r = 0;
				color.g = 0;
				color.b = 0;
				color.a = 0;
				return (color);
			}
		}

/*		intensite_pixel = g_app->scene->light->ratio * ft_dot_vec3(ft_normalize_vec3(ft_sub_vec3(g_app->scene->light->pos, ray_origin->pt_intersection)), ray_origin->normal) / ft_norme2_vec3(ft_sub_vec3(g_app->scene->light->pos, ray_origin->pt_intersection));
*/

		t_vec3 light_orient = create_vec3(0, 0, 0);

		light_orient = ft_normalize_vec3(ft_sub_vec3(g_app->scene->light->pos, ray_origin->pt_intersection));


		intensite_pixel = 0.8 * ft_dot_vec3(light_orient, ray_origin->normal);

		/* NON
		color.r =  pow(sphere->color.r *intensite_pixel, 1/2.2) * 256;  
		color.g =  pow(sphere->color.g *intensite_pixel, 1/2.2) * 256;
		color.b =  pow(sphere->color.b *intensite_pixel, 1/2.2) * 256;
		color.a =  pow(sphere->color.a *intensite_pixel, 1/2.2) * 256;//255; //// Suivant la transparence*/
		// 1/2.2 Correction GAMMA*/


		if (intensite_pixel > 1)
			return (sphere->color);
		if (intensite_pixel < 0)
			intensite_pixel = 0;
		color.r =  sphere->color.r * intensite_pixel;
		color.g =  sphere->color.g * intensite_pixel;
		color.b =  sphere->color.b * intensite_pixel;
		color.a =  sphere->color.a * intensite_pixel;//255 ?
		
		/*color.r = 1 * intensite_pixel;
		color.g = 0 * intensite_pixel;
		color.b = 0 * intensite_pixel;
		color.a = intensite_pixel;*/

		return (color);
}


t_color		find_pixel_color(t_obj *obj, t_ray *ray_origin)
{
	if (obj->type == SPHERE)
		return(color_sphere((t_sphere *)obj->shape, ray_origin));
	/*else if (obj->type == PLANE)
		return(color_plane((t_plane *)obj->shape));
	else if (obj->type == SQUARE)
		return(color_square((t_square *)obj->shape));
	else if (obj->type == TRIANGLE)
		return(color_triangle((t_triangle *)obj->shape));
	else if (obj->type == CYLINDRE)
		return(color_triangle((t_sphere *)obj->shape));*/
	return(color_sphere((t_sphere *)obj->shape, ray_origin));
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
