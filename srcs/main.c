/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/31 20:10:50 by lvirgini         ###   ########.fr       */
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

void	testing_scene(void)
{
	int x = 0;
	int y = 0;

	while (x < g_app->size.x)
	{
		while (y < g_app->size.y)
		{
			if ((-40 + (g_app->size.x / 2)) == x)
				put_pixel(g_app->img, x, y, create_color(0, 0, 0, 255));
			if ((-40 + (g_app->size.y / 2)) == y)
				put_pixel(g_app->img, x, y, create_color(0, 0, 0, 255));
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

void	generate_scene(void)
{
	t_camera *cam = malloc_camera(60 * PI / 180, create_vec3(0, 0, 0), create_vec3(0, 0, 0));
	t_sphere *sphere = malloc_sphere(create_vec3(40, 40, -200), 20, create_color(0, 0, 255, 200));
	t_sphere *sphere2 = malloc_sphere(create_vec3(0, -155, -350), 20, create_color(20, 50, 80, 140));

	t_obj	*obj;
	obj = malloc_object(SPHERE, sphere);
	obj->next = malloc_object(SPHERE, sphere2);
	//printf("CREATION obj ->next = %p\n", obj->next);
	g_app->scene = malloc_scene(cam, obj);
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

	param[1] = malloc_color(0, 0, 255, 125);
	param[2] = malloc_color(255, 0, 0, 255);
	param[3] = malloc_color(0, 255, 0, 125);
	param[4] = malloc_color(255,255,255,255);


	generate_scene();
	raytracing_test(param);
	testing_scene();

	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->img->img_ptr,0, 0);
 	mlx_key_hook(g_app->win_ptr,handle_key, param);
	mlx_mouse_hook (g_app->win_ptr,handle_mouse, g_app->scene->objs);
	mlx_hook(g_app->win_ptr, 17, (1L << 17), exit_program, 0);

//	mlx_hook(g_app->win_ptr, 3, 2, handle_key, &param);
//	mlx_loop_hook(g_app->mlx_ptr, raytracing_test, param);
//premiers_test(param);




	printf("%p END g_app->scene->obj->next\n", g_app->scene->objs->next);
	printf("%p END gapp->obj\n", g_app->scene->objs);

	return (run_application());

	if(ac == 0 && av[0] == 0) // pour -Werror
		return(0); //
}
/*
i = -1;
	while (++i < my_mlx->scene->viewport->width)
	{
		args = new_s_args(my_mlx, i, &lock);
		if (pthread_create(&threads[i], NULL, &thread_function, args))
			pthread_error(-10);
	}


void	*thread_function(void *arguments)
{
	t_vector		*obs;
	t_vector		*d;
	int				c;
	int				y;
	t_args			*args;

	args = (t_args *)arguments;
	if (!(t_camera *)args->scene->cameras)
		return (free_cpy_scene(args->scene) ? NULL : NULL);
	obs = ((t_camera *)args->scene->cameras->object)->origin;
	y = -(args->scene->viewport->height / 2) - 1;
	while (++y <= args->scene->viewport->height / 2)
	{
		d = new_vector(
args->x * (args->scene->viewplane->width / args->scene->viewport->width),
y * (args->scene->viewplane->height / args->scene->viewport->height), 1);
		rot(d, ((t_camera *)args->scene->cameras->object)->rotation);
		c = trace_ray(*d, args->scene);
		put_pixel(args, ((-(y - (args->scene->viewport->height / 2)))), c);
		free(d);
		((t_camera *)args->scene->cameras->object)->origin = obs;
		args->scene->depth = 3;
	}
	return (free_cpy_scene(args->scene) ? NULL : NULL);
}*/