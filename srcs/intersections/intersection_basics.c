/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_basics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:24:37 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/11 13:25:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Renvoie a la fonction d'intersection suivant le type d'objet.
*/

double		intersect_objects(t_ray *ray, t_obj *objs)
{
	//printf("obj = %d\n", objs->type);
	if (objs->type == SPHERE)
		return(intersect_sphere(*ray, (t_sphere *)objs->shape));
	/*else if (objs->type == PLANE)
		intersect_plane(ray, *objs);
	else if (objs->type == SQUARE)
		intersect_square(ray, *objs);
	else if (objs->type == CYLINDRE)
		intersect_cylindre(ray, *objs);
	else if (objs->type == TRIANGLE)
		intersect_triange(ray, *objs);*/
	return (0);
}

/*
** Recherche la premiere intersection du rayon avec un objet.
*/

t_obj		*find_first_intersection(t_ray *ray, t_obj *objs)
{
	t_obj	*first_obj;
	double	t1;
	double	t2;
	
	if (!objs)
		return (NULL);
	first_obj = NULL;
	t1 = intersect_objects(ray, objs);
	if (t1 <= 0.0 || t1 > 1e99)
		return (find_first_intersection(ray, objs->next));
	else
	{
		first_obj = objs;
		while (objs->next)
		{
			t2 = intersect_objects(ray, objs->next);
			if (t2 != 0.0 && t2 < t1 )
			{
				t1 = t2;
				first_obj = objs->next;
			}
			objs = objs->next;
		}
		return (first_obj);
	}
}

/*
** dessine l'objet indiqué
*/

void		print_object(t_obj *obj, int x, int y)
{
	t_sphere *sphere;

	if (obj->type == SPHERE)
	{
		sphere = (t_sphere *)obj->shape;
		put_pixel(g_app->img, x, y, sphere->color);
	}
	/*
		if obj == SHAPE
			color = find color sphere(t_sphere SHAPE)
		else if obj == SHAPE 2
			color = ...
		put pixel (color)
	*/
}

/*
** Pour chaque pixel de l'image, recherche une intersection avec un obj en fonction du rayon de la camera (cam) envoyé en parametre.
*/

int			browse_image_for_intersection(t_camera *cam, int W, int H)
{
	int		i;
	int		j;
	t_obj	*first_obj;
	t_ray *ray;
	
	ray = malloc_ray(create_vec3(0, 0, 0), create_vec3(0, 0, 1));
	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			ray->direction = ft_normalize_vec3(create_vec3(j - (W / 2), i - (H / 2), - W / (2 * tan(cam->fov /2)))); 
			first_obj = find_first_intersection(ray, g_app->scene->objs);
			if (first_obj != NULL)
				put_pixel(g_app->img, j, H - i - 1, find_pixel_color(first_obj));
			j++;
		}
		i++;
	}
	free_ray(ray);
	return (0);
}

/*
** En partant de l'origin du rayon, retourne l'emplacement du point lorsque
** direction * t.
** return = origin + (direction * t)


t_vec3		ray_calculate_t(t_ray ray, double t)
{
	return (ft_add_vec3(ray.origin, ft_mul_vec3(ray.direction, t)));
}
*/


/*
** Renvoi le numero correspondant au type d'objet
*/
/*
int			intersect_type_object(t_obj	*obj)
{
	t_ft_intersect inter[5];

	inter[0] = NULL; //
	inter[SPHERE] = intersect_sphere;
	inter[PLANE] = intersect_plane;
	inter[SQUARE] = intersect_square;
	inter[CYLINDRE] = intersect_cylendre;
	inter[TRIANGLE] = intersect_triangle;
	
	inter[obj->type](obj->shape);
}*/