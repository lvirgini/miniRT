/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_line_recup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:27:23 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/04 15:32:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Recupere le prochain nombre de la chaine *str, le retourne en INT.
*/

int		line_recup_number_float(char *str, float *result)
{
	int		neg;
	int		i;

	i = 0;
	while (str[i] && (ft_isalpha(str[i]) || ft_isspace(str[i])))
		i++;
	neg = str[i] == '-' ? -1 : 1;
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

int		line_recup_number_int(char *str, int *result)
{
	int		neg;
	int		i;

	i = 0;
	while (str[i] && (ft_isalpha(str[i]) || ft_isspace(str[i])))
		i++;
	neg = str[i] == '-' ? -1 : 1;
	if (str[i] && ft_isdigit(str[i]))
	{
		*result = atoi(str + i) * neg;
		while (ft_isdigit(str[i++]))
			;
		return (i);
	}
	return (-1);
}
