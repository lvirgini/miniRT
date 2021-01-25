/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:47:44 by lvirgini          #+#    #+#             */
/*   Updated: 2021/01/25 17:33:45 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** check if a parameter is missing
** verifie s'il ne manque pas un parametre obligatoire pour le scene.
** Minimum : camera, resolution, lumiere ambiante
*/

static int		check_file_is_complete(const t_vec2 size)
{
	if (size.x == 0 || size.y == 0)
		return (file_error("RESOLUTION", 3));
	if (g_scene->light_ambiant == NULL)
		return (file_error("AMBIANT LIGHT", 3));
	if (g_scene->cam == NULL)
		return (file_error("CAMERA", 3));
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
		return (0);	//// SAUVEGARDE EN IMAGE A FAIRE
	if (ac < 2)
		return (file_error("no file in first argument", 0));
	if (file_type(av[1]) == -1)
		return (file_error("file is not .rt", 0));
	if (read_file(av[1], app) == -1
	|| check_file_is_complete(app->size))
		return (-1);
	return (0);
}
