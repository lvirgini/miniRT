/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/03 17:23:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		return (generate_bmp_file(&app));
	return (run_application(&app));
}
