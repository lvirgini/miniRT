/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:38:26 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/24 15:07:02 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Keyboard keys management for camera orient change
*/

static int	camera_orient_changing(int key, t_camera *cam)
{
	if (key == XK_KP_Left)
		cam->orient.x -= 0.1;
	else if (key == XK_KP_Right)
		cam->orient.x += 0.1;
	else if (key == XK_KP_Down)
		cam->orient.y -= 0.1;
	else if (key == XK_KP_Up)
		cam->orient.y += 0.1;
	else if (key == XK_KP_Page_Down)
		cam->orient.z -= 0.1;
	else if (key == XK_KP_Page_Up)
		cam->orient.z += 0.1;
	else
		return (0);
	cam->orient = normalize_vec3(cam->orient);
	return (1);
}

/*
** Keyboard keys management for camera movement
*/

static int	camera_pos_changing(int key, t_camera *cam)
{
	if (key == XK_z)
		cam->pos.z += 10;
	else if (key == XK_s)
		cam->pos.z -= 10;
	else if (key == XK_q)
		cam->pos.x -= 10;
	else if (key == XK_d)
		cam->pos.x += 10;
	else if (key == XK_w)
		cam->pos.y -= 10;
	else if (key == XK_x)
		cam->pos.y += 10;
	else
		return (camera_orient_changing(key, cam));
	return (1);
}

/*
** Keyboard keys management
*/

int			handle_key(int key, t_app *app)
{
	printf("key = %x\n", key);
	if (key == XK_Escape)
		exit_free_minirt(app, 0, 0);
	else if (key == XK_space)
	{
		app->img = app->img->next;
		app->scene->cam = app->scene->cam->next;
	}
	else if (check_image_transform(key, app->img, app))
		;
	else if (camera_pos_changing(key, app->scene->cam))
		generate_raytracing(app);
	else
		return (0);
	return (run_application(app, app->img));
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

/*
int			handle_mouse(int button, int x, int y, t_app *app)
{
	t_ray		ray;
	t_sphere	*sphere;
	t_obj		*first_obj;
	t_camera	*cam;

	
//	printf("button = %d		x = %d	y = %d\n", button, x, y);
	int X = ((y * app->img->size.x) + x) * 4;
	t_color c = create_color(app->img->pixels[X + RED_PIXEL],
								app->img->pixels[X + GREEN_PIXEL],
								app->img->pixels[X + BLUE_PIXEL]);
	print_color(c);*/

/*	cam = app->scene->cam;
	ray = create_ray(cam->pos, add_vec3(cam->pos, cam->orient),
		create_vec3(0, 0, 0));
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
*/