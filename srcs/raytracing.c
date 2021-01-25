/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:36:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/01/25 19:41:05 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	exit_minirt(void)
{
	exit(0);
	return (0);
}

/*
** Mise en place du raytracing
**	- clear_application = couleur de fond
** 	- parcours l'image pour modifier la couleur de chaque pixel s'il y a
**		 intersection
**	- affiche l'image resultante sur la fenetre.
**	- mise en place des actions suivant la touche clavier ou souris.
**	- quitte le programme si la fenetre est fermee.
*/

int			generate_raytracing(void *param) // param a determier
{
	t_app	*app;

	app = (t_app *)param;
	clear_application(create_color(25, 25, 25, 255), app); // a determiner

	browse_image_for_intersection(g_scene->cam, app->size.x, app->size.y, app->img);
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img->img_ptr, 0, 0);

 	mlx_key_hook(app->win_ptr, handle_key, param);
	mlx_mouse_hook(app->win_ptr, handle_mouse, g_scene->objs);
	mlx_hook(app->win_ptr, 17, (1L << 17), exit_minirt, 0);
	return (0);
}

/*
** Derniere chose a faire : demarrer l'application.
*/

int			run_application(t_app *app)
{
	mlx_loop(app->mlx_ptr);
	exit_free_minirt(app, 0);
	return (0);
}

int			generate_content(t_app *app)
{
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr, app->size.x,
					app->size.y, "title");
	if (!(app->img = malloc_image(app->size.x, app->size.y, app->mlx_ptr)))
		return (malloc_error());
	return (0);
}
