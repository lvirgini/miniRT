/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:57:28 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/26 21:45:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


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
		color = calculate_shadow(obj_color, ray_origin, g_app->scene->light);

		// faire une fonction pour plusieurs lumiere /////////////////////
		light_orient = ft_normalize_vec3(ft_sub_vec3(g_app->scene->light->pos, ray_origin->pt_intersection));
		light_distance = ft_norme_vec3(ft_sub_vec3(g_app->scene->light->pos, ray_origin->pt_intersection));

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

	t_color copy_color = calculate_shadow(obj_color, ray_origin, g_app->scene->light);
// creation couleur ambiante

	double R = color.r;
	double G = color.g;
	double B = color.b;

	R = kd * Ia * (ambiant_color.r + color.r)/2; 
	G = kd * Ia * (ambiant_color.g + color.g)/2;
	B = kd * Ia * (ambiant_color.b + color.b)/2;


// creation couleur et lumiere directe
	
	t_vec3	light_vector= ft_normalize_vec3(ft_sub_vec3(g_app->scene->light->pos, ray_origin->pt_intersection));

	double N_L = ft_dot_vec3(ray_origin->normal, light_vector);
	double Il = g_app->scene->light->ratio;

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
		color.a =  color.a * intensite_pixel ;/// light_distance * light_distance;*/
	/*	return (color);
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