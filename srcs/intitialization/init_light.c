/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:45:01 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/26 20:19:54 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion des t_light : creation, malloc et free.
*/

t_light		create_light(t_vec3 pos, double ratio, t_color color)
{
	t_light	light;

	light.pos = pos;
	light.ratio = ratio;
	light.color = color;
	return (light);
}

t_light		*malloc_light(t_vec3 pos, double ratio, t_color color)
{
	t_light	*light;

	if (!(light = malloc(sizeof(t_light))))
		minirt_exit_on_error(1);
	*light = create_light(pos, ratio, color);
	return (light);
}

void		free_light(t_light *light)
{
	free(light);
}

