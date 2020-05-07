/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:47 by lvirgini          #+#    #+#             */
/*   Updated: 2020/05/07 10:14:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_app		*g_app;

int		run_application(void)
{
	mlx_loop(g_app->mlx_ptr);
	free_application(g_app);
	return (0);
}

int		main(int ac, char **av)
{
	int		x = 800;
	int		y = 600;
	char	*title = "Premier test";

	t_xvar	*xvar;
	
	if (!(xvar = malloc(sizeof(*xvar))))
		printf("xwar pb\n");

	if ((xvar->display = XOpenDisplay("")) == 0)
		printf("xvardisplay\n");
	if (!(xvar = malloc(sizeof(*xvar))) || (xvar->display = XOpenDisplay(""))==0)
		printf("xvardisplay2\n");
	return(0);

	void *test = mlx_init();
	printf("test = %llx, mlx init = %p\n", test = mlx_init(), mlx_init());
	while (test == 0)
	{
		 test = mlx_init();
		printf("test = %d, mlx init = %p\n", test, mlx_init());
		printf("fucking ok %p\n", mlx_init());
	}
	return (0);
	//printf("fucking ok %p\n", mlx_init());
	//test = mlx_init();

	while (mlx_init() != NULL)
		printf("fucking ok %p\n", mlx_init());
	return (0);
	if (!(g_app = malloc_application(x, y, title, test)))
		return (file_error("MALLOC", 1));
	g_app->img = malloc_image(x, y);
	/*if (file_checking(ac, av) == -1)
		return (-1);*/

	clear_application(create_color(255, 255, 255, 255));
	mlx_put_image_to_window(g_app->mlx_ptr, g_app->win_ptr, g_app->img->img_ptr,0, 0);

	printf("%p\n", g_app->mlx_ptr);
	return (run_application());


	if(ac == 0 && av[0] == 0) // pour -Werror
		return(0); //
}
