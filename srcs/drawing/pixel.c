/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:22:26 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/28 17:50:43 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Si l'objet est mirroir calcul du nouveau rayon pour trouver la couleur réfléchie par la surface mirroir.
** max_rebound pour stopper la reflexion infinie.
*/

t_color		find_mirroir_color(t_ray ray_incident, t_color obj_color)
{	
	t_ray	new_ray;
	t_vec3	new_direction;
	t_obj	*first_obj;
	t_color color;
	static int max_rebound = 5;

	max_rebound--;
	if (max_rebound == 0)
		return (create_color(0, 0, 0, 255));

	new_direction = ft_sub_vec3(ray_incident.direction, ft_mul_vec3(ray_incident.normal, 2 * ft_dot_vec3(ray_incident.direction, ray_incident.normal)));
	new_ray = create_ray(ft_add_vec3(ray_incident.pt_intersection, ft_mul_vec3(ray_incident.normal, 0.01)), new_direction);
	first_obj = find_first_intersection(&new_ray, g_app->scene->objs);
	if (first_obj != NULL)
		color = find_pixel_color(first_obj, &new_ray);
	else 
		color = create_color(0, 0, 0, 255);
	max_rebound = 5;
	return (color);
}


/*
** Recherche et retourne la bonne couleur du pixel.
*/

static t_color		find_good_color(t_ray *ray_origin, t_color obj_color, int texture, t_light *light)
{
	double 		intensite_pixel;
	t_color		color;
	t_vec3 		light_vec;
	//double		light_distance;

	// si MIRROIR : 
	if (texture == TEXTURE_MIRROIR)
		return(find_mirroir_color(*ray_origin, obj_color));

	// SI dans l'ombre la couleur devient noir.
	color = calculate_shadow(obj_color, ray_origin, light);

	// intensité de la lumière :
	light_vec = ft_sub_vec3(light->pos, ray_origin->pt_intersection);

	double light_scalaire = ft_dot_vec3(ft_normalize_vec3(light_vec), ray_origin->normal);

	if (light_scalaire < 0.)
		light_scalaire = 0;

	int light_intensity = 3000 * light->ratio ; /////

	intensite_pixel = light_intensity * light_scalaire / ft_norme2_vec3(light_vec);


	if (light_intensity < 0)
		light_intensity = 0;

	int r =  color.r * intensite_pixel;// / light_distance * light_distance;
		color.r = r > 255 ? 255 : r;
		r =  color.g * intensite_pixel;// / light_distance * light_distance;
		color.g = r > 255 ? 255 : r;
		r =  color.b * intensite_pixel;// / light_distance * light_distance;
		color.b = r > 255 ? 255 : r;
		r =  color.a * intensite_pixel;// / light_distance * light_distance;
		color.a = r > 255 ? 255 : r;
		color.a = 255;

	return (color);
}

/*
** en fonction du rayon, et de l'objet intersepté par ce rayon, retourne la couleur obtenue.
*/

t_color		find_pixel_color(t_obj *obj, t_ray *ray_origin)
{
	if (obj->type == SPHERE)
		return(find_good_color( ray_origin, ((t_sphere *)obj->shape)->color, ((t_sphere *)obj->shape)->texture, g_app->scene->light));
	/*else if (obj->type == PLANE)
		return(color_plane((t_plane *)obj->shape));
	else if (obj->type == SQUARE)
		return(color_square((t_square *)obj->shape));
	else if (obj->type == TRIANGLE)
		return(color_triangle((t_triangle *)obj->shape));
	else if (obj->type == CYLINDRE)
		return(color_triangle((t_sphere *)obj->shape));*/
	return(color_sphere((t_sphere *)obj->shape, ray_origin)); ///// NOPE
}

/*
** Inscrit sur l'image la couleur donnée sur le pixel de coordonnees x, y.
*/

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



/// OLD
t_color		color_sphere(t_sphere *sphere, t_ray *ray_origin)
{
		double 		intensite_pixel;
		t_color		color;
		t_vec3 		light_orient;

		color = calculate_shadow(sphere->color, ray_origin, g_app->scene->light);
		light_orient = ft_normalize_vec3(ft_sub_vec3(g_app->scene->light->pos, ray_origin->pt_intersection));
		intensite_pixel = pow(0.9 * ft_dot_vec3(light_orient, ray_origin->normal), 1/2.2);
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



/*		intensite_pixel = g_app->scene->light->ratio * ft_dot_vec3(ft_normalize_vec3(ft_sub_vec3(g_app->scene->light->pos, ray_origin->pt_intersection)), ray_origin->normal) / ft_norme2_vec3(ft_sub_vec3(g_app->scene->light->pos, ray_origin->pt_intersection));
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
