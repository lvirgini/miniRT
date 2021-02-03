/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:38:26 by lvirgini          #+#    #+#             */
/*   Updated: 2021/02/03 14:49:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_help_key(void)
{
	ft_putstr("* -------------------------------------------------------- *\n");
	ft_putstr("Welcome to hellp\n\nexit program : Echap\n");
	ft_putstr("switch camera : Space\n");
	ft_putstr("Move camera position : Z Q S D  and W X\n");
	ft_putstr("Move light : + -\n");
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
		exit_free_minirt((t_app *)param, 0);
	else if (key == KEY_SPACE) // change cam ou tab ?
			;
	else if (key == 104)   // h for help
		print_help_key();
	else if (key == 65361) // fleche gauche
		g_scene->light->pos.x -= 10;
	else if (key == 65363) // fleche droite
		g_scene->light->pos.x += 10;
	else if (key == 65362) // fleche haut
		g_scene->light->pos.y += 10;
	else if (key == 65364) // fleche bas
		g_scene->light->pos.y -= 10;
	else if (key == 65451) // +
		g_scene->light->pos.z -= 10;
	else if (key == 65453) // -
		g_scene->light->pos.z += 10;

	else if (key == 122)   // z
		g_scene->cam->pos.z -= 3;
	else if (key == 115)   // s
		g_scene->cam->pos.z += 3;
	else if (key == 113)   // q
		g_scene->cam->pos.x -= 3;
	else if (key == 100)   // d
		g_scene->cam->pos.x += 3;
	else if (key == 119)   // w
		g_scene->cam->pos.y += 3;
	else if (key == 120)   // x
		g_scene->cam->pos.y -= 3;
	else if (key == 97)		// a
		g_scene->cam->orient.x += 100;
	else if (key == 101)	// e
		g_scene->cam->orient.x -= 100;
	else
		return (0);
	generate_raytracing(param);
	return (0);
}

/*
** Gestion de la souris : Pour le moment gere la premiere sphere
** touchee par la souris.
**
** 1 = clic gauche
** 2 = clic molette
** 3 = clic droit
** 4 = molette vers le haut
** 5 molette vers le bas.
*/

int		handle_mouse(int button, int x, int y, void *param)
{
	printf("button = %d		x = %d	y = %d\n", button, x, y);

	t_ray		*ray;
	t_sphere	*sphere;
	t_obj		*first_obj;
	t_camera	*cam;
	t_app		*app;

	app = (t_app *)param;
	cam = g_scene->cam;
	ray = malloc_ray(cam->pos, add_vec3(cam->pos, cam->orient));
	ray->direction = normalize_vec3(create_vec3(y - (app->size.x / 2)
					+ 0.5, x - (app->size.y / 2) + 0.5, -app->size.x /
					(2 * tan(cam->fov / 2))));
	first_obj = closest_object(ray, g_scene->objs);
	if (first_obj && first_obj->type == SPHERE)
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
		generate_raytracing(param);
	}
	free(ray);
	return (0);
}
