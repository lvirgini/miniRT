/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:47:44 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 14:17:49 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** check if a parameter is missing
** verifie s'il ne manque pas un parametre obligatoire pour le scene.
** Minimum : camera, resolution, lumiere ambiante
*/

static int		check_file_is_complete(const t_vec2 size, t_scene *scene)
{
	if (size.x == 0 || size.y == 0)
		return (file_error(0, "RESOLUTION", ERR_UNDEF));
	if (scene->light_ambiant == NULL)
		return (file_error(0, "AMBIANT LIGHT", ERR_UNDEF));
	if (scene->cam == NULL)
		return (file_error(0, "CAMERA", ERR_UNDEF));
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
	if (ac < 2)
		return (file_error(app, 0, ERR_NO_FILE));
	if (file_type(av[1]) == -1)
		return (file_error(app, 0, ERR_NOT_RT));
	if (read_file(av[1], app) == -1)
		return (-1);
	return (check_file_is_complete(app->size, app->scene));
}
