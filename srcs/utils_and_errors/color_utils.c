/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:24:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/15 14:07:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		add_color_light(t_color *res, t_color l_color, double ratio)
{
	res->r = res->r + (l_color.r * ratio);
	res->g = res->g + (l_color.g * ratio);
	res->b = res->b + (l_color.b * ratio);
}


t_color		add_color(t_color a, t_color b)
{
	t_color res;

	res.r = a.r + b.r;
	res.g = a.g + b.g;
	res.b = a.b + b.b;
	return (res);
}

t_color		mul_color(t_color a, t_color b)
{
	t_color		res;

	res.r = a.r * b.r;
	res.g = a.g * b.g;
	res.b = a.b * b.b;
	return (res);
}

t_color		mul_color_ratio(t_color color, double ratio)
{
	t_color		res;

	res.r = color.r * ratio;
	res.g = color.g * ratio;
	res.b = color.b * ratio;
	return (res);
}