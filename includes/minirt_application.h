/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_application.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:44:02 by lvirgini          #+#    #+#             */
/*   Updated: 2020/09/26 17:24:55 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_APPLICATION_H
# define MINIRT_APPLICATION_H

# include "minirt.h"

typedef struct s_app		t_app;

/*
** s_app :
**		mlx_ptr : le retour de mlx_init(), correspond a un tableau de pointeur
**		des fonctions de la mlx.
**		win_ptr : retour de mlx_new_window(), correspond a la fenetre a l'ecran.
**		size : taille de la fenetre en pixel.
**		img : le contenu de la fenetre.
**		scene : toutes les infos concernant la scene.
*/

struct		s_app
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_vec2		size;
	t_image		*img;
	t_scene		*scene;
};

/*
** Fonctions qui gerent la variable t_app
*/

t_app		*malloc_application();
void		destroy_application(t_app to_destroy);
void		free_application(t_app *to_free);
void		application_create_content(void); //
void		clear_application_int(int color); //

#endif
