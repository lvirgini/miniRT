/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:58:38 by lvirgini          #+#    #+#             */
/*   Updated: 2021/03/17 14:04:55 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**  BMP FILE HEADER :
**	octet	octet	description					INT
**	0		2		Bitmap signature			'B' - 'M'
**	2		4		FileSize					(bits/pixel*x*y) + header
**	6		4		Reserved field				0
**	10		4		Reserved (offset of pixel data inside the image)	0
**	14		4		header size					40
**	18		4		width of the image			img->x  (nb pixel)
**	22		4		height of the image			img->y	(nb pixel)
**	26		2		reserved image plane		1 - 0
**	28		2		bits per pixel				img->bits_per_pixel
**	30		4		compression type			0 no compression
**	34		4		size of pixel data			0
**	38		4		horizontal pixel per meter	0
**	42		4		vertical pixel per meter	0
**	46		4		nb of colors color palette	0
**	50		4		nb of important color		0 = all important
*/

static void		bmp_write_header(int fd, t_image *img)
{
	char	bmp_header[54];
	int		file_size;

	ft_bzero(bmp_header, 54);
	file_size = 54 + img->bits_per_pixel / 8 * img->size.x * img->size.y;
	bmp_header[0] = 'B';
	bmp_header[1] = 'M';
	bmp_header[2] = (unsigned int)file_size;
	bmp_header[3] = (unsigned int)file_size >> 8;
	bmp_header[4] = (unsigned int)file_size >> 16;
	bmp_header[5] = (unsigned int)file_size >> 24;
	bmp_header[14] = 40;
	bmp_header[18] = (unsigned int)img->size.x;
	bmp_header[19] = (unsigned int)img->size.x >> 8;
	bmp_header[20] = (unsigned int)img->size.x >> 16;
	bmp_header[21] = (unsigned int)img->size.x >> 24;
	bmp_header[22] = (unsigned int)img->size.y;
	bmp_header[23] = (unsigned int)img->size.y >> 8;
	bmp_header[24] = (unsigned int)img->size.y >> 16;
	bmp_header[25] = (unsigned int)img->size.y >> 24;
	bmp_header[26] = 1;
	bmp_header[28] = img->bits_per_pixel;
	write(fd, bmp_header, 54);
}

static void		bmp_write_data(int fd, t_image *img)
{
	int		x;
	int		y;
	int		pixel_index;

	y = 0;
	while (y < img->size.y)
	{
		x = 0;
		while (x < img->size.x)
		{
			pixel_index = (int)((img->size.y - 1 - y) * img->size.x + x);
			write(fd, (int *)img->pixels + pixel_index, 4);
			x++;
		}
		y++;
	}
}

static int		img_to_bmp(t_app *app)
{
	int		fd;

	fd = open("Minirt.bmp", O_RDWR | O_CREAT | O_TRUNC,
		S_IRWXU | S_IRWXG | S_IRWXO);
	printf("FD = %d\n", fd);
	if (fd == -1)
		exit_free_minirt(app, __FILE__, ERR_FD);
	bmp_write_header(fd, app->img);
	bmp_write_data(fd, app->img);
	close(fd);
	destroy_application(app);
	return (0);
}

int				generate_bmp_file(t_app *app)
{
	browse_image_for_intersection(app->scene->cam, app->img, app, app->size);
	destroy_scene(*app->scene);
	return (img_to_bmp(app));
}
