/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:44:48 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/21 11:48:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** create a new image in black and white mode
*/

static t_image	*get_image_black(t_app *app, char *pixels, int nb_pixel)
{
	int		x;
	t_color c;
	t_image	*res;

	if (!(res = malloc_image(app->img->size.x, app->img->size.y, app->mlx_ptr)))
		exit_free_minirt(app, "get_image_black", ERR_MALLOC);
	x = 0;
	while (x + 4 <= nb_pixel)
	{
		c = create_color((unsigned char)pixels[x + RED_PIXEL],
						(unsigned char)pixels[x + GREEN_PIXEL],
						(unsigned char)pixels[x + BLUE_PIXEL]);
		c = create_color((0.299 * c.r + 0.587 * c.g + 0.114 * c.b),
						(0.299 * c.r + 0.587 * c.g + 0.114 * c.b),
						(0.299 * c.r + 0.587 * c.g + 0.114 * c.b));
		c = adjust_min_max_color(c);
		res->pixels[x + RED_PIXEL] = (char)c.r;
		res->pixels[x + GREEN_PIXEL] = (char)c.g;
		res->pixels[x + BLUE_PIXEL] = (char)c.b;
		res->pixels[x + ALPHA_PIXEL] = 0;
		x += 4;
	}
	return (res);
}

/*
** create a new image in sepia mode
*/

static t_image	*get_image_sepia(t_app *app, char *pixels, int nb_pixel)
{
	int		x;
	t_color c;
	t_image	*res;

	if (!(res = malloc_image(app->img->size.x, app->img->size.y, app->mlx_ptr)))
		exit_free_minirt(app, "get_image_sepia", ERR_MALLOC);
	x = 0;
	while (x + 4 <= nb_pixel)
	{
		c = create_color((unsigned char)pixels[x + RED_PIXEL],
						(unsigned char)pixels[x + GREEN_PIXEL],
						(unsigned char)pixels[x + BLUE_PIXEL]);
		c = create_color((0.393 * c.r + 0.769 * c.g + 0.189 * c.b),
						(0.349 * c.r + 0.686 * c.g + 0.168 * c.b),
						(0.272 * c.r + 0.534 * c.g + 0.131 * c.b));
		c = adjust_min_max_color(c);
		res->pixels[x + RED_PIXEL] = (char)c.r;
		res->pixels[x + GREEN_PIXEL] = (char)c.g;
		res->pixels[x + BLUE_PIXEL] = (char)c.b;
		res->pixels[x + ALPHA_PIXEL] = 0;
		x += 4;
	}
	return (res);
}

/*t_image		*get_image_blue(t_app *app, char *pixels, int nb_pixel)
{
	int		x;
	t_image	*res;
	t_color	c;

	if (!(res = malloc_image(app->img->size.x, app->img->size.y, app->mlx_ptr)))
		exit_free_minirt(app, "get_image_blue", ERR_MALLOC);
	x = 0;
	while (x + 4 <= nb_pixel)
	{
		c = create_color((unsigned char)pixels[x + RED_PIXEL],
						(unsigned char)pixels[x + GREEN_PIXEL],
						(unsigned char)pixels[x + BLUE_PIXEL]);
		c = create_color(c.r * 1.5,
						c.g * 1.5,
						c.b * 1.5);
		c = adjust_min_max_color(c);
		res->pixels[x + RED_PIXEL] = (char)c.r;
		res->pixels[x + GREEN_PIXEL] = (char)c.g;
		res->pixels[x + BLUE_PIXEL] = (char)c.b;
		res->pixels[x + ALPHA_PIXEL] = 0;
		x += 4;
	}
	return (res);
}*/

int			check_image_transform(int key, t_image *img, t_app *app)
{
	if (key == XK_t)
	{
		if (!img->sepia)
			img->sepia = get_image_sepia(app, img->pixels,
					img->size.x * img->size.y * 4);
		run_application(app, img->sepia);
	}
	else if (key == XK_y)
	{
		if (!img->black)
			img->black = get_image_black(app, img->pixels,
					img->size.x * img->size.y * 4);
		run_application(app, img->black);
	}
/*	else if (key == XK_i)
	{
		if (!img->black)
			img->black = get_image_blue(app, img->pixels,
					img->size.x * img->size.y * 4);
		run_application(app, img->black);
	}*/
	else
		return (0);
	return (1);
}
