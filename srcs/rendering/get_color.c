/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:57:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/18 10:18:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_color_ambiant(t_light amb, t_color *res, double total_intens)
{
	add_color_light(res, amb.color, amb.ratio / total_intens);
}

/*
** Contribution lumiere speculaire
** v = ray direction primaire
** n = normal obj
** L = light_vecteur
** R = 2(N⋅L)N − L.
** si (R.-V) > 0
** intensity speculaire = <V.R> puissance SPECULAR_VALUE
** Couleur finale += couleur lumiere * intensity speculaire
*/

static void	get_color_specular(t_light light, t_ray ray, t_color *result)
{
	double		intensity;
	double		r_dot_v;
	t_vec3		reflect;
	t_vec3		light_vec;

	light_vec = normalize_vec3(sub_vec3(light.pos, ray.pt_inter));
	reflect = sub_vec3(mul_vec3(mul_vec3(ray.normal,
			dot_vec3(ray.normal, light_vec)), 2), light_vec);
	r_dot_v = dot_vec3(reflect, mul_vec3(ray.direction, -1));
	if (r_dot_v > 0)
	{
		r_dot_v = r_dot_v / norme_vec3(reflect) * norme_vec3(ray.direction);
		intensity = light.ratio * pow(r_dot_v, SPECULAR_VALUE);
		add_color_light(result, light.color, intensity);
	}
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

static void	get_color_diffus(t_light light, t_ray ray, t_color *res,
				double total_intens)
{
	double		intensity;
	double		light_scalaire;
	t_vec3		light_vec;

	light_vec = sub_vec3(light.pos, ray.pt_inter);
	light_scalaire = dot_vec3(normalize_vec3(light_vec), ray.normal);
	if (light_scalaire < 0)
		light_scalaire = 0;
	intensity = light.ratio * light_scalaire / total_intens;
	add_color_light(res, light.color, intensity);
}

/*
** Check all lights and texture and get all illumination of a pixel
*/

t_color		find_good_color(t_ray *ray, t_color obj_color,
					int texture, t_app *app)
{
	t_color		final_color;
	t_light		*l;
	double		total_intens;

	total_intens = app->scene->total_intens;
	final_color = create_color(0, 0, 0);
	if (texture != TEXTURE_MIRROIR)
		get_color_ambiant(*app->scene->light_ambiant, &final_color,
			total_intens);
	l = app->scene->light;
	while (l)
	{
		if (check_if_shadow(ray, l, app->scene->objs) == 0)
		{
			if (texture != TEXTURE_MIRROIR)
				get_color_diffus(*l, *ray, &final_color, total_intens);
			get_color_specular(*l, *ray, &final_color);
		}
		l = l->next;
	}
	if (texture != TEXTURE_MIRROIR)
		return (adjust_final_obj_color(final_color, obj_color));
	final_color = add_color(final_color, find_mirroir_color(*ray, app));
	return (adjust_min_max_color(final_color));
}

/*
** en fonction du rayon, et de l'objet intersepté par ce rayon,
** retourne la couleur obtenue.
*/

t_color		find_pixel_color(int type, void *shape, t_ray *ray, t_app *app)
{
	if (type == SPHERE)
		return (find_good_color(ray, ((t_sphere *)shape)->color,
				((t_sphere *)shape)->texture, app));
	else if (type == PLANE)
		return (find_good_color(ray, ((t_plane *)shape)->color,
				((t_plane *)shape)->texture, app));
	else if (type == TRIANGLE)
		return (find_good_color(ray, ((t_triangle *)shape)->color,
				((t_triangle *)shape)->texture, app));
	else if (type == SQUARE)
		return (find_good_color(ray, ((t_square *)shape)->color,
				((t_square *)shape)->texture, app));
	else if (type == CYLINDRE)
		return (find_good_color(ray, ((t_cyl *)shape)->color,
				((t_cyl *)shape)->texture, app));
	else
		return (create_color(255, 255, 255));
}
