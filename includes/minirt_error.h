/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 11:25:29 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/26 16:40:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERROR_H
# define MINIRT_ERROR_H

# include "minirt.h"

# define NB_ERR	12

typedef enum e_nb_error	t_nb_error;

/*
** see error.c for correspondance messages
*/

enum	e_nb_error
{
	ERR_NONE,
	ERR_NO_FILE,
	ERR_NOT_RT,
	ERR_NOT_READ,
	ERR_DEF_TWICE,
	ERR_BAD_VALUE,
	ERR_UNDEF,
	ERR_NOT_TYPE,
	ERR_FD,
	ERR_MALLOC,
	ERR_MLX_INIT,
	ERR_MLX_NEW_WINDOW,
};

int			file_error(char *location, unsigned int nb_error);
void		exit_free_minirt(t_app *app, char *location, int if_error);

#endif
