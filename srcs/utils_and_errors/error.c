/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:38:19 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/07 23:05:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_free_minirt(t_app *app, int if_error) 
{
	if (g_scene)
		destroy_scene(*g_scene);
	if (app)
		destroy_application(app);
	exit(if_error);
}

/*
** print error of file
*/

int		file_error(char *location, int error)
{
	ft_putstr("Error in file :\t");
	ft_putstr(location);
	if (error == 1)
		ft_putstr(" : defined twice in file\n");
	else if (error == 2)
		ft_putstr(" : badly defined value\n");
	else if (error == 3)
		ft_putstr(" : is undefined\n");
	else if (error == 4)
		ft_putstr(" : is not a type of element for this minirt\n");
	return (-1);
}

/*
** print error of malloc
*/

int		malloc_error(void)
{
	ft_putstr("Error : Malloc return NULL : allocation problem\n");
	return (-1);
}
