/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_line_recup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:27:23 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/03 16:03:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Recupere le prochain nombre de la chaine *str, le retourne en INT.
*/

int		line_recup_number_float(char *str, float *result)
{
	char 	*tmp;
	int 	integer_part;

	line_recup_number_int(str, &integer_part);
	if (str && *str == '.')
	{
		str++;
		line_recup_number_int(str, (int *)result);
	}
	else 
		*result = 0;
	while (*result >= 1)
		*result /= 10;
	result += integer_part;
	return (0);
}

/*
** Recupere le prochain nombre de la chaine *str, le retourne en INT.
*/

int		line_recup_number_int(char *str, int *result)
{
	char 	*tmp;
	int		i;

	i = 0;
	while (str && (ft_isalpha(*str) || ft_isspace(*str)))
		str++;
	i = recup_nb_negative(tmp, *str);
	while(str && ft_isdigit(str[i]))
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	str += i;
	if (i != 0)
	{	
		*result = atoi(tmp);
		return (0); // annuler le malloc de atoi
	}
	return (-1);
}

/*
** 
*/

int		recup_nb_negative(char *dst, char c)
{
	if (c == '-')
	{
		dst[0] = c;
		dst[1] = '\0';
		return (1);
	}
	return (0);
}