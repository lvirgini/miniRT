/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:14:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/07/01 11:03:43 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**							   			S.origin
**								/radius	|B
**   *Ro --> Rd ---------   (t1--- A ----P--------t2)------>
**
** Point = Ray.origin + Ray.direction * t
** t = dot(Sphere.origin - Ray.origin, Ray.direction)
** *
** A =  racine carree de radius^2 - B^2
** B =  longueur entre Sphere origin et P
** *
** t1 = P - A
** t2 = P + A
**
*/

/*
** intersection entre un rayon et une sphere revient a resoudre : 
** a*t² + b*t + c = 0
** delta = b² - 4ac
** t1 = -b - racine(delta) / 2a  -> plus proche
** t2 = -b + racine(delta) / 2a  -> plus loin
**
** retourne la longueur la plus petite ou 0 si pas d'intersection.
** modifie le pt_intersection = rayon origin + (t * rayon direction)
**	la normale = vecteur normalise (pt intersection - sphere origine)
**/

double		intersect_sphere(t_ray *ray, t_sphere *sphere, t_vec3 *pt_intersection, t_vec3 *normal)
{
	double a;
	double b;
	double c;
	double delta;
	double t[2];


	//ray->direction = ft_normalize_vec3(ray->direction);

	a = 1.0;
	b = 2 * dot_vec3(ray->direction, sub_vec3(ray->origin, sphere->pos));
	c = (norme2_vec3(sub_vec3(ray->origin, sphere->pos)) - (sphere->radius * sphere->radius));
	delta = (b * b) - (4 * a * c);
	if (delta < 0) /// SI dans la sphere
		return (0);
	t[0] = (-b - sqrt(delta)) / (2 * a);
	t[1] = (-b + sqrt(delta)) / (2 * a);

	if (t[1] < RAY_T_MIN)
		return (0);

	if (t[0] > RAY_T_MIN && t[0] < RAY_T_MAX)
	{
		*pt_intersection = add_vec3(ray->origin, mul_vec3(ray->direction, t[0]));
		*normal = normalize_vec3(sub_vec3(*pt_intersection, sphere->pos));
		return (t[0]); // si normal negative dans la sphere
	}
		/// DANS LA SPHERE ///
	//if (t[0] < RAY_T_MIN && (t[1] > RAY_T_MIN déja mis plus haut) && t[1] < RAY_T_MAX) 
		//return (0); 
	return (0);
}

/* AUTRE TEST NON CONCLUANT //

	a = (ray.direction.x * ray.direction.x) + (ray.direction.y - ray.direction.y) + (ray.direction.z * ray.direction.z);

	b = 2 * ((ray.direction.x * (ray.origin.x - sphere.pos.x)) +
			(ray.direction.y * (ray.origin.y - sphere.pos.y)) +
			(ray.direction.z * (ray.origin.z - sphere.pos.z)));
	
	c = (((ray.origin.x - sphere.pos.x) * (ray.origin.x - sphere.pos.x)) +
		((ray.origin.y - sphere.pos.y) * (ray.origin.y - sphere.pos.y)) + 
		((ray.origin.z - sphere.pos.z) * (ray.origin.z - sphere.pos.z))) - (sphere.radius * sphere.radius);*/

/*a = DIR.x^2 + DIR.y^2 + DIR.z^2
b = 2 * (DIR.x * (O.x - Xc) + DIR.y * (O.y - Yc) + DIR.z * (O.z - Zc))
c = ((O.x - Xc)^2 + (O.y - Yc)^2 + (O.z - Zc)^2) - r^2*/


/*double		intersect_sphere(t_ray ray, t_sphere sphere)
{
	double t;
	t_vec3 point;
	double a;
	double b;
	double tt[2];
	
	t  = ft_dot_vec3(ft_sub_vec3(sphere.pos, ray.origin), ray.direction);
	point = ft_add_vec3(ray.origin, ft_mul_vec3(ray.direction, t));
	b = ft_norme_vec3(ft_sub_vec3(sphere.pos, point));

	if (b < sphere.radius)
	{
		a = sqrt((sphere.radius * sphere.radius) - (b * b));
		tt[0] = t - a;
		tt[1] = t + a;

	//	printf("tt0 = %f\n", tt[0]);
	return (tt[0]);
	}
	return (0);
}*/
/*
double		remap(double a, double b, double t)
{
	return ((t - a)/ (b - a));
}*/
