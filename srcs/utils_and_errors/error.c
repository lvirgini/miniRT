/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:38:19 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/16 09:58:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** All message error with enum e_nb_error in file_error.h
*/

static char		*g_msg_error[NB_ERR] =
{
	"\n",
	" : no file in first argument\n",
	" : file is not .rt\n",
	" : file cannot be read by the (read) function. maybe not exist ? \n",
	" : defined twice in file\n",
	" : badly defined value\n",
	" : is undefined\n",
	" : is not a type of element for this minirt\n",
	" : (open) return bad fd : uncreate bmp file\n",
	" : Malloc return NULL : allocation problem\n",
	" : mlx_init() return NULL (allocation problem ?)\n"
	" : mlx_new_window() return NULL( allocation problem ?)\n"
};

static void		print_error(char *location, unsigned int n_error)
{
	ft_putstr("ERROR  ");
	if (location)
		ft_putstr(location);
	if (n_error && n_error < NB_ERR)
		ft_putstr(g_msg_error[n_error]);
}

/*
** destroy and free all malloc in minirt
*/

static void		free_all_minirt(t_app *app, t_scene *scene)
{
	if (app)
		destroy_application(app);
	if (scene)
		destroy_scene(*scene);
}

/*
** free all and exit
*/

void			exit_free_minirt(t_app *app, char *location,
								unsigned int if_error)
{
	if (if_error)
		print_error(location, if_error);
	free_all_minirt(app, g_scene);
	exit(if_error);
}

/*
** file error and return -1 // no exit
*/

int				file_error(t_app *app, char *location, unsigned int n_error)
{
	print_error(location, n_error);
	printf("%s", (char *)strerror(errno));
	free_all_minirt(app, g_scene);
	return (-1);
}
