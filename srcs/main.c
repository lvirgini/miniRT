/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/27 11:57:23 by lvirgini         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	int		x = 800;
	int		y = 600;
	char	*title = "Premiers test";


	if (!(g_app = malloc_application(x, y, title)))
		return (file_error("MALLOC", 1));
	g_app->img = malloc_image(x, y);
	/*if (file_checking(ac, av) == -1)
		return (-1);*/

	void *param[5];
	param[0] = malloc_color(0, 0, 0, 255);
	param[1] = malloc_color(0, 0, 255, 125);
	param[2] = malloc_color(255, 0, 0, 255);
	param[3] = malloc_color(0, 255, 0, 125);
	param[4] = malloc_color(255,255,255,255);



	raytracing_test(param);
 	mlx_key_hook(g_app->win_ptr,handle_key, param);
//	mlx_hook(g_app->win_ptr, 3, 2, handle_key, &param);
//	mlx_loop_hook(g_app->mlx_ptr, raytracing_test, param);
//premiers_test(param);
	return (run_application());


	if(ac == 0 && av[0] == 0) // pour -Werror
		return(0); //
}
