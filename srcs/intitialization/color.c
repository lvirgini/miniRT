/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:46:07 by lvirgini          #+#    #+#             */
/*   Updated: 2020/04/30 14:28:09 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		create_color(uchar r, uchar g, uchar b, uchar a)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

t_color		*malloc_color(uchar r, uchar g, uchar b, uchar a)
{
	t_color *color;

	if(!(color = malloc(sizeof(t_color))))
		return (NULL);
	*color = create_color(r, g, b, a);
	return (color);
	
}

void		free_color(t_color *to_free)
{
	free(to_free);
}

/*
**Permet de fusionner deux couleurs en une seule, en fonction de l'alpha.
** entree de la fonction :
**	1 - La couleur ACTUELLEMENT en place -> la couleur dessous -> actual
**	2 - La couleur a ajouter -> la couleur dessus -> to_add
** Retour de la fonction :
**	La couleur une fois fusionnee
**	couleur finale = (X% de la couleur a ajouter) **+ (100 - X% de la couleur
**	de base)
*/

t_color fuze_color(t_color actual, t_color to_add)
{
	t_color result;
	float new_alpha;
	float inv_alpha;

	// 1 ) Calcul de X -> new_alpha
	new_alpha = to_add.a / 255.0f;

	// 2 ) Calcul de 100 - X -> inv_alpha
	inv_alpha = 1.0f - new_alpha;

	// 3 ) Application de la formule
	result = create_color(
		actual.r * inv_alpha + to_add.r * new_alpha,
		actual.g * inv_alpha + to_add.g * new_alpha,
		actual.b * inv_alpha + to_add.b * new_alpha,
		255
	);
	return (result);
}