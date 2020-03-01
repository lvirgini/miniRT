/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:19:10 by lvirgini          #+#    #+#             */
/*   Updated: 2020/03/01 15:39:55 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/*
**	INCLUDES
*/

# define SUCCESS 0
# define FAIL	-1

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


# include "libft.h"
# include "get_next_line.h"
# include "objets.h"
# include "ft_file.h"

/*
** Structures
*/


typedef struct s_img 		t_img;
typedef struct s_app		t_app;
typedef struct s_scene		t_scene;

struct 	s_img
{
	t_vector2	size;
	void		*img_ptr;
	char		*pixels;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
};

struct 	s_app
{
	int 	x;
	int 	y;
	t_img	*img;
	t_scene	*scene;
};

struct s_scene
{
	t_vector
};


/*
**
*/

#endif
