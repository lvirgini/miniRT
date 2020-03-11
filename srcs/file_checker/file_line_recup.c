/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_line_recup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:27:23 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/11 17:27:23 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "../../includes/minirt.h"

/*
** Recupere le prochain nombre de la chaine *str, le retourne en INT.
*/

int		line_get_float(char *str, float *result)
{
	int		neg;
	int		i;

	i = 0;
	neg = 1;
	while (str[i] && (ft_isalpha(str[i]) || ft_isspace(str[i])))
		i++;
	if(str[i] == '-' && (++i > 0))
		neg = -1;
	if (ft_isdigit(str[i]))
	{
		*result = ft_atof(str + i) * neg;
		while (ft_isdigit(str[i++]))
			;
		return (i);
	}
	return (-1);
}

/*
** Recupere le prochain nombre de la chaine *str, le retourne en INT.
*/

int		line_get_int(char *str, int *result)
{
	int		neg;
	int		i;

	i = 0;
	neg = 1;
	while (str[i] && (ft_isalpha(str[i]) || ft_isspace(str[i])))
		i++;
	if(str[i] == '-' && (++i > 0))
		neg = -1;
	if (str[i] && ft_isdigit(str[i]))
	{
		*result = atoi(str + i) * neg;
		while (ft_isdigit(str[i++]))
			;
		return (i);
	}
	return (-1);
}

/*
** Recupere un t_color
*/

int		line_get_t_color(char *s, t_color *res)
{
	int i;
	int j;
	int recup[3];
	
	i = 0;
	j = -1;
	while (++j < 4)
	{
		i = line_get_int(s + i, recup + j);
		if (i < 0 || (recup[j] < 0 && recup[j] > 255))
			return (-1);
		if (j < 3 && s[i] != ',')
			return (-1);
		i += 1;
	}
	res->r = recup[0];
	res->g = recup[1];
	res->b = recup[2]; //// a VERIFIER ORDRE DES RGB;
	return (i);
}
