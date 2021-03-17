/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:24:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 14:22:28 by lvirgini         ###   ########.fr       */
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

int		check_if_shadow(t_ray *ray_origin, t_light *light, t_obj *objs)
{
	double		distance_light2;
	t_vec3		obj_to_light;
	t_ray		ray_light;

	obj_to_light = sub_vec3(light->pos, ray_origin->pt_inter);
	ray_light = create_ray(add_vec3(ray_origin->pt_inter,
			mul_vec3(ray_origin->normal, RAY_T_MIN)),
			normalize_vec3((obj_to_light)), create_vec3(0, 0, 0));
	if (closest_object(&ray_light, objs) != NULL)
	{
		distance_light2 = norme2_vec3(obj_to_light);
		if (ray_light.t * ray_light.t < distance_light2)
			return (1);
	}
	return (0);
}
