/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/28 18:12:34 by lvirgini         ###   ########.fr       */
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

void	generate_scene(void)
{
	t_camera *cam = malloc_camera(60 * PI / 180, create_vec3(0, 0, 0), create_vec3(0, 0, 1));
	t_sphere *sphere = malloc_sphere(create_vec3(0, 0, -55), 20, create_color(0, 0, 200, 200));

	t_obj	*obj;
	obj = malloc_object(SPHERE, sphere);
	g_app->scene = malloc_scene(cam, obj);
}


int		main(int ac, char **av)
{
	int		x = 800;
	int		y = 600;
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

 	mlx_key_hook(g_app->win_ptr,handle_key, param);
	mlx_mouse_hook (g_app->win_ptr,handle_mouse, g_app->scene->objs);

//	mlx_hook(g_app->win_ptr, 3, 2, handle_key, &param);
//	mlx_loop_hook(g_app->mlx_ptr, raytracing_test, param);
//premiers_test(param);



	t_sphere 	*sphere;

	sphere = g_app->scene->objs->shape;

	printf("%p g_app->scene->obj->shape\n", g_app->scene->objs->shape);
	printf("%p sphere\n", sphere);
	printf("radius = %f\n", sphere->radius);
	



	printf("%p get END 3 gapp->obj\n", g_app->scene->objs);
	printf("%p get END 3 *gapp->obj\n", *g_app->scene->objs);

	return (run_application());

	if(ac == 0 && av[0] == 0) // pour -Werror
		return(0); //
}
