/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:38:26 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 14:30:42 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_help_key(void)
{
	ft_putstr("* -------------------------------------------------------- *\n");
	ft_putstr("exit program : Echap\n");
	ft_putstr("switch camera : Space\n");
	ft_putstr("Move camera position : Z Q S D  and  orient x : 4 6 y: 8 2 z: 9 3\n");
	ft_putstr("Move 1st light : + -\n");
	ft_putstr("Use the mouse wheel on a object to grow it or get it smaller\n");
	ft_putstr("* -------------------------------------------------------- *\n");
}

/*
** Gestion des touches du clavier
**** Pour le moment gere la lumiere unique.
*/

int handle_key(int key, t_app *app)
{
	printf("key = %d\n", key);
	if (key == KEY_ESC)
		exit_free_minirt(app, 0, 0);
	else if (key == KEY_SPACE) // change cam ou tab ?
		{
			app->img = app->img->next;
		//	app->scene->cam = app->scene->cam->next;
			return(run_application(app));
		}	
	else if (key == 104)   // h for help
		print_help_key();
	else if (key == 65361) // fleche gauche
		app->scene->light->pos.x -= 10;
	else if (key == 65363) // fleche droite
		app->scene->light->pos.x += 10;
	else if (key == 65362) // fleche haut
		app->scene->light->pos.y -= 10;
	else if (key == 65364) // fleche bas
		app->scene->light->pos.y += 10;
	else if (key == 65451) // +
		app->scene->light->pos.z -= 10;
	else if (key == 65453) // -
		app->scene->light->pos.z += 10;
	else if (key == 122)   // z
		app->scene->cam->pos.z += 10;
	else if (key == 115)   // s
		app->scene->cam->pos.z -= 10;
	else if (key == 113)   // q
		app->scene->cam->pos.x -= 10;
	else if (key == 100)   // d
		app->scene->cam->pos.x += 10;
	else if (key == 119)   // w
		app->scene->cam->pos.y -= 10;
	else if (key == 120)   // x
		app->scene->cam->pos.y += 10;
	else if (key == 97)		// a
		app->scene->cam->orient.x += 100;
	else if (key == 101)	// e
		app->scene->cam->orient.x -= 100;
	else if (key == 65430)	// 4
		app->scene->cam->orient.x -= 0.1;
	else if (key == 65432)	// 4
		app->scene->cam->orient.x += 0.1;
	else if (key == 65433)	// 4
		app->scene->cam->orient.y -= 0.1;
	else if (key == 65431)	// 4
		app->scene->cam->orient.y += 0.1;
	else
		return (0);
	app->scene->cam->orient = normalize_vec3(app->scene->cam->orient);
	generate_raytracing(app);
	run_application(app);
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

int		handle_mouse(int button, int x, int y, t_app *app)
{
	printf("button = %d		x = %d	y = %d\n", button, x, y);
	t_ray		ray;
	t_sphere	*sphere;
	t_obj		*first_obj;
	t_camera	*cam;

	cam = app->scene->cam;
	ray = create_ray(cam->pos, add_vec3(cam->pos, cam->orient), create_vec3(0,0,0));
	ray.direction = normalize_vec3(create_vec3(y - (app->size.x / 2)
					+ 0.5, x - (app->size.y / 2) + 0.5, -app->size.x /
					(2 * tan(cam->angle))));
	first_obj = closest_object(&ray, app->scene->objs);
	if (first_obj && first_obj->type == SPHERE)
	{
		sphere = first_obj->shape;
		if (button == 4)
			sphere->radius += 1;
		if (button == 5 && sphere->radius > 1)
			sphere->radius -= 1;
		generate_raytracing(app);
		run_application(app);
	}
	return (0);
}
