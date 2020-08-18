/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 11:57:28 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/18 17:37:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** str doit contenir trois nombre separer par des virgules
** ex: 3.5,0.0,5.0 equivalent a  x,y,z
*/

t_vec3		get_line_to_coordonnees(char *line)
{
	char 	**tab;
	t_vec3	result;

	tab = ft_split(line, ',');
	if (tab_len(tab) < 3)
		minirt_exit_on_error(2); ///
	if (line_get_double(tab[0], &result.x) == -1
			|| line_get_double(tab[1], &result.y) == -1
			|| line_get_double(tab[2], &result.z) == -1)
	minirt_exit_on_error(3); ///
	return (result);
}

/*
** str doit contenir trois nombre separer par des virgules
** ex: 3.5,0.0,5.0 equivalent a  x,y,z
** split : 
**	tab 0 (x)	tab 1 (y)	tab 2 (z)
**	3.5			0.0			5.0
*/

int			get_coord_from_line(t_vec3 *vec, char *line)
{
	char	**tab;
	
	tab = ft_split(line, ',');
	if (tab_len(tab) < 3)
	{
		free_tab(tab);
		return(-1);
	}
	print_tab(tab);
	vec->x = ft_atof(tab[0]);
	vec->y = ft_atof(tab[1]);
	vec->z = ft_atof(tab[2]);
	free_tab(tab);
	printf("x = %f	y = %f	z = %lf\n", vec->x, vec->y, vec->z);
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
	char 	**tab;

	tab = ft_split(line, ',');
	if (tab_len(tab) < 3)
	{
		free_tab(tab);
		return(-1);
	}
	result->r = ft_atoi(tab[0]);
	result->g = ft_atoi(tab[1]);
	result->b = ft_atoi(tab[2]);
	free_tab(tab);
	printf("r = %d	g = %d	b = %d\n", result->r, result->g, result->b);
	return (0);
}
