/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/01 17:41:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene		*g_scene;

int		main(int ac, char **av)
{
	g_scene = malloc_scene();
	if (file_checking(ac, av) == -1)
		return (-1);
	free_scene(g_scene);
	return (0);
}