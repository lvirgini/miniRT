/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:57:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/16 18:20:20 by lvirgini         ###   ########.fr       */
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
		return (create_color(0, 0, 0));
	new_direction = sub_vec3(ray_incident.direction, mul_vec3(ray_incident.normal, 2 * dot_vec3(ray_incident.direction, ray_incident.normal)));
	new_ray = create_ray(add_vec3(ray_incident.pt_inter, mul_vec3(ray_incident.normal, RAY_T_MIN)), new_direction);
	first_obj = closest_object(&new_ray, g_scene->objs);
	if (first_obj != NULL)
		color = find_pixel_color(first_obj, &new_ray);
	else
		color = create_color(0, 0, 0);
	max_rebound = MAX_REBOUND;
	(void)obj_color; ///
	return (color);
}

void		get_color_ambiant(t_light ambiant, t_color obj_color, t_color *final)
{

	final->r += ambiant.color.r * ambiant.ratio / g_scene->total_intens;
	final->g += ambiant.color.g * ambiant.ratio / g_scene->total_intens;
	final->b += ambiant.color.b * ambiant.ratio / g_scene->total_intens;

/*	final->r += (obj_color.r + ambiant.color.r)/2 * ambiant.ratio / g_scene->total_intens;
	final->g += (obj_color.g + ambiant.color.g)/2 * ambiant.ratio / g_scene->total_intens;
	final->b += (obj_color.b + ambiant.color.b)/2 * ambiant.ratio / g_scene->total_intens;*/
}

double		cos_vec3(t_vec3 a, t_vec3 b)
{
	return (dot_vec3(a, b) / (norme_vec3(a) * norme_vec3(b)));
}

static t_color	find_good_color(t_ray *ray_origin, t_color obj_color, int texture, t_light *light)
{
	double		intensite_pixel;
	t_color		color;
	t_vec3		light_vec;
	double		r;

	if (g_scene->total_intens < 1.0)
		g_scene->total_intens = 1.0;
	// si MIRROIR :
	if (texture == TEXTURE_MIRROIR)
		return (find_mirroir_color(*ray_origin, obj_color));

	color = (t_color){0, 0, 0};
	get_color_ambiant(*(g_scene)->light_ambiant, obj_color, &color);

	/*color.r = obj_color.r * g_scene->light_ambiant->ratio;
	color.g = obj_color.g * g_scene->light_ambiant->ratio;
	color.b = obj_color.b * g_scene->light_ambiant->ratio;*/
	if (check_if_shadow(ray_origin, light) == 0)
	{
	// intensité de la lumière :
		light_vec = sub_vec3(light->pos, ray_origin->pt_inter);
		double light_scalaire = dot_vec3(light_vec, ray_origin->normal);
		if (light_scalaire < 0)
			light_scalaire = 0;

		//GAMMA
		//intensite_pixel = light->ratio * pow(cos_vec3(ray_origin->normal, normalize_vec3(light_vec)), 1 / 2.2);
		
		// NO GAMMA
		intensite_pixel = light->ratio * cos_vec3(ray_origin->normal, normalize_vec3(light_vec));
	
		/*color.r +=  (obj_color.r + light->color.r)/2 * intensite_pixel/ g_scene->total_intens;
		color.g +=  (obj_color.g + light->color.g)/2 * intensite_pixel/ g_scene->total_intens;
		color.b +=  (obj_color.b + light->color.b)/2 * intensite_pixel/ g_scene->total_intens;*/
		
		color.r += light->color.r * intensite_pixel / g_scene->total_intens;
		color.g += light->color.g * intensite_pixel / g_scene->total_intens;
		color.b += light->color.b * intensite_pixel / g_scene->total_intens;
	}

	color.r = obj_color.r * (color.r / 255);
	color.g = obj_color.g * (color.g / 255);
	color.b = obj_color.b * (color.b / 255);

	return (color);
}



t_color		adjust_final_color(t_color color)
{	
	t_color res;

	res.r = fmax(0, fmin(255, color.r));
	res.g = fmax(0, fmin(255, color.g));
	res.b = fmax(0, fmin(255, color.b));
	return (res);
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
	return (create_color(255, 255, 255)); ///// NOPE
}
