/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 12:35:35 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/09 20:00:13 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"
#include "fdf.h"

void	color(t_struct *strct, int x, int y)
{
	if (strct->choix->col->color_uni
			&& strct->choix->col->color_uni_reset == 0)
		strct->hsv->hue += 1;
	if (strct->choix->col->color_uni_alt
			&& strct->choix->col->color_uni_reset == 0)
		strct->hsv->hue_alt += 1;
	if (strct->choix->col->color_x)
	{
		strct->hsv->saturation = x * 1 / (float)strct->tab->tl;
		strct->hsv->saturation_alt = x * 1 / (float)strct->tab->tl;
	}
	else if (strct->choix->col->color_y)
	{
		strct->hsv->saturation = y * 1 / (float)strct->tab->len_coor[x];
		strct->hsv->saturation_alt = y * 1 / (float)strct->tab->len_coor[x];
	}
}
