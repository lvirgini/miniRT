/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/13 13:50:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_app		*g_app;

int		run_application(void)
{
	mlx_loop(g_app->mlx_ptr);
	free_application(g_app);
	return (0);
}

int		exit_program(void)
{
	exit(0);
	return (0);
}

void	print_vec3(t_vec3 vec)
{
	printf("x = %f	y = %f	z = %f\n", vec.x, vec.y, vec.z);
}

void	make_croix_milieu(void)
{
	int x = 0;
	int y = 0;

	while (x < g_app->size.x)
	{
		while (y < g_app->size.y)
		{
		/*	if ((-40 + (g_app->size.x / 2)) == x)
				put_pixel(g_app->img, x, y, create_color(0, 0, 0, 255));
			if ((-40 + (g_app->size.y / 2)) == y)
				put_pixel(g_app->img, x, y, create_color(0, 0, 0, 255));*/
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

void	generate_scene_2(void)
{
		t_camera *cam = malloc_camera(60 * PI / 180, create_vec3(0, 0, 0), create_vec3(0, 0, 0));
		t_sphere *sphere = malloc_sphere(create_vec3(0, 0, -55), 20.0, create_color(0, 0, 255, 200));
		t_sphere *sphere1 = malloc_sphere(create_vec3(0, -2000-20, 0), 2000.0, create_color(255, 255, 255, 200));
		t_sphere *sphere2 = malloc_sphere(create_vec3(0, 2000 + 100, 0), 2000.0, create_color(255, 255, 255, 200));
		t_sphere *sphere3 = malloc_sphere(create_vec3(-2000-50,0 , 0), 2000.0, create_color(0, 255, 0, 200));
		t_sphere *sphere4 = malloc_sphere(create_vec3(2000 + 50,0 , 0), 2000.0, create_color(0, 255, 0, 200));
		t_sphere *sphere5 = malloc_sphere(create_vec3(0,0 , -2000 - 100), 2000.0, create_color(0, 255, 255, 200));
		t_light *light = malloc_light(create_vec3(15, 70, -30), 1000000000000, create_color(255,255,255,255));/// ratio a voir

		t_obj	*obj;

		obj = malloc_object(SPHERE, sphere);
		obj->next = malloc_object(SPHERE, sphere1);
		obj->next->next = malloc_object(SPHERE, sphere2);
		obj->next->next->next = malloc_object(SPHERE, sphere3);
		obj->next->next->next->next = malloc_object(SPHERE, sphere4);
		obj->next->next->next->next->next = malloc_object(SPHERE, sphere5);
		g_app->scene = malloc_scene(cam, obj);
		g_app->scene->light = light;
}


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

int		main(int ac, char **av)
{
	int		x = 1024;
	int		y = 1024;
	char	*title = "Minirt";

	if (!(g_app = malloc_application(x, y, title)))
		return (file_error("MALLOC", 1));
	g_app->img = malloc_image(x, y);
	/*if (file_checking(ac, av) == -1)
		return (-1);*/

	void *param[5];

	generate_scene();
	raytracing_test(param);
	make_croix_milieu();

	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->img->img_ptr,0, 0);
 	mlx_key_hook(g_app->win_ptr,handle_key, param);
	mlx_mouse_hook (g_app->win_ptr,handle_mouse, g_app->scene->objs);
	mlx_hook(g_app->win_ptr, 17, (1L << 17), exit_program, 0);

//	mlx_hook(g_app->win_ptr, 3, 2, handle_key, &param);
//	mlx_loop_hook(g_app->mlx_ptr, raytracing_test, param);
//premiers_test(param);

	/*printf("%p END g_app->scene->obj->next\n", g_app->scene->objs->next);
	printf("%p END gapp->obj\n", g_app->scene->objs);*/

	return (run_application());

	if(ac == 0 && av[0] == 0) // pour -Werror
		return(0); //
}