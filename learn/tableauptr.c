/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableauptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:38:32 by lvirgini          #+#    #+#             */
/*   Updated: 2020/02/29 19:06:23 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strchr_i(const char *s, int a)
{
	unsigned int i;

	i = 0;
	while (s[i] && s[i] != a)
		++i;
	return (i);
}

int		plus(int a, int b)
{
	return (a + b);
}

int 	moins(int a, int b)
{
	return (a - b);
}

typedef	int (*t_f)(int, int);

int main(void)
{
	static t_f f[2] = {
		&plus, 
		&moins };
	char *f_num = "pm";

	char *a;
	int res;

	a = "tt";

	res = f[ft_strchr_i(f_num, a[0])](10, 3);
	printf("%d\n", res);


/* utilisation normale : 

	t_f f;

	f = &moins;
	printf("%d\n", f(10, 3));
*/

	return (0);
}