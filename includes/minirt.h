/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:19:10 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/01 19:02:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
**	DEFINES
*/

# define SUCCESS 0
# define FAIL -1

/*
** INCLUDES de librairies officielles
*/

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** INCLUDES de librairies internes
*/

# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"


/*
** INCLUDES propre a minirt
*/

# include "define.h"
# include "struct_objet.h"
# include "struct_image.h"
# include "ft_prototype.h"

extern t_scene	*g_scene;
extern t_app	*g_app;

#endif
