/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:38:26 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/07 18:54:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int handle_key(int key, void *param[])
{
	printf("key = %d\n", key);
	printf("param = %p", param[1]);
	
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_SPACE)
			param[0] = (void *)malloc_color(0, 255, 0, 255);

	return (0);
}
