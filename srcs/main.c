/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/25 13:56:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_help_key(void)
{
	ft_putstr("* -------------------------------------------------------- *\n");
	ft_putstr("exit program : Echap\n");
	ft_putstr("switch camera : Space\n");
	ft_putstr("Move camera position : Z Q S D W X\n");
	ft_putstr("Move camera orient x : 4 6 	y: 8 2 	z: 9 3\n");
	ft_putstr("switch to image in Sepia mode : T\n");
	ft_putstr("Switch to image in black and white mode : Y\n");
	ft_putstr("* -------------------------------------------------------- *\n");
}

int			main(int ac, char **av)
{
	t_app	app;
	t_scene	scene;

	errno = 0;
	init_application(&app);
	init_scene(&scene);
	app.scene = &scene;
	if (file_checking(ac, av, &app) == -1)
		exit_free_minirt(&app, 0, -1);
	generate_mlx_content(&app);
	generate_raytracing((void *)&app);
	print_help_key();
	if (app.save == 1)
		return (generate_bmp_file(&app));
	return (run_application(&app, app.img));
}
