/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:19:10 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/25 13:44:14 by lvirgini         ###   ########.fr       */
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

# include "minirt_matrix_4x4.h"
# include "minirt_define.h"
# include "minirt_color.h"
# include "minirt_image.h"
# include "minirt_objet.h"
# include "minirt_scene.h"
# include "minirt_application.h"
# include "minirt_intersection.h"
# include "minirt_pixel.h"
# include "minirt_parsing.h"
# include "minirt_error.h"
# include "minirt_bonus.h"

#endif
