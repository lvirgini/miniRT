/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:38:26 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/26 11:05:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int handle_key(int key, void **param)
{
	t_color *color;
	t_color *color2;

	color = ((void **)(param))[0];
	color2 = ((void **)(param))[1];

	printf("key = %d\n", key);
	printf("param = %p\n", param);
	printf("param[0] = %p\n", param + 1);
	
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_SPACE)
			;
	else if (key == KEY_R)
		color->r = color->r < 245 ? color->r + 10 : 255;
	else if (key == KEY_G)
		color->g = color->g < 245 ? color->g + 10 : 255;
	else if (key == KEY_B)
		color->b = color->b < 245 ? color->b + 10 : 255;
	return (0);
}
