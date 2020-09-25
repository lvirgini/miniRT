/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:47:44 by lvirgini          #+#    #+#             */
/*   Updated: 2020/09/25 17:49:22 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** verifie s'il ne manque pas un parametre obligatoire pour le scene.
** Minimum : camera, resolution
*/

static int		check_file_is_complete(void)
{
	if (g_app->size.x == 0 && g_app->size.y == 0)
		file_error("RESOLUTION", 3);
	if (g_app->scene->light_ambiant == NULL)
		file_error("AMBIANT LIGHT", 3);
	if (g_app->scene->cam == NULL)
		file_error("CAMERA", 3);
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

int				file_checking(int ac, char **av)
{

	if (ac == 3 && (ft_strcmp(av[2], "--save") || ft_strcmp(av[2], "-save")))
		return (0);	//// SAUVEGARDE EN IMAGE A FAIRE
	if (ac < 2)
		file_error("no file in first argument", 0);
	if (file_type(av[1]) == -1)
		file_error("file is not .rt", 0);
	//*g_app = create_application(1024, 1024, "test1");
	read_file(av[1]);
	check_file_is_complete();
	return (0); 
}
