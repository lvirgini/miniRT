/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_application.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:36:59 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/04 17:13:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Mise a zero d'une t_app / creation sans malloc
*/

t_app	create_application(void)
{
	t_app app;

	ft_bzero(&app, sizeof(app));
	return (app);
}

/*
** Creation avec malloc d'une t_app
*/

t_app	*malloc_application(void)
{
	t_app	*app;

	if (!(app = (t_app *)malloc(sizeof(app))))
		return (NULL);
	*app = create_application();
	app->scene = malloc_scene();
	return (app);
}

/*
** free du contenu d'une t_app
*/

void	destroy_application(t_app to_destroy)
{
	free_scene(to_destroy.scene);
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
