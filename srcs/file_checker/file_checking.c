/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:47:44 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/20 21:51:15 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		get_cam_list_circle(t_camera *cam)
{
	t_camera *last;

	last = cam;
	while (last->next)
		last = last->next;
	last->next = cam;
}

/*
** check if a parameter is missing
** verifie s'il ne manque pas un parametre obligatoire pour le scene.
** Minimum : camera, resolution, lumiere ambiante
*/

static int		check_file_is_complete(const t_vec2 size, t_app *app)
{
	if (size.x == 0 || size.y == 0)
		return (file_error(app, "RESOLUTION", ERR_UNDEF));
	if (app->scene->light_ambiant == NULL)
		return (file_error(app, "AMBIANT LIGHT", ERR_UNDEF));
	if (app->scene->cam == NULL)
		return (file_error(app, "CAMERA", ERR_UNDEF));
	get_cam_list_circle(app->scene->cam);
	return (0);
}

/*
** Checking if file is .rt;
*/

static int		file_type(char *str)
{
	if (ft_strcmp(str + ft_strlen(str) - 3, ".rt"))
		return (-1);
	return (0);
}

/*
** Checking arguments of the program.
** minimum required is file.rt
*/

int				file_checking(int ac, char **av, t_app *app)
{
	if (ac == 3 && (ft_strcmp(av[2], "--save") || ft_strcmp(av[2], "-save")))
		app->save = 1;
	//if (ac >= 4 && (ft_strcmp(av[2], "-sepia"))
	if (ac < 2)
		return (file_error(app, 0, ERR_NO_FILE));
	if (file_type(av[1]) == -1)
		return (file_error(app, 0, ERR_NOT_RT));
	if (read_file(av[1], app) == -1)
		return (-1);
	return (check_file_is_complete(app->size, app));
}
