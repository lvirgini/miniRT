/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:46:07 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/20 19:35:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		create_color(double r, double g, double b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
