/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_basics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:24:37 by lvirgini          #+#    #+#             */
/*   Updated: 2020/09/27 13:34:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Renvoie a la fonction d'intersection suivant le type d'objet.
*/

static double	intersect_objects(t_ray *ray, t_obj *obj, t_vec3 *pt_inter,
	t_vec3 *normal)
{
	if (obj->type == SPHERE)
		return (intersect_sphere(ray, (t_sphere *)obj->shape, pt_inter, normal));
	else if (obj->type == PLANE)
		return (intersect_plane(ray, (t_plane *)obj->shape, pt_inter, normal));
	//else if (obj->type == TRIANGLE)
	//	return(intersect_triangle(ray, (t_triangle *)obj->shape, pt_inter, normal));
	/*else if (obj->type == SQUARE)
		intersect_square(ray, *obj);
	else if (obj->type == CYLINDRE)
		intersect_cylindre(ray, *obj);*/
	return (0);
}

static void		update_ray(t_ray *ray, t_vec3 pt_inter, t_vec3 normal, int t)
{
	ray->pt_intersection = copy_vec3(pt_inter);
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
** Pour chaque pixel de l'image, recherche une intersection avec un obj 
** en fonction du rayon de la camera (cam) envoyé en parametre.
*/

int				browse_image_for_intersection(t_camera *cam, int w, int h)
{
	int		i;
	int		j;
	t_obj	*first_obj;
	t_ray	*ray;
	//cam = malloc_camera(2, create_vec3(0, 0, 0), create_vec3(0, 0, 1));
	printf("browse_image OK\n\n");
	print_vec3(cam->pos, "cam->pos");
	print_vec3(cam->orient, "cam->orient");
	ray = malloc_ray(cam->pos, add_vec3(cam->pos, cam->orient));
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
				//printf("browse_image	i = %d		j = %d\n", i, j);
			// creation du rayon normalisé entre le point de la camera et le pixel de "l'ecran".
			ray->direction = normalize_vec3(create_vec3(j - (w / 2) + 0.5, i - (h / 2) + 0.5, -w / (2 * tan(cam->fov / 2))));

			// recherche le premier objet intersepté sur le lancer de rayon
			first_obj = find_first_intersection(ray, g_app->scene->objs);

			// s'il y a intersection / s'il y a un obj sur le rayon :
			//		color le pixel de la couleur retourné par find pixel color.
			if (first_obj != NULL)
			{
				//if (first_obj->type == TRIANGLE)
				//	put_pixel(g_app->img, j, h - i - 1, create_color(255, 255, 255, 255));
				//else
					put_pixel(g_app->img, j, h - i - 1, find_pixel_color(first_obj, ray));
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
