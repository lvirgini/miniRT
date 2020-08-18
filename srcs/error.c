/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:38:19 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/18 14:19:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int		exit_program(void)
{
	exit(0);
	return (0);
}

/*
** print errors of everything else than file.
*/

void	minirt_exit_on_error(int error)
{
	if (error == 1)
		ft_putstr("Error : Malloc return NULL : allocation problem\n");
	exit_program();
}

/*
** print error of file
*/

void	file_error(char *location, int error)
{
	ft_putstr("Error in file :\t");
	if (location)
		ft_putstr(location);
	if (error == 0)
		;
	else if (error == 1)
		ft_putstr(" : defined twice in file");
	else if (error == 2)
		ft_putstr(" : badly defined value");
	else if (error == 3)
		ft_putstr(" : is undefined");
	else if (error == 4)
		ft_putstr(" : is not a type of element for this minirt");
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
	ft_putstr("\n");
	exit_program();
}
