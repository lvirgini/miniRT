/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_a_supprimer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:03:21 by lvirgini          #+#    #+#             */
/*   Updated: 2020/08/25 11:10:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_vec3(t_vec3	v, char *name)
{
	if (name)
		printf("%s : x = %lf\ty = %lf\tz = %lf\n",name, v.x, v.y, v.z);
}

void	print_color(t_color color)
{
	printf("R: %d\tG: %d\tB: %d\n", color.r, color.g, color.b);
}

void	print_tab(char **tab) ///
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		printf("tab %ld : |%s|\n", i, tab[i]);
		i++;
	}
}

void		print_all_obj(t_obj *obj)
{
	size_t	i;

	i = 0;
	while (obj)
	{
		printf("obj %ld : adresse : %p	TYPE : %d\n", i++, obj, obj->type);
		printf("obj->next = %p\n", obj->next);
		obj = obj->next;
	}
}

void		print_all_cam(t_camera *cam)
{
	size_t	i;

	i = 0;
	if (cam)
	{
		printf("Camera %ld :\nfov = %lf\n",i++, cam->fov);
		print_vec3(cam->pos, "cam->pos");
		print_vec3(cam->orient, "cam->orient");
	}
}

void		print_all_lights(t_light *l, t_light *la)
{
	size_t	i;

	i = 0;
	if (la)
	{
		printf("Light Ambiant : ratio = %lf\n", la->ratio);
		print_vec3(la->pos, "la->pos");
		print_color(la->color);
	}

	if (l)
	{
		printf("Light %ld : ratio = %lf\n", i++, l->ratio);
		print_vec3(l->pos, "\t l->pos");
		print_color(l->color);
	}
}

void		print_all_scene(t_scene *scene)
{
	printf("*------------------------------------------------------------*\n");
	printf("\t*--------------*\n\tALL SCENE\n\t*--------------*\n\n");
	printf("%p : adresse de la t_scene\n", scene);
	printf("*------------------------------------------------------------*\n");
	if (!scene)
		printf("Attention la scene n'existe pas\n");
	else
	{
		print_all_obj(scene->objs);
		printf("*------------------------------------------------------------*\n");
		print_all_cam(scene->cam);
		printf("*------------------------------------------------------------*\n");
		print_all_lights(scene->light, scene->light_ambiant);
		printf("*------------------------------------------------------------*\n");
	}
	printf("*------------------------------------------------------------*\n");
}
