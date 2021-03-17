/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_minirt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:46:23 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 14:19:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** for mlx event : exit and free all before exit
*/

static int		exit_minirt(t_app *app)
{
	exit_free_minirt(app, 0, 0);
	return (0);
}

/*
** last to do : run application :
** put image to windows
** create all event mlx
** loop
*/

int				run_application(t_app *app)
{
	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr,
			app->img->img_ptr, 0, 0);
	mlx_hook(app->win_ptr, 33, StructureNotifyMask, exit_minirt, app);
	mlx_key_hook(app->win_ptr, handle_key, app);
	mlx_mouse_hook(app->win_ptr, handle_mouse, app->scene->objs);
	mlx_loop(app->mlx_ptr);
	exit_free_minirt(app, 0, 0);
	return (0);
}
