/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:45:21 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 14:19:19 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Si l'objet est mirroir calcul du nouveau rayon pour trouver la couleur
** réfléchie par la surface mirroir.
** max_rebound pour stopper la reflexion infinie.
*/

t_color			find_mirroir_color(t_ray ray_incident, t_app *app)
{
	t_ray		new_ray;
	t_vec3		new_direction;
	t_obj		*first_obj;
	t_color		color;
	static int	max_rebound = MAX_REBOUND + 1;

	max_rebound--;
	if (max_rebound == 0)
		return (create_color(0, 0, 0));
	new_direction = sub_vec3(ray_incident.direction,
			mul_vec3(ray_incident.normal,
			2 * dot_vec3(ray_incident.direction, ray_incident.normal)));
	new_ray = create_ray(add_vec3(ray_incident.pt_inter,
			mul_vec3(ray_incident.normal, RAY_T_MIN)),
			new_direction, ray_incident.dir_std);
	first_obj = closest_object(&new_ray, app->scene->objs);
	if (first_obj != NULL)
		color = find_pixel_color(first_obj->type, first_obj->shape,
				&new_ray, app);
	else
		color = create_color(0, 0, 0);
	max_rebound = MAX_REBOUND + 1;
	return (color);
}
