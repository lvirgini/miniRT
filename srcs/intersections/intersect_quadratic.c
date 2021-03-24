/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_quadratic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:12:39 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/24 17:13:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Resolution de l'equation du second degres
** a*t² + b*t + c = 0
** delta = b² - 4ac
** si delta < 0 pas d'intersection.
** si delta == 0 intersection unique : t = -b/ 2a
** t1 = -b - racine(delta) / 2a  -> plus proche
** t2 = -b + racine(delta) / 2a  -> plus loin
*/

double	quadratic_equation(double a, double b, double c, double t[2])
{
	double delta;

	if ((delta = (b * b) - (4.0 * a * c)) < 0)
		return (0);
	else if (delta == 0)
	{
		t[0] = -b / (2 * a);
		t[1] = t[0];
	}
	else
	{
		t[0] = (-b - sqrt(delta)) / (2 * a);
		t[1] = (-b + sqrt(delta)) / (2 * a);
	}
	if (t[1] < RAY_T_MIN)
		return (0);
	if (t[0] > RAY_T_MIN && t[0] < RAY_T_MAX)
		return (t[0]);
	return (t[1]);
}
