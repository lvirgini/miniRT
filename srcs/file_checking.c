/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:47:44 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/01 19:04:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** print error of file
*/

int		file_error(int error)
{
	ft_printf("l.%d, %s, %s\n", _LINE_, _FUNCTION_, _FILE_);
	if (error == 1)
		ft_putstr_fd("ERROR : no file in first argument\n", 1);
	if (error == 2)
		ft_putstr_fd("ERROR : file is not .rt\n", 1);
	if (error == 3)
		ft_putstr_fd("ERROR : file cannot be read by the (read) function\n", 1);
/*	if (error == 10)
		ft_putchar_fd(ERROR_10, 1);
*/	return (-1);
}

/*
** Checking if file is .rt;
*/

int		file_type(char *str)
{
	int len;

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
		return (file_error(1));
	if (file_type(av[1]) == -1)
		return (file_error(2));
	return (read_file(av[1]));	
}
