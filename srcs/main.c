/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/19 10:24:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// intersection cylindre
// integration de "bonus".

static void	print_help_key(void)
{
	ft_putstr("* -------------------------------------------------------- *\n");
	ft_putstr("exit program : Echap\n");
	ft_putstr("switch camera : Space\n");
	ft_putstr("Move camera position : Z Q S D W X\n");
	ft_putstr("Move camera orient x : 4 6 	y: 8 2 	z: 9 3\n");
	ft_putstr("Use the mouse wheel on a object to grow it or get it smaller\n");
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
		return (-1);
	print_all_scene(app.scene);
	generate_mlx_content(&app);
	generate_raytracing((void *)&app);
	print_help_key();
	if (app.save == 1)
		return (generate_bmp_file(&app));
	return (run_application(&app));
}
