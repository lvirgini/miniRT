/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:57:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/17 18:24:21 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		get_color_ambiant(t_light amb, t_color *result)
{
	add_color_light(result, amb.color, amb.ratio / g_scene->total_intens);
}

/*
** Contribution lumiere diffuse :
** Couleur finale += couleur lumiere * <L.N> * coeff
** L vecteur entre position de la lumiere et le pt intersection
** N la normale au pt inter
** coeff ratio / total ratio dans la scene
**
**GAMMA = intensity =pow(light.ratio * light_scalaire, 1/2.2);
** NO GAMMA intensity = light.ratio * light_scalaire / g_scene->total_intens;
*/

static void		get_color_light(t_light light, t_ray ray, t_color *result)
{
	double		intensity;
	double		light_scalaire;
	t_vec3		light_vec;

	light_vec = sub_vec3(light.pos, ray.pt_inter);
	light_scalaire = dot_vec3(normalize_vec3(light_vec), ray.normal);
	if (light_scalaire < 0)
		light_scalaire = 0;
	intensity = light.ratio * light_scalaire / g_scene->total_intens;
	add_color_light(result, light.color, intensity);
}

t_color			find_good_color(t_ray *ray_origin, t_color obj_color,
					int texture, t_light *light)
{
	t_color		final_color;
	t_light		*l;

	if (g_scene->total_intens < 1.0)
		g_scene->total_intens = 1.0;
	if (texture == TEXTURE_MIRROIR)
		return (find_mirroir_color(*ray_origin));
	final_color = (t_color){0, 0, 0};
	get_color_ambiant(*(g_scene)->light_ambiant, &final_color);
	l = light;
	while (l)
	{
		if (check_if_shadow(ray_origin, l) == 0)
			get_color_light(*l, *ray_origin, &final_color);
		l = l->next;
	}
	final_color.r = obj_color.r * (final_color.r / 255);
	final_color.g = obj_color.g * (final_color.g / 255);
	final_color.b = obj_color.b * (final_color.b / 255);
	return (adjust_final_color(final_color));
}

/*
** en fonction du rayon, et de l'objet intersepté par ce rayon,
** retourne la couleur obtenue.
*/

t_color			find_pixel_color(t_obj *obj, t_ray *ray)
{
	if (obj->type == SPHERE)
		return (find_good_color(ray, ((t_sphere *)obj->shape)->color,
				((t_sphere *)obj->shape)->texture, g_scene->light));
	else if (obj->type == PLANE)
		return (find_good_color(ray, ((t_plane *)obj->shape)->color,
				((t_plane *)obj->shape)->texture, g_scene->light));
	else if (obj->type == TRIANGLE)
		return (find_good_color(ray, ((t_triangle *)obj->shape)->color,
				((t_triangle *)obj->shape)->texture, g_scene->light));
	else if (obj->type == SQUARE)
		return (find_good_color(ray, ((t_square *)obj->shape)->color,
				((t_square *)obj->shape)->texture, g_scene->light));
	else if (obj->type == CYLINDRE)
		return (find_good_color(ray, ((t_cyl *)obj->shape)->color,
				((t_cyl *)obj->shape)->texture, g_scene->light));
	else
		return (create_color(255, 255, 255));
}
