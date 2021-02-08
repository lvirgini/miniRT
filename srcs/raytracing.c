/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:36:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/08 13:33:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	exit_minirt(void *param)
{
	exit_free_minirt((t_app *)param, 0);
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
	int		ret;

	app = (t_app *)param;
	ret = browse_image_for_intersection(g_scene->cam, app->size.x, app->size.y, app->img);
	if (ret == -1)
		clear_application(create_color(255, 0, 0, 0), app);
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img->img_ptr, 0, 0);
	return (run_application(app));
}

/*
** Derniere chose a faire : demarrer l'application.
*/

int			run_application(t_app *app)
{
	mlx_hook(app->win_ptr, DestroyNotify, StructureNotifyMask, exit_minirt, app);// dont work
 	mlx_key_hook(app->win_ptr, handle_key, app);
	mlx_mouse_hook(app->win_ptr, handle_mouse, g_scene->objs);
	mlx_loop(app->mlx_ptr);
	exit_free_minirt(app, errno);
	return (0);
}

int			generate_content(t_app *app)
{
	app->mlx_ptr = mlx_init();
	if (app->save == 0)
		app->win_ptr = mlx_new_window(app->mlx_ptr, app->size.x,
				app->size.y, "Minirt");
	if (!(app->img = malloc_image(app->size.x, app->size.y, app->mlx_ptr)))
		return (malloc_error());
	return (0);
}
