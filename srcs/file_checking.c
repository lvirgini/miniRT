/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:47:44 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/03 13:06:48 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** print error of file
*/

int		file_error(char *error)
{
//	ft_printf("l.%d, %s, %s\n", _LINE_, _FUNCTION_, _FILE_);
	ft_printf("Error : %s\n", error);
	return (-1);
}

/*
** Checking if file is .rt;
*/

int		file_type(char *str)
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
		return (file_error("no file in first argument"));
	if (file_type(av[1]) == -1)
		return (file_error("file is not .rt"));
	return (read_file(av[1]));	
}
