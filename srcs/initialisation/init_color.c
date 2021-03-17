/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:46:07 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 13:14:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		create_color(t_uchar r, t_uchar g, t_uchar b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
