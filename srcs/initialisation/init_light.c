/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:45:01 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/16 11:48:20 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion des t_light : malloc et free.
*/

t_light		*malloc_light(t_vec3 pos, double ratio, t_color color)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light->pos = pos;
	light->ratio = ratio;
	light->color = color;
	light->next = NULL;
	g_scene->total_intens += ratio;
	return (light);
}

void		free_light(t_light *light)
{
	t_light	*tmp;

	while (light)
	{
		tmp = light->next;
		free(light);
		light = tmp;
	}
}
