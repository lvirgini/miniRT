/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:13:25 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/07 23:07:48 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Gestion de la structure t_obj
*/

t_obj		*malloc_object(int type, void *shape)
{
	t_obj	*obj;

	if (!(obj = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	obj->type = type;
	obj->shape = shape;
	obj->next = NULL;
	return (obj);
}

/*
** free du contenu de l'objet
*/

void		free_object_shape(void *shape, int type)
{
	if (type == 1)
		free_sphere((t_sphere *)shape);
	else if (type == 2)
		free_plane((t_plane *)shape);
	else if (type == 3)
		free_square((t_square *)shape);
	else if (type == 4)
		free_cyl((t_cyl *)shape);
	else if (type == 5)
		free_triangle((t_triangle *)shape);
}

/*
** Free de tous les t_obj en prenant *obj comme le premier element.
*/

void		free_all_objects(t_obj *obj)
{
	t_obj	*tmp;

	while (obj)
	{
		tmp = obj->next;
		free_object_shape(obj->shape, obj->type);
		free(obj);
		obj = tmp;
	}
}
