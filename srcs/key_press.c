/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:38:26 by lvirgini          #+#    #+#             */
/*   Updated: 2020/10/02 12:55:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_help_key(void)
{
	ft_putstr("* -------------------------------------------------------- *\n");
	ft_putstr("Welcome to hellp\n\nPress 'echap' for exit program\n");
	ft_putstr("Press 'space' for change camera\n");
	ft_putstr("Press 'z, q, s, d w, x' for moving this camera position\n");
	ft_putstr("Press the arrow keys, + and - for moving light\n");
	ft_putstr("Use the mouse wheel on a object to grow it or get it smaller\n");
	ft_putstr("* -------------------------------------------------------- *\n");
}

/*
** Gestion des touches du clavier
**** Pour le moment gere la lumiere unique.
*/

int handle_key(int key, void **param)
{
	(void)param;

	printf("key = %d\n", key);
	
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_SPACE) // change cam
			;
	else if (key == 104)   // h for help
		print_help_key();
	else if (key == 65361) // fleche gauche
		g_app->scene->light->pos.x -= 10;
	else if (key == 65363) // fleche droite
		g_app->scene->light->pos.x += 10;
	else if (key == 65362) // fleche haut
		g_app->scene->light->pos.y += 10;
	else if (key == 65364) // fleche bas
		g_app->scene->light->pos.y -= 10;
	else if (key == 65451) // +
		g_app->scene->light->pos.z -= 10;
	else if (key == 65453) // -
		g_app->scene->light->pos.z += 10;

	else if (key == 122)   // z
		g_app->scene->cam->pos.z -= 3;
	else if (key == 115)   // s
		g_app->scene->cam->pos.z += 3;
	else if (key == 113)   // q
		g_app->scene->cam->pos.x -= 3;
	else if (key == 100)   // d
		g_app->scene->cam->pos.x += 3;
	else if (key == 119)   // w
		g_app->scene->cam->pos.y += 3;
	else if (key == 120)   // x
		g_app->scene->cam->pos.y -= 3;
	else if (key == 97)		// a
		g_app->scene->cam->orient.x += 100;
	else if (key == 101)	// e
		g_app->scene->cam->orient.x -= 100;	
	else
		return (0);
	raytracing_test(param);
	return (0);
}

/*
** Gestion de la souris : Pour le moment gere la premiere sphere touchee par la souris.
**
** 1 = clic gauche
** 2 = clic molette
** 3 = clic droit
** 4 = molette vers le haut
** 5 molette vers le bas.
*/

int		handle_mouse(int button, int x,int y, void *param)
{	
	printf("button = %d		x = %d	y = %d\n", button, x, y);
	
	t_ray 		*ray;
	t_sphere 	*sphere;
	t_obj		*first_obj;
	t_camera	*cam;

	cam = g_app->scene->cam;
	ray = malloc_ray(cam->pos, add_vec3(cam->pos, cam->orient));
	ray->direction = normalize_vec3(create_vec3(y - (g_app->size->x / 2) + 0.5, x - (g_app->size->y / 2) + 0.5, - g_app->size->x / (2 * tan(cam->fov / 2))));
	first_obj = find_first_intersection(ray, g_app->scene->objs);

	if (first_obj)
	{
		sphere = first_obj->shape;
		if (button == 4)
			sphere->radius += 1;
		if (button == 5 && sphere->radius > 1)
			sphere->radius -= 1;
		if (button == 1)
		{
			t_color color = find_pixel_color(first_obj, ray);
			printf("r = %d\ng = %d\nb = %d\na = %d\n\n", color.r, color.b, color.b, color.a);
		}
		raytracing_test(param);
	}
	free(ray);
	return (0);
}
