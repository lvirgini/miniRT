/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:47:44 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/29 16:04:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** print error of file
*/

int		file_error(int error)
{
	if (error == 1)
		ft_putstr_fd("ERROR : no file in first argument\n", 1);
	if (error == 2)
		ft_putstr_fd("ERROR : file is not .rt\n", 1);
	if (error == 3)
		ft_putstr_fd("ERROR : file not read by the (read) function\n", 1);
	return (-1);
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
** Checking if file.rt is correct.
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
