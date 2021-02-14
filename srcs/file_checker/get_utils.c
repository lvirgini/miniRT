/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 11:57:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/14 16:48:59 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Selon si la scene est vide d'objet ou non.
** j'aurai pu faire filo
*/

int			save_obj_in_scene(int type, void *shape)
{
	t_obj		*obj;

	if (!(g_scene->objs))
	{
		if (!(g_scene->objs = malloc_object(type, shape)))
			return (file_error(0, __FILE__, ERR_MALLOC));
	}
	else
	{
		obj = find_last_obj(g_scene->objs);
		if (!(obj->next = malloc_object(type, shape)))
			return (file_error(0, __FILE__, ERR_MALLOC));
	}
	return (0);
}

/*
** str doit contenir trois nombres separer par des virgules
** ex: 3.5,0.0,5.0 equivalent a  x,y,z
** split :
**	tab 0 (x)	tab 1 (y)	tab 2 (z)
**	3.5			0.0			5.0				// EXAMPLE //
*/

int			get_coord_from_line(t_vec3 *result, char *line)
{
	char	**tab;

	tab = ft_split(line, ',');
	if (tab_len(tab) < 3)
	{
		free_tab(tab);
		return (-1);
	}
	result->x = ft_atof(tab[0]);
	result->y = ft_atof(tab[1]);
	result->z = ft_atof(tab[2]);
	free_tab(tab);
	return (0);
}

/*
** line doit contenir trois nombres allant de 0 a 255 separe par des virgules
** ex: "100,0,255" etant "rouge, vert, bleu"
** puis split :
**	tab 0 		tab 1 		tab 2
**  "rouge"		"vert"		"bleu"
*/

int			get_color_from_line(t_color *result, char *line)
{
	char	**tab;
	t_vec3	tmp;

	tab = ft_split(line, ',');
	if (tab_len(tab) < 3)
	{
		free_tab(tab);
		return (-1);
	}
	tmp.x = ft_atoi(tab[0]);
	tmp.y = ft_atoi(tab[1]);
	tmp.z = ft_atoi(tab[2]);
	free_tab(tab);
	if (check_in_range(tmp, 0.0, 255.0))
		return (-1);
	result->r = tmp.x;
	result->g = tmp.y;
	result->b = tmp.z;
	return (0);
}
