/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:14:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/24 19:29:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "minirt.h"

# define SPECULAR_VALUE 45
# define MAX_REBOUND	10

int			check_image_transform(int key, t_image *img, t_app *app);
int			malloc_caps_cylinder(t_cyl *cyl, t_app *app);

#endif
