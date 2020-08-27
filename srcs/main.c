/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/27 11:47:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_app		*g_app;

/*
** Derniere chose a faire : demarrer l'application.
*/
int		run_application(void)
{
	mlx_loop(g_app->mlx_ptr);
	free_application(g_app);
	return (0);
}

/// A VIRER : 
void	make_croix_milieu(void)
{
	int x = 0;
	int y = 0;

	while (x < g_app->size.x)
	{
		while (y < g_app->size.y)
		{
			if (((g_app->size.x / 2)) == x)
				put_pixel(g_app->img, x, y, create_color(255, 255, 255, 255));
			if (((g_app->size.y / 2)) == y)
				put_pixel(g_app->img, x, y, create_color(255, 255, 255, 255));
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->img->img_ptr,0, 0);
}

//// TEST DE SCENE 2:

void	generate_scene_2(void)
{
		t_camera *cam = malloc_camera(60 * PI / 180, create_vec3(0, 0, 0), create_vec3(0, 0, 0));
		t_light *light = malloc_light(create_vec3(15, 70, -30), 0.9, create_color(255,255,255,255));/// ratio a voir
		t_light	*light_ambiant = malloc_light(create_vec3(0, 0, 0), 0.4, create_color(200,0,200,255));

		
		t_sphere *sphere = malloc_sphere(create_vec3(15, 0, -55), 10.0, create_color(0, 200, 255, 200), TEXTURE_MIRROIR);
		//t_sphere *sphere6 = malloc_sphere(create_vec3(-15, 0, -55), 10.0, create_color(0, 0, 255, 200), TEXTURE_MIRROIR);
		
	//	t_sphere *sphere1 = malloc_sphere(create_vec3(0, -2000-20, 0), 2000.0, create_color(210, 180, 220, 200), 0);

		t_plane *plan = malloc_plane(create_vec3(0, -30, 0), create_vec3(0, 1, 0), create_color(102, 51, 153, 255), 0);
		t_plane *plan2 = malloc_plane(create_vec3(-70, 0, 0), create_vec3(1, 0, 0),  create_color(204, 153, 102, 255), 0);
		t_plane *plan3 = malloc_plane(create_vec3(70, 0, 0), create_vec3(1, 0, 0), create_color(51, 204, 255, 255), 0);

		t_sphere *sphere4 = malloc_sphere(create_vec3(0, 15, -70), 10.0, create_color(255, 0, 0, 255), 0);
		t_sphere *sphere5 = malloc_sphere(create_vec3(-15, 0, -70), 10.0, create_color(0, 0, 255, 200),0);

		//t_vec3 pos[3] = {create_vec3(0,15,-70), create_vec3(-15, 0, -70), create_vec3(15, 0, -55)};
		//t_triangle *triangle = malloc_triangle(pos, create_color(255, 255, 255, 255), 0);

		
		t_obj	*obj;

		obj = malloc_object(SPHERE, sphere);
		obj->next = malloc_object(PLANE, plan);
		obj->next->next = malloc_object(PLANE, plan2);
		obj->next->next->next = malloc_object(PLANE, plan3);
		obj->next->next->next->next = malloc_object(SPHERE, sphere4);
		obj->next->next->next->next->next = malloc_object(SPHERE, sphere5);
		//obj->next->next->next->next->next->next = malloc_object(TRIANGLE, triangle);

		g_app->scene = malloc_scene(cam, obj, light, light_ambiant);
}

/// TEST DE SCENE 1:
void	generate_scene(void)
{
	generate_scene_2();
	/*t_camera *cam = malloc_camera(60 * PI / 180, create_vec3(0, 0, 0), create_vec3(0, 0, 0));
	t_sphere *sphere = malloc_sphere(create_vec3(0, 0, -200), 30.0, create_color(0, 0, 255, 200));
	t_sphere *sphere2 = malloc_sphere(create_vec3(70, 70, -200), 20.0, create_color(180, 20, 100, 255));
	t_sphere *sphere3 = malloc_sphere(create_vec3(-70, -70, -200), 20.0, create_color(0, 180, 80, 255));
	t_light *light = malloc_light(create_vec3(15, 180, -10), 15000000, create_color(255,255,255,255));/// ratio a voir

	t_obj	*obj;

	obj = malloc_object(SPHERE, sphere);
	obj->next = malloc_object(SPHERE, sphere2);
	obj->next->next = malloc_object(SPHERE, sphere3);
	//printf("CREATION obj ->next = %p\n", obj->next);
	g_app->scene = malloc_scene(cam, obj);
	g_app->scene->light = light;*/
}

/*
** 1) Check ac, av
** 2) Creation global g_app, initialisation de la mlx
** 3) Mise en place de la scene avec le fichier (check des erreurs) file_checking
** 4) Creation de l'image avec le raytracing
** 5) lancement de l'application (Mise en place des fonctionnalités clavier souris)
**		OU sauvegarder l'image en fichier image.
*/
int		main(int ac, char **av)
{
	//int		x = 1024;
	//int		y = 1024;
	//char	*title = "Minirt";
	//void 	*param[5]; ///



	/*if (!(g_app = malloc_application(x, y, title)))
		minirt_exit_on_error(1);
	if (!(g_app->img = malloc_image(x, y)))
		minirt_exit_on_error(1);*/

	g_app = malloc_application();
	g_app->scene = malloc_scene();
	
	print_all_scene(g_app->scene);
	if (file_checking(ac, av) == -1)
		minirt_exit_on_error(1);

	/*generate_scene();
	raytracing_test(param);
	make_croix_milieu(); ///

	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->img->img_ptr,0, 0);

 	mlx_key_hook(g_app->win_ptr,handle_key, param);
	mlx_mouse_hook (g_app->win_ptr,handle_mouse, g_app->scene->objs);
	mlx_hook(g_app->win_ptr, 17, (1L << 17), exit_program, 0);

//	mlx_hook(g_app->win_ptr, 3, 2, handle_key, &param);
//	mlx_loop_hook(g_app->mlx_ptr, raytracing_test, param);
//	premiers_test(param);

	return (run_application());*/

	if(ac == 0 && av[0] == 0) // pour -Werror
		return(0); //*/
	return (0);
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

