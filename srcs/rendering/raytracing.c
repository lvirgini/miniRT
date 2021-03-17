/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 16:36:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 14:10:14 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** for each camera, create an image.
*/

int				generate_raytracing(t_app *app)
{
	t_camera	*cam;
	t_image		*img;
	int			nb_cam;

	nb_cam = app->scene->nb_cam;
	cam = app->scene->cam;
	img = app->img;
	if (app->scene->total_intens < 1.0)
		app->scene->total_intens = 1.0;
	while (nb_cam--)
	{
		browse_image_for_intersection(cam, img, app, app->size);
		cam = cam->next;
		img = img->next;
	}
	return (0);
}

/*
** check if weight and hight demand are inside maximum size of display.
*/

static void		check_max_display(void *mlx_ptr, t_vec2 *size)
{
	int		max_x;
	int		max_y;

	mlx_get_screen_size(mlx_ptr, &max_x, &max_y);
	if (size->x > max_x)
		size->x = max_x;
	if (size->y > max_y)
		size->y = max_y;
}

/*
** create with malloc one image for each camera
** make a circle list of images.
*/

static t_image	*generate_all_img(void *mlx_ptr, double x, double y, int nb_cam)
{
	t_image	*img;
	t_image	*tmp;

	tmp = NULL;
	while (nb_cam--)
	{
		if (!(img = malloc_image(x, y, mlx_ptr)))
			return (NULL);
		img->next = tmp;
		tmp = img;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = img;
	return (img);
}

/*
** generate mlx ptr
** open windows if not bmp file request
** create malloc image for each camera.
*/

int				generate_mlx_content(t_app *app)
{
	app->mlx_ptr = mlx_init();
	if (app->mlx_ptr == NULL)
		exit_free_minirt(app, __FILE__, ERR_MLX_INIT);
	check_max_display(app->mlx_ptr, &app->size);
	if (app->save == 0)
	{
		app->win_ptr = mlx_new_window(app->mlx_ptr, app->size.x,
				app->size.y, "Minirt");
		if (app->win_ptr == NULL)
			exit_free_minirt(app, __FILE__, ERR_MLX_NEW_WINDOW);
	}
	if (!(app->img = generate_all_img(app->mlx_ptr, app->size.x,
			app->size.y, app->scene->nb_cam)))
		exit_free_minirt(app, __FILE__, ERR_MALLOC);
	return (0);
}
