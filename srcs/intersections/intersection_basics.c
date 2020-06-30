/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_basics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:24:37 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/30 11:45:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Renvoie a la fonction d'intersection suivant le type d'objet.
*/

static double	intersect_objects(t_ray *ray, t_obj *objs, t_vec3 *pt_intersection, t_vec3 *normal)
{
	if (objs->type == SPHERE)
		return(intersect_sphere(ray, (t_sphere *)objs->shape, pt_intersection, normal));
	else if (objs->type == PLANE)
		return(intersect_plane(ray, (t_plane *)objs->shape, pt_intersection, normal));
	else if (objs->type == TRIANGLE)
		return(intersect_triangle(ray, (t_triangle *)objs->shape, pt_intersection, normal));
	/*else if (objs->type == SQUARE)
		intersect_square(ray, *objs);
	else if (objs->type == CYLINDRE)
		intersect_cylindre(ray, *objs);*/
	return (0);
}

static void		update_ray(t_ray *ray, t_vec3 pt_intersection, t_vec3 normal, int t)
{
	ray->pt_intersection = copy_vec3(pt_intersection);
	ray->normal = copy_vec3(normal);
	ray->t = t;
}

/*
** Recherche la premiere intersection du rayon avec un objet.
*/

t_obj			*find_first_intersection(t_ray *ray, t_obj *objs)
{
	t_obj	*first_obj;
	double	t1;
	double	t2;
	t_vec3	pt_intersection;
	t_vec3	normal;
	
	if (!objs)
		return (NULL);
	first_obj = NULL;
	pt_intersection = create_vec3(0, 0, 0);
	normal = create_vec3(0, 0, 0);
	t1 = intersect_objects(ray, objs, &pt_intersection, &normal);

	// s'il n'y a pas d'intersection avec l'objet courant, on passe au prochain obj.
	if (t1 <= RAY_T_MIN || t1 > RAY_T_MAX)
		return (find_first_intersection(ray, objs->next));

	// S'il y a intersection, verifie s'il y a un autre objet plus proche que celui ci.
	else
	{
		first_obj = objs;
		update_ray(ray, pt_intersection, normal, t1);
		while (objs->next)
		{
			t2 = intersect_objects(ray, objs->next, &pt_intersection, &normal);
			if (t2 > RAY_T_MIN && t2 < t1)
			{
				t1 = t2;
				first_obj = objs->next;
				update_ray(ray, pt_intersection, normal, t1);
			}
			objs = objs->next;
		}
		return (first_obj);
	}
}

/*
** Pour chaque pixel de l'image, recherche une intersection avec un obj en fonction du rayon de la camera (cam) envoyé en parametre.
*/

int			browse_image_for_intersection(t_camera *cam, int W, int H)
{
	int		i;
	int		j;
	t_obj	*first_obj;
	t_ray 	*ray;
	
	ray = malloc_ray(create_vec3(0, 0, 0), create_vec3(0, 0, 1));
	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			// creation du rayon normalisé entre le point de la camera et le pixel de "l'ecran".
			ray->direction = ft_normalize_vec3(create_vec3(j - (W / 2) + 0.5, i - (H / 2) + 0.5, - W / (2 * tan(cam->fov /2))));

			// recherche le premier objet intersepté sur le lancer de rayon
			first_obj = find_first_intersection(ray, g_app->scene->objs);

			// s'il y a intersection / s'il y a un obj sur le rayon : 
			//		color le pixel de la couleur retourné par find pixel color.
			if (first_obj != NULL)
			{
				/*if (first_obj->type == PLANE)
					put_pixel(g_app->img, j, H - i - 1, create_color(255,255,255,255));
				else*/
					put_pixel(g_app->img, j, H - i - 1, find_pixel_color(first_obj, ray));
			}
			
			// remet a zero le point d'intersection et la normal modifié dans 
			// find intersection.
			ray->pt_intersection = create_vec3(0, 0, 0);
			ray->normal = create_vec3(0, 0, 0);
			j++;
		}
		i++;
	}
	free_ray(ray);
	return (0);
}
