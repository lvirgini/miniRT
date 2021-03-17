/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:24:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 14:34:34 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		add_color_light(t_color *res, t_color l_color, double ratio)
{
	res->r += l_color.r * ratio;
	res->g += l_color.g * ratio;
	res->b += l_color.b * ratio;
}

t_color		add_color(t_color a, t_color b)
{
	t_color res;

	res.r = a.r + b.r;
	res.g = a.g + b.g;
	res.b = a.b + b.b;
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

/*
** adjust the min 0 and max 255 color.
*/

t_color		adjust_min_max_color(t_color res)
{
	res.r = fmax(0, fmin(255, res.r));
	res.g = fmax(0, fmin(255, res.g));
	res.b = fmax(0, fmin(255, res.b));
	return (res);
}

t_color		adjust_final_obj_color(t_color final_color, t_color obj_color)
{
	t_color res;

	res.r = obj_color.r * (final_color.r / 255);
	res.g = obj_color.g * (final_color.g / 255);
	res.b = obj_color.b * (final_color.b / 255);
	return (adjust_min_max_color(res));
}
