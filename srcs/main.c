/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/11 19:43:30 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_app		*g_app;

int		main(int ac, char **av)
{
	if (!(g_app = malloc_application()))
		return (file_error("MALLOC", 1)); // errno ?
	if (file_checking(ac, av) == -1)
		return (-1);
	//free_application(g_app);
	return (0);
}