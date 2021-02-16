/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:24:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/16 13:50:32 by lvirgini         ###   ########.fr       */
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
 
 
 //////OLD

t_color		calculate_shadow(t_color color, t_ray *ray_origin, t_light *light)
{
	double		distance_light2;
	t_vec3		obj_to_light;
	t_ray		ray_light;
	double		light_ambiant;

	light_ambiant = g_scene->light_ambiant->ratio;
	obj_to_light = sub_vec3(light->pos, ray_origin->pt_inter);
	ray_light = create_ray(add_vec3(ray_origin->pt_inter,
			mul_vec3(ray_origin->normal, RAY_T_MIN)),
			normalize_vec3((obj_to_light)));
	if (closest_object(&ray_light, g_scene->objs) != NULL)
	{
		distance_light2 = norme2_vec3(obj_to_light);
		if (ray_light.t * ray_light.t < distance_light2) // SI CEST DANS L'OMBRE
		{
			color.r = color.r * light_ambiant;
			color.g = color.g * light_ambiant;
			color.b = color.b * light_ambiant;
		}
	}
	return (color);
}


			////// NEW
int		check_if_shadow(t_ray *ray_origin, t_light *light)
{
	double		distance_light2;
	t_vec3		obj_to_light;
	t_ray		ray_light;

	obj_to_light = sub_vec3(light->pos, ray_origin->pt_inter);
	ray_light = create_ray(add_vec3(ray_origin->pt_inter,
			mul_vec3(ray_origin->normal, RAY_T_MIN)),
			normalize_vec3((obj_to_light)));
	if (closest_object(&ray_light, g_scene->objs) != NULL)
	{
		distance_light2 = norme2_vec3(obj_to_light);
		if (ray_light.t * ray_light.t < distance_light2) // SI CEST DANS L'OMBRE
			return (1);
	}
	return (0);
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

	lumiere_pt_inter = ft_sub_vec3(light->pos, ray_origin->pt_inter);
	ray_light = create_ray(ft_add_vec3(ray_origin->pt_inter, ft_mul_vec3(ray_origin->normal, 0.01)), ft_normalize_vec3((lumiere_pt_inter)));
	ray_light.t = 0;
	if (closest_object(&ray_light, g_scene->objs) != NULL)
		{
			if (texture == 1)
			{
				t_vec3 direction_mirroir = ft_sub_vec3(ray_origin->direction, ft_mul_vec3(ray_light.normal, 2 * ft_dot_vec3(ray_light.normal, ray_origin->direction)));
				t_vec3 origin_mirroir = ft_add_vec3(ray_light.pt_inter, ft_mul_vec3(ray_light.normal, 0.001));
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
