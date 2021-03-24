/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_intersection.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 17:06:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/24 17:32:38 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_INTERSECTION_H
# define MINIRT_INTERSECTION_H

# include "minirt.h"

/*
** Rayon avec un point origine, un vecteur de direction, si intersection :
** pt_inter sur un objet, et la normal a ce pt d'intersection.
*/

typedef struct s_ray		t_ray;

struct		s_ray
{
	t_vec3		origin;
	t_vec3		dir;
	t_vec3		dir_std;
	t_vec3		pt_inter;
	t_vec3		normal;
	double		t;
};

/*
** Fonctions qui gerent la creation et suppression d'un s_ray.
*/

t_ray		create_ray(t_vec3 origin, t_vec3 direction, t_vec3 dir_std);
t_ray		*malloc_ray(t_vec3 origin, t_vec3 direction);
void		free_ray(t_ray *ray);

/*
** Fonctions qui gerent les intersections rayon / obj.
*/

int			generate_raytracing(t_app *app);
int			browse_image_for_intersection(t_camera *cam, t_image *img,
					t_app *app, t_vec2 size);
t_obj		*closest_object(t_ray *ray, t_obj *obj);
double		intersect_sphere(t_ray *ray, t_sphere *sphere,
				t_vec3 *pt_inter, t_vec3 *normal);
double		intersect_plane(t_ray *ray, t_plane *plane,
				t_vec3 *pt_inter, t_vec3 *normal);
double		intersect_triangle(t_ray *ray, t_triangle *triangle,
				t_vec3 *pt_inter, t_vec3 *normal);
double		intersect_square(t_ray *ray, t_square *square,
				t_vec3 *pt_inter, t_vec3 *normal);
double		intersect_cylinder(t_ray *ray, t_cyl *cyl, t_vec3 *p,
				t_vec3 *normal);
double		quadratic_equation(double a, double b, double c, double t[2]);

#endif
