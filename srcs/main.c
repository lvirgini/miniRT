/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 14:42:49 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (app.save == 1)
		return (generate_bmp_file(&app));
	return (run_application(&app));
}
