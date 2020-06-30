/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:19:10 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/30 10:14:53 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
** INCLUDES de librairies officielles
*/

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h> //

/*
** INCLUDES de librairies internes
*/

# include "libft.h"
# include "ft_printf.h"
# include "ft_vector.h"
# include "mlx.h"
# include "mlx_int.h"

/*
** INCLUDES propre a minirt
*/

# include "minirt_define.h"
# include "minirt_color.h"
# include "minirt_image.h"
# include "minirt_objet.h"
# include "minirt_scene.h"
# include "minirt_application.h"

# include "minirt_drawing.h"
# include "minirt_parsing.h"
# include "minirt_intersection.h"

int		exit_program(void);
void	minirt_exit_on_error(int error);
int		handle_mouse(int button, int x,int y, void *param);
void	print_vec3(t_vec3 vec); ///


extern t_app	*g_app;
typedef	unsigned char	t_uchar;
#endif
