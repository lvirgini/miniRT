/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_intersection.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:06:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/16 13:50:45 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_INTERSECTION_H
# define MINIRT_INTERSECTION_H

# include "minirt.h"

/*
** Defini le nom t_point pour diférencier un point d'un vecteur. a voir si ca
** pose probleme par la suite.
*/

typedef	struct s_vec2		t_pt2; //
typedef	struct s_vec3		t_pt3;
typedef struct s_ray		t_ray;

/*
** Rayon avec un point origine, un vecteur de direction, si intersection :
** pt_inter sur un objet, et la normal a ce pt d'intersection.
*/

struct		s_ray
{
	t_pt3		origin;
	t_vec3		direction;
	t_vec3		pt_inter;
	t_vec3		normal;
	double		t;
};

/*
** Fonctions qui gerent la creation et suppression d'un s_ray.
*/

t_ray		create_ray(t_vec3 origin, t_vec3 direction);
t_ray		*malloc_ray(t_vec3 origin, t_vec3 direction);
void		free_ray(t_ray *ray);

/*
** Fonctions qui gerent les intersections rayon / obj.
*/

int			generate_raytracing(t_app *app);
int			browse_image_for_intersection(t_camera *cam, int win_x, int win_y,
				t_image *img);
t_obj		*closest_object(t_ray *ray, t_obj *obj);
double		intersect_sphere(t_ray *ray, t_sphere *sphere,
				t_vec3 *pt_inter, t_vec3 *normal);
double		intersect_plane(t_ray *ray, t_plane *plane,
				t_vec3 *pt_inter, t_vec3 *normal);
double		intersect_triangle(t_ray *ray, t_triangle *triangle,
				t_vec3 *pt_inter, t_vec3 *normal);
//int			calculate_shadow(t_ray *ray_origin, t_light *light);

int			check_if_shadow(t_ray *ray_origin, t_light *light);
t_color		calculate_shadow(t_color color, t_ray *ray_origin, t_light *light);

#endif
