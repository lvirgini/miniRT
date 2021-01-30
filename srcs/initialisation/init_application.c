/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_application.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:36:59 by lvirgini          #+#    #+#             */
/*   Updated: 2021/01/27 14:50:48 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion des t_app
** avec la mlx :
** 		mlx_ptr recupere le retour de mlx_init
** 		win_ptr recupere le retour de mlx_new_window.
*/

t_app		init_application(void)
{
	t_app	app;

	ft_bzero(&app, sizeof(t_app));
	return (app);
}

/*
** free de l'integralite d'une t_app
*/

void		destroy_application(t_app *app)
{
	if (app)
	{
		if (app->img)
			free_image(app->img, app->mlx_ptr);
		if (app->mlx_ptr)
			mlx_destroy_window(app->mlx_ptr, app->win_ptr);
	}
}
