/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:24:13 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/07 17:53:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** verifie et calcule si le point d'intersection se trouve dans l'ombre d'un
** autre obj.
** CALCUL :
**		obj_to_light = le vecteur entre le point d'intersection et la lumiere.
**		distance_light2 = longueur du vecteur obj_to_light au carre
**		ray_light = rayon du point d'intersection a la lumiere. (legerement
**					decaller pour ne pas s'interecter lui-meme.)
** S il y a un objet sur le ray_light et qu'il se trouve plus proche que
**   la lumiere : le point d'intersection se trouve dans son ombre.
*/

//// sph1.w est la taille de la sphère
//float amb = smoothstep(0.0, sph1.w, length(pos.xz-sph1.sz));

t_color		calculate_shadow(t_color color, t_ray *ray_origin, t_light *light)
{
	double		distance_light2;
	t_vec3		obj_to_light;
	t_ray		ray_light;
	int			light_ambiant;

	light_ambiant = g_scene->light_ambiant->ratio; ///

	obj_to_light = sub_vec3(light->pos, ray_origin->pt_intersection);
	ray_light = create_ray(add_vec3(ray_origin->pt_intersection,
			mul_vec3(ray_origin->normal, RAY_T_MIN)),
			normalize_vec3((obj_to_light)));
	if (find_first_intersection(&ray_light, g_scene->objs) != NULL)
	{
		distance_light2 = norme2_vec3(obj_to_light);
		if (ray_light.t * ray_light.t < distance_light2) // SI CEST DANS L'OMBRE
		{
			/*
			color.r = color.r * ray_light.t / distance_light2 *256;
			color.g = color.g * ray_light.t / distance_light2 *256;
			color.b = color.b * ray_light.t / distance_light2 *256;
			color.a = color.a * ray_light.t / distance_light2 *256; ////NOPE
			*/
			color.r = color.r * light_ambiant;
			color.g = color.g * light_ambiant;
			color.b = color.b * light_ambiant;
			color.a = color.a * light_ambiant;
		}
	}
	return (color);
}

/*
** verifie et calcule si le point d'intersection se trouve dans l'ombre d'un
** autre obj.
*/
/*
t_color		calculate_shadow(t_color color, t_ray *ray_origin, t_light *light,
							int texture)
{
	double		distance_light2;
	t_vec3 		lumiere_pt_inter;
	t_ray 		ray_light;

	if ( texture-- == -1)
		return (create_color(0, 0, 0, 0));

	lumiere_pt_inter = ft_sub_vec3(light->pos, ray_origin->pt_intersection);
	ray_light = create_ray(ft_add_vec3(ray_origin->pt_intersection, ft_mul_vec3(ray_origin->normal, 0.01)), ft_normalize_vec3((lumiere_pt_inter)));
	ray_light.t = 0;
	if (find_first_intersection(&ray_light, g_scene->objs) != NULL)
		{
			if (texture == 1)
			{
				t_vec3 direction_mirroir = ft_sub_vec3(ray_origin->direction, ft_mul_vec3(ray_light.normal, 2 * ft_dot_vec3(ray_light.normal, ray_origin->direction)));
				t_vec3 origin_mirroir = ft_add_vec3(ray_light.pt_intersection, ft_mul_vec3(ray_light.normal, 0.001));
				t_ray ray_mirroir = create_ray(origin_mirroir, direction_mirroir);
				return(calculate_shadow(color, &ray_mirroir, light, texture));
			}
		else
		distance_light2 = ft_norme2_vec3(lumiere_pt_inter);
		if (ray_light.t * ray_light.t < distance_light2) // SI CEST DANS L'OMBRE
		{
			color.r = 0;
			color.g = 0;
			color.b = 0;
			color.a = 0;
		}
	}
	return (color);
}*/
