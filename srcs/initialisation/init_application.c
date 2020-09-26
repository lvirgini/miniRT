/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_application.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:36:59 by lvirgini          #+#    #+#             */
/*   Updated: 2020/09/26 15:47:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion des t_app : creation, malloc, destroy et free.
** avec la mlx :
** 		mlx_ptr recupere le retour de mlx_init
** 		win_ptr recupere le retour de mlx_new_window.
*/

t_app	*malloc_application(void)
{
	t_app	*app;

	if (!(app = (t_app *)malloc(sizeof(app))))
		minirt_exit_on_error(1);
	ft_bzero(app, sizeof(app));
	return (app);
}

/*
** free du contenu d'une t_app
*/

void	destroy_application(t_app to_destroy)
{
	free_scene(to_destroy.scene);
	mlx_destroy_window(to_destroy.mlx_ptr, to_destroy.win_ptr);
}

/*
** free de l'integralite d'une t_app
*/

void	free_application(t_app *to_free)
{
	destroy_application(*to_free);
	free(to_free);
}
