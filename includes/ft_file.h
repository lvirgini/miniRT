/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:50:01 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/29 19:42:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

int			file_checking(int ac, char **av);
int			file_type(char *str);
int			file_error(int error);
int			read_file(char *str);
int			line_parser(char *line);
t_func		*set_functions(void);
int			check_file_is_complete(void);


int 		create_sphere(char *str);
int 		create_plane(char *str);
int 		create_square(char *str);
int 		create_triangle(char *str);
int 		create_cyl(char *str);
	

int 		create_resolution(char *str);
int 		create_ambiant_ligth(char *str);
int 		create_light(char *str);
int 		create_camera(char *str);


#endif