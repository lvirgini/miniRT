/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:36:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/16 10:00:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	exit_minirt(t_app *app)
{
	printf("IN EXIT\n");
	exit_free_minirt(app, 0, 0);
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

int			generate_raytracing(t_app *app) // param a determier
{
	int	ret;

	ret = browse_image_for_intersection(g_scene->cam, app->size.x, app->size.y, app->img);
	if (ret == -1)
		clear_application(create_color(255, 0, 0), app);
	return (0);
}

/*
** Derniere chose a faire : demarrer l'application.
*/

int			run_application(t_app *app)
{
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img->img_ptr, 0, 0);
	mlx_hook(app->win_ptr, 33, StructureNotifyMask, exit_minirt, app);
	mlx_key_hook(app->win_ptr, handle_key, app);
	mlx_mouse_hook(app->win_ptr, handle_mouse, g_scene->objs);
	mlx_loop(app->mlx_ptr);
	exit_free_minirt(app, 0, 0);
	return (0);
}

static void	check_max_display(void *mlx_ptr, t_vec2 *size)
{
	int		max_x;
	int		max_y;

	mlx_get_screen_size(mlx_ptr, &max_x, &max_y);
	if (size->x > max_x)
		size->x = max_x;
	if (size->y > max_y)
		size->y = max_y;
}

int			generate_mlx_content(t_app *app)
{
	app->mlx_ptr = mlx_init();
	if (app->mlx_ptr == NULL)
		exit_free_minirt(app, __FILE__, ERR_MLX_INIT);
	check_max_display(app->mlx_ptr, &app->size);
	if (app->save == 0)
	{
		app->win_ptr = mlx_new_window(app->mlx_ptr, app->size.x,
				app->size.y, "Minirt");
		if (app->win_ptr == NULL)
			exit_free_minirt(app, __FILE__, ERR_MLX_NEW_WINDOW);
	}
	if (!(app->img = malloc_image(app->size.x, app->size.y, app->mlx_ptr)))
		exit_free_minirt(app, __FILE__, ERR_MALLOC);
	return (0);
}
