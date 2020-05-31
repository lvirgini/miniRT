/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_basics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:24:37 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/31 20:10:01 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** En partant de l'origin du rayon, retourne l'emplacement du point lorsque
** direction * t.
** return = origin + (direction * t)
*/

t_vec3		ray_calculate_t(t_ray ray, double t)
{
	return (ft_add_vec3(ray.origin, ft_mul_vec3(ray.direction, t)));
}

/*
** Renvoie a la fonction d'intersection suivant le type d'objet.
*/

double		intersect_objects(t_ray *ray, t_obj *objs)
{
	double t;

	t = 0;
	//while (objs)
	//{
		//printf("obj = %d\n", objs->type);
		if (objs->type == SPHERE)
			t = intersect_sphere(*ray, *(t_sphere *)objs->shape);
		/*else if (objs->type == PLANE)
			intersect_plane(ray, *objs);
		else if (objs->type == SQUARE)
			intersect_square(ray, *objs);
		else if (objs->type == CYLINDRE)
			intersect_cylindre(ray, *objs);
		else if (objs->type == TRIANGLE)
			intersect_triange(ray, *objs);*/
	//	objs = objs->next;
	//}
	return (t);
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
	if (t1 == 0.0)
		return (find_first_intersection(ray, objs->next));
	else
	{
		first_obj = objs;
		while (objs->next)
		{
			t2 = intersect_objects(ray, objs->next);
			if (t2 != 0.0 && t2 < t1)
				first_obj = objs->next;
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
	int x = 0;
	int y = 0;
	t_obj	*first_obj;

	i = 0;
	j = 0;

	t_ray *ray;
	ray = malloc_ray(create_vec3(0, 0, 0), create_vec3(0, 0, 1));

	while (i < H) //(x < W) // i
	{
		while (j < W) // j
		{
			ray->direction = ft_normalize_vec3(create_vec3(j - (W / 2), i - (H / 2), - W / (2 * tan(cam->fov /2)))); //- W / (2 * tan(cam->fov/2))));

			//ray->direction = ft_normalize_vec3(create_vec3((2 * x) / W , (2 *  y) /  H, H / (2 * tan(cam->fov))));

			//	ray->direction = ft_normalize_vec3(create_vec3(x, y, 1);
			//Vector2 screenCoord((2.0f*x) / image.getWidth() - 1.0f,
			//	(-2.0f*y) / image.getHeight() + 1.0f);

			 //vec3 RayTrace(vec3 &Origin, const vec3 &Ray

			  // vec3 Color = RayTrace(Camera.Position, normalize(Camera.RayMatrix * vec3((float)x, (float)Line, 0.0f)));



		//	Vector direction =
	//	forward + point.u * w * right + point.v * h * up;

			first_obj = find_first_intersection(ray, g_app->scene->objs);
			if (first_obj != NULL)
			//	put_pixel(g_app->img, j, i, first_obj->color));
				print_object(first_obj, j, i);
/*
			if (intersect_objects(ray, *g_app->scene->objs) > 0)
				put_pixel(g_app->img, i, j, create_color(0,0,155,255));*/
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
