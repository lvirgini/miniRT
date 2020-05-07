/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_application.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:36:59 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/07 15:51:15 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Mise a zero d'une t_app / creation sans malloc
*/

t_app	create_application(int x, int y, char *title)
{
	t_app app;
				
	app.size = create_vec2(x, y);
	app.mlx_ptr = mlx_init(); // 2x car sinon ca ne marche pas ....
	app.mlx_ptr = mlx_init();
	app.win_ptr = mlx_new_window(app.mlx_ptr, x, y, title);
	return (app);
}

/*
** Creation avec malloc d'une t_app
*/

t_app	*malloc_application(int x, int y, char *title)
{
	t_app	*app;

	if (!(app = (t_app *)malloc(sizeof(app))))
		return (NULL);
	*app = create_application(x, y, title);
	return (app);
}

/*
** free du contenu d'une t_app
*/

void	destroy_application(t_app to_destroy)
{
	//free_scene(to_destroy.scene);
	mlx_destroy_window(to_destroy.mlx_ptr, to_destroy.win_ptr);
	(void)to_destroy;
}

/*
** free de l'integralite d'une t_app
*/

void	free_application(t_app *to_free)
{
	destroy_application(*to_free);
	free(to_free);
}

void	application_create_content(void)
{
	g_app->img = malloc_image(g_app->size.x, g_app->size.y);
	//app->scene = malloc_scene();
}
