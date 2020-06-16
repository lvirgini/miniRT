/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:13:25 by lvirgini          #+#    #+#             */
/*   Updated: 2020/06/16 12:01:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion de la structure t_obj : creation, malloc, free.
*/

t_obj		create_object(int type, void *shape)
{
	t_obj	obj;
	
	obj.type = type;
	obj.shape = shape;
	obj.next = NULL;
	return (obj);
}

t_obj 		*malloc_object(int type, void *shape)
{
	t_obj	*obj;

	if (!(obj = malloc(sizeof(t_obj))))
		minirt_exit_on_error(1);
	*obj = create_object(type, shape);
	return (obj);
}

/*
** free un seul t_obj
*/

void		free_object(t_obj *obj)
{
	free(obj);
}

/*
** Free de tous les t_obj en prenant *obj comme le premier element.
*/

void		free_all_object(t_obj *obj)
{
	t_obj	*tmp;

	while (obj)
	{
		tmp = obj->next;
		free_object(obj);
		obj = tmp;
	}
}
