/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:47:44 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/07 15:38:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** print error of file
*/

int		file_error(char *location, int error)
{
	ft_putstr("Error in file :\n");
	if (location)
		ft_putstr(location);
	if (error == 0)
		;
	else if (error == 1)
		ft_putstr("defined twice in file\n");
	else if (error == 2)
		ft_putstr("badly defined value\n");
	else if (error == 1)
		ft_putstr("\n");
	else if (error == 1)
		ft_putstr("\n");
	else if (error == 1)
		ft_putstr("\n");
	else if (error == 1)
		ft_putstr("\n");
	else if (error == 1)
		ft_putstr("\n");
	else if (error == 1)
		ft_putstr("\n");
	else if (error == 1)
		ft_putstr("\n");
	
	return (-1);
}

/*
** Checking if file is .rt;
*/

static int		file_type(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (ft_strcmp(str + len - 3, ".rt"))
		return (-1);
	return (0);
}

/*
** Checking arguments of the program.
** minimum required is file.rt
*/

int		file_checking(int ac, char **av)
{
	if (ac == 3 && ft_strcmp(av[2], "--save"))
		;
	if (ac < 2)
		return (file_error("no file in first argument", 0));
	if (file_type(av[1]) == -1)
		return (file_error("file is not .rt", 0));
	return (read_file(av[1]));
}
