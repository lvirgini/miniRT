/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:38:19 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/16 11:53:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int		exit_program(void)
{
	exit(0);
	return (0);
}

void	minirt_exit_on_error(int error)
{
	if (error == 1)
		ft_putstr("Error : Malloc return NULL : allocation problem\n");
	exit_program();

}