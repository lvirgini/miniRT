/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 11:57:28 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/29 13:57:20 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** str doit contenir trois nombre separer par des virgule
** ex: 3.5,0.0,5.0 equivalent a  x,y,z
*/

static int	tab_len(char **tab)
{
	int 	i;

	i = 0;
	while (tab++)
		i++;
	return (i);
}

t_vec3	get_line_to_coordonnees(char *line)
{
	char 	**tab;
	t_vec3	result;

	tab = ft_split(line, ',');
	if (tab_len(tab) != 3)
		minirt_exit_on_error(2); ///
	if (line_get_double(tab[0], &result.x) == -1
			|| line_get_double(tab[1], &result.y) == -1
			|| line_get_double(tab[2], &result.z) == -1)
	minirt_exit_on_error(3); ///
	return (result);
}

