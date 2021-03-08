/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_a_supprimer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:03:21 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/08 17:11:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_vec3(t_vec3	v, char *name)
{
	if (name)
		printf("%s : x = %.1lf\ty = %.1lf\tz = %.1lf\n",name, v.x, v.y, v.z);
}

void	print_color(t_color color)
{
	printf("\tR: %.0f\tG: %.0f\tB: %.0f\n", color.r, color.g, color.b);
}

void	print_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		printf("tab %ld : |%s|\n", i, tab[i]);
		i++;
	}
}

void		print_sphere(t_sphere *sp)
{
	printf("SPHERE\n\t");
	print_vec3(sp->pos, "pos");
	printf("\tradius: %.1lf\n\ttexture = %d\n\tcolor =", sp->radius, sp->texture);
	print_color(sp->color);
}

void		print_plane(t_plane *pl)
{
	printf("PLANE:\n\ttexture = %d\n\t", pl->texture);
	print_vec3(pl->pos, "pos");
	printf("\t");
	print_color(pl->color);
}
void		print_all_obj(t_obj *obj)
{
	size_t	i;

	i = 0;
	while (obj)
	{
		printf("obj %ld : adresse : %p	TYPE : %d\n", i++, obj, obj->type);
		//printf("obj->next = %p\n", obj->next);
		if (obj->type == SPHERE)
			print_sphere((t_sphere *)obj->shape);
		if (obj->type == PLANE)
			print_plane((t_plane *)obj->shape);
		obj = obj->next;
		printf ("\n");
	}
}

void		print_all_cam(t_camera *cam)
{
	size_t	i;

	i = 0;
	if (cam)
	{	
		printf("%p : adresse de la scene->cam", cam);
		printf("Camera %ld :\nfov = %lf\n",i++, cam->fov);
		print_vec3(cam->pos, "cam->pos");
		print_vec3(cam->orient, "cam->orient");
	}
	printf ("\n");
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
	printf ("\n");
	while (l)
	{
		printf("Light %ld : ratio = %lf\n", i++, l->ratio);
		print_vec3(l->pos, "\t l->pos");
		print_color(l->color);
		l = l->next;
	}

	printf ("\n");
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
		printf("MAX RATIO = %lf\n", scene->total_intens);
	}
	printf("*-----------------------END----------------------------------*\n");
}
