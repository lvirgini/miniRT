/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/17 18:24:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// faire une sphere blanche pour voir les lumieres colorées
// intersection triangle
//	ATTENTION : pas d'ombre si light devant le triangle (derriere oui)
//			  :	pas de reflex sur le mirroir du triangle entier
// intersection carré
// intersection cylindre
// integration de "bonus".

t_scene		*g_scene;

int			main(int ac, char **av)
{
	t_app	app;
	t_scene	scene;

	errno = 0;
	init_application(&app);
	init_scene(&scene);
	app.scene = &scene;
	g_scene = &scene;
	if (file_checking(ac, av, &app) == -1)
		return (-1);
	print_all_scene(g_scene);
	generate_mlx_content(&app);
	generate_raytracing((void *)&app);
	printf("TOTAL RATIO = %f\n", g_scene->total_intens);
	if (app.save == 1)
		return(generate_bmp_file(&app));
	return (run_application(&app));
}

/*
 const Vec3f &orig, const Vec3f &dir, 
    const Vec3f &v0, const Vec3f &v1, const Vec3f &v2, 
    float &t) 
{ 

    // compute plane's normal
    Vec3f v0v1 = v1 - v0; 
    Vec3f v0v2 = v2 - v0; 
    // no need to normalize
    Vec3f N = v0v1.crossProduct(v0v2); // N 
    float area2 = N.length(); 
 
    // Step 1: finding P
 
    // check if ray and plane are parallel ?
    float NdotRayDirection = N.dotProduct(dir); 
    if (fabs(NdotRayDirection) < kEpsilon) // almost 0 
        return false; // they are parallel so they don't intersect ! 
 
    // compute d parameter using equation 2
    float d = N.dotProduct(v0); 
 
    // compute t (equation 3)
    t = (N.dotProduct(orig) + d) / NdotRayDirection; 
    // check if the triangle is in behind the ray
    if (t < 0) return false; // the triangle is behind 
 
    // compute the intersection point using equation 1
    Vec3f P = orig + t * dir; 
 
    // Step 2: inside-outside test
    Vec3f C; // vector perpendicular to triangle's plane 
 
    // edge 0
    Vec3f edge0 = v1 - v0; 
    Vec3f vp0 = P - v0; 
    C = edge0.crossProduct(vp0); 
    if (N.dotProduct(C) < 0) return false; // P is on the right side 
 
    // edge 1
    Vec3f edge1 = v2 - v1; 
    Vec3f vp1 = P - v1; 
    C = edge1.crossProduct(vp1); 
    if (N.dotProduct(C) < 0)  return false; // P is on the right side 
 
    // edge 2
    Vec3f edge2 = v0 - v2; 
    Vec3f vp2 = P - v2; 
    C = edge2.crossProduct(vp2); 
    if (N.dotProduct(C) < 0) return false; // P is on the right side; 
 
    return true; // this ray hits the triangle 
} */
/*

denom = -(product_vectors(*object->normal, *object->a));
		object->calcul_a = product_vectors(origin, *object->normal) + denom;
		object->prev_origin = cpy_vector(&origin);
	}
	b = product_vectors(direction, *object->normal);
	t = -(object->calcul_a / b);
	if (t <= 0)
		return (0);

	t_vector		*temp;
	t_vector		*point;
	float			dot_wv_wu[2];
	t_vector		*w;
	float			r[2];

	temp = multiply_vectors(t, direction);
	point = add_vectors(origin, *temp);
	free(temp);


	w = subtract_vectors(*point, *object->a);
	dot_wv_wu[0] = product_vectors(*w, *object->u);
	dot_wv_wu[1] = product_vectors(*w, *object->v);
	r[0] = (object->dot_uv * dot_wv_wu[1] - object->dot_vv *
dot_wv_wu[0]) / object->calcul_d;
	free(w);
	if (r[0] < 0 || r[0] > 1)
		return (0);
	r[1] = (object->dot_uv * dot_wv_wu[0] - object->dot_uu *
dot_wv_wu[1]) / object->calcul_d;
	if (r[1] < 0 || (r[0] + r[1] > 1))
		return (0);
	return (t);


	triangle->a = a;
	triangle->b = b;
	triangle->c = c;
	triangle->u = subtract_vectors(*triangle->b, *triangle->a);
	triangle->v = subtract_vectors(*triangle->c, *triangle->a);
	triangle->normal = cross(*triangle->u, *triangle->v);
	triangle->dot_uu = product_vectors(*triangle->u, *triangle->u);
	triangle->dot_uv = product_vectors(*triangle->u, *triangle->v);
	triangle->dot_vv = product_vectors(*triangle->v, *triangle->v);
	triangle->calcul_d =
triangle->dot_uv * triangle->dot_uv - triangle->dot_uu * triangle->dot_vv;
*/


/*
for x in [-Cw/2, Cw/2] {
    for y in [-Ch/2, Ch/2] {
        D = CanvasToViewport(x, y)
        color = TraceRay(O, D, 1, inf)
        canvas.PutPixel(x, y, color)
    }

	CanvasToViewport(x, y) {
    return (x*Vw/Cw, y*Vh/Ch, d)
}
}*/
/*
int				browse_image_for_intersectionfirst(t_camera *cam, int w, int h, t_image	*img)
{
	int		i;
	int		j;
	t_obj	*first_obj;
	t_ray	*ray;

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
			first_obj = find_first_intersection(ray, g_scene->objs);

			// s'il y a intersection / s'il y a un obj sur le rayon :
			//		color le pixel de la couleur retourné par find pixel color.
			if (first_obj != NULL)
			{
				//if (first_obj->type == TRIANGLE)
				//	put_pixel(g_app->img, j, h - i - 1, create_color(255, 255, 255, 255));
				//else
					put_pixel(img, j, h - i - 1, find_pixel_color(first_obj, ray));
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





t_obj			*find_first_intersectionold(t_ray *ray, t_obj *objs)
{
	t_obj	*first_obj;
	double	t1;
	double	t2;
	t_vec3	pt_inter;
	t_vec3	normal;

	if (!objs)
		return (NULL);
	first_obj = NULL;
	pt_inter = create_vec3(0, 0, 0);
	normal = create_vec3(0, 0, 0);
	t1 = intersect_objects(ray, objs, &pt_inter, &normal);
// s'il n'y a pas d'intersection avec l'objet courant, on passe au prochain obj.
	if (t1 == 0)
		return (find_first_intersection(ray, objs->next));
// S'il y a intersection, verifie s'il y a un autre objet plus proche que lui.
	else
	{
		first_obj = objs;
		update_ray(ray, pt_inter, normal, t1);
		while (objs->next)
		{
			t2 = intersect_objects(ray, objs->next, &pt_inter, &normal);
			if (t2 > RAY_T_MIN && t2 < t1)
			{
				t1 = t2;
				first_obj = objs->next;
				update_ray(ray, pt_inter, normal, t1);
			}
			objs = objs->next;
		}
		return (first_obj);
	}
}
*/