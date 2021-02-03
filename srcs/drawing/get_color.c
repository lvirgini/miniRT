/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:57:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/03 14:05:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Si l'objet est mirroir calcul du nouveau rayon pour trouver la couleur 
** réfléchie par la surface mirroir.
** max_rebound pour stopper la reflexion infinie.
*/

t_color			find_mirroir_color(t_ray ray_incident, t_color obj_color)
{
	t_ray		new_ray;
	t_vec3		new_direction;
	t_obj		*first_obj;
	t_color		color;
	static int	max_rebound = MAX_REBOUND;

	max_rebound--;
	if (max_rebound == 0)
		return (create_color(0, 0, 0, 255));
	new_direction = sub_vec3(ray_incident.direction, mul_vec3(ray_incident.normal, 2 * dot_vec3(ray_incident.direction, ray_incident.normal)));
	new_ray = create_ray(add_vec3(ray_incident.pt_intersection, mul_vec3(ray_incident.normal, 0.01)), new_direction);
	first_obj = closest_object(&new_ray, g_scene->objs);
	if (first_obj != NULL)
		color = find_pixel_color(first_obj, &new_ray);
	else
		color = create_color(0, 0, 0, 255);
	max_rebound = MAX_REBOUND;
	(void)obj_color; ///
	return (color);
}

/*
** Recherche et retourne la bonne couleur du pixel.
*/

static t_color	find_good_color(t_ray *ray_origin, t_color obj_color, int texture, t_light *light)
{
	double		intensite_pixel;
	t_color		color;
	t_vec3		light_vec;
	int			r;

	// si MIRROIR :
	if (texture == TEXTURE_MIRROIR)
		return (find_mirroir_color(*ray_origin, obj_color));

	// SI dans l'ombre la couleur devient noir.
	color = calculate_shadow(obj_color, ray_origin, light);

	// intensité de la lumière :
	light_vec = sub_vec3(light->pos, ray_origin->pt_intersection);

	double light_scalaire = dot_vec3(normalize_vec3(light_vec), ray_origin->normal);

	if (light_scalaire < 0.)
		light_scalaire = 0;

	// PAS DE CORRECTION
	//int light_intensity = 6000 * light->ratio ; /////
	//intensite_pixel = light_intensity * light_scalaire / ft_norme2_vec3(light_vec);

	// CORRECTION GAMMA
	int	light_intensity = 6000 * light->ratio ;
	intensite_pixel = pow(light_intensity * light_scalaire / norme2_vec3(light_vec), 1 / 2.2);

	if (intensite_pixel < 0)
		intensite_pixel = 0;

	r = color.r * intensite_pixel;
	color.r = r > 255 ? 255 : r;
	r = color.g * intensite_pixel;
	color.g = r > 255 ? 255 : r;
	r = color.b * intensite_pixel;
	color.b = r > 255 ? 255 : r;
	r = color.a * intensite_pixel;
	color.a = r > 255 ? 255 : r;
	return (color);
}

/*
** en fonction du rayon, et de l'objet intersepté par ce rayon, retourne la couleur obtenue.
*/

t_color			find_pixel_color(t_obj *obj, t_ray *ray_origin)
{
	if (obj->type == SPHERE)
		return (find_good_color(ray_origin, ((t_sphere *)obj->shape)->color, ((t_sphere *)obj->shape)->texture, g_scene->light));
	else if (obj->type == PLANE)
		return (find_good_color(ray_origin, ((t_plane *)obj->shape)->color, ((t_plane *)obj->shape)->texture, g_scene->light));
	else if (obj->type == TRIANGLE)
		return (find_good_color(ray_origin, ((t_triangle *)obj->shape)->color, ((t_triangle *)obj->shape)->texture, g_scene->light));
	/*else if (obj->type == SQUARE)
		return(color_square((t_square *)obj->shape));
	else if (obj->type == CYLINDRE)
		return(color_triangle((t_sphere *)obj->shape));*/
	return (create_color(255, 255, 255, 255)); ///// NOPE
}

/*
** Retourne la bonne couleur du pixel.
*/

/*static t_color		find_good_colorfirst(t_ray *ray_origin, t_color obj_color, int texture)
{
		double 		intensite_pixel;
		t_color		color;
		t_vec3 		light_orient;
		double		light_distance;

		if (texture == TEXTURE_MIRROIR)
			return(find_mirroir_color(*ray_origin, obj_color));
		color = calculate_shadow(obj_color, ray_origin, g_scene->light);

		// faire une fonction pour plusieurs lumiere /////////////////////
		light_orient = ft_normalize_vec3(ft_sub_vec3(g_scene->light->pos, ray_origin->pt_intersection));
		light_distance = ft_norme_vec3(ft_sub_vec3(g_scene->light->pos, ray_origin->pt_intersection));

		// calcul l'intensité du pixel (nouveau ratio) suivant le ratio de la lumiere, la normal au pt d'intersection.
		// avec correction gamma = puissance 1/2.2
		intensite_pixel =  0.5 * ft_dot_vec3(light_orient, ray_origin->normal) /  light_distance * light_distance;

	*//*	INTENSITE
	**	lumiere speculaire = ks(R.V)^n
			ks = contribution speculaire par rapport a la matiere de l'obj
			R.V = produit scalaire entre rayon reflechis et rayon camera obj
			puissance n = coefficient de reflexion

		lumiere directe = Ii(Iokd(L.N))
			Ii intensité de la lumiere incidente
			Io intensité de l'obj
			kd contribution diffuse par rapport a la matiere de l'obj
			L.N = produit scalaire entre lumiere et la normal

		intensité ambiante = IoIaka
			Io intensité de l'objet
			Ia intensité ambiante
			ka contribution ambiante

		intensite_pixel += 0.2;
		//if (intensite_pixel > 1)
		//	return (color);
		if (intensite_pixel < 0)
			intensite_pixel = 0;

		*//*color.r = (color.r + 255) * intensite_pixel;
		color.g = (color.g + 255) * intensite_pixel;
		color.b = (color.b + 255) * intensite_pixel;
		color.a = 255; //(color.a/2 + 255/2) * intensite_pixel;*/


	/// TEST 3

/*	double kd = 1; // coeff diffusion de l'obj
	double ks = 1; // coeff reflexion speculaire
	double n = 0.8; // coeff surbrillance de l'obj;

	t_color ambiant_color = create_color(125, 0, 0, 255);
	double Ia = 0.2; // coeff intensité de la lumiere ambiante

	t_color copy_color = calculate_shadow(obj_color, ray_origin, g_scene->light);
// creation couleur ambiante

	double R = color.r;
	double G = color.g;
	double B = color.b;

	R = kd * Ia * (ambiant_color.r + color.r)/2;
	G = kd * Ia * (ambiant_color.g + color.g)/2;
	B = kd * Ia * (ambiant_color.b + color.b)/2;


// creation couleur et lumiere directe

	t_vec3	light_vector= ft_normalize_vec3(ft_sub_vec3(g_scene->light->pos, ray_origin->pt_intersection));

	double N_L = ft_dot_vec3(ray_origin->normal, light_vector);
	double Il = g_scene->light->ratio;

	t_color color_light = create_color(255,255,255,255);
	color_light.r *= (1. / (light_distance * light_distance));
	color_light.g *= (1. / (light_distance * light_distance));
	color_light.b *= (1. / (light_distance * light_distance));

	R += kd * N_L * Il * copy_color.r;
	G += kd * N_L * Il * copy_color.g;
	B += kd * N_L * Il * copy_color.b;


	color.r = R > 255 ? 255 : R;
	color.r = R < 0 ? 0 : R;

	color.g = G > 255 ? 255 : G;
	color.g = G < 0 ? 0 : G;

	color.b = B > 255 ? 255 : B;
	color.b = B < 0 ? 0 : B;

	color.a = 255;


	return (color);






		int r =  color.r * intensite_pixel;// / light_distance * light_distance;
		color.r = r > 255 ? 255 : r;
		r =  color.g * intensite_pixel;// / light_distance * light_distance;
		color.g = r > 255 ? 255 : r;
		r =  color.b * intensite_pixel;// / light_distance * light_distance;
		color.b = r > 255 ? 255 : r;
		r =  color.a * intensite_pixel;// / light_distance * light_distance;
		color.a = r > 255 ? 255 : r;

*//*

		color.g =  color.g * intensite_pixel;// / light_distance * light_distance;
		color.b =  color.b * intensite_pixel;// / light_distance * light_distance;
		color.a =  color.a * intensite_pixel ;/// light_distance * light_distance;
		return (color);
}*/

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

		color = calculate_shadow(sphere->color, ray_origin, g_scene->light);
		light_orient = ft_normalize_vec3(ft_sub_vec3(g_scene->light->pos, ray_origin->pt_intersection));
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
}*/
