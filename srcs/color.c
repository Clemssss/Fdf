/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 12:35:35 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/08 12:47:05 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"
#include "fdf.h"

static	void 	color_alt(t_struct *strct, int x, int y, int x2, int y2)
{
	if (strct->tab->coor[x][y] - '0' || strct->tab->coor[x2][y2] - '0')
	{
		strct->hsv->hue = 0;
		strct->hsv->saturation = 1;
		strct->hsv->value = 1;
	}
	else
	{
		strct->hsv->hue = 120;
		strct->hsv->saturation = 1;
		strct->hsv->value = 1;
	}
}

void 					color(t_struct *strct, int x, int y, int x2, int y2)
{
	if (strct->choix->color_alt)
		color_alt(strct, x, y, x2, y2);
	if (strct->choix->color_x)
		strct->hsv->saturation = x * 1 / (float)strct->tab->tl;
	else if (strct->choix->color_y)
		strct->hsv->saturation = y * 1 / (float)strct->tab->len_coor[x];
}
