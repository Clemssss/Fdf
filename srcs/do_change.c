/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:16:00 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/06 18:49:49 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libmlx.h"

static	void 	move(t_struct *strct)
{
	if (strct->pos_win->key[126])
		strct->pos_win->starty = strct->pos_win->starty - 15;
	if (strct->pos_win->key[125])
		strct->pos_win->starty = strct->pos_win->starty + 15;
	if (strct->pos_win->key[123])
		strct->pos_win->startx = strct->pos_win->startx - 15;
	if (strct->pos_win->key[124])
		strct->pos_win->startx = strct->pos_win->startx + 15;
}

static	void 	rotate(t_struct *strct)
{
	if (strct->pos_win->key[13])
		strct->pos_win->degre += 1;
	if (strct->pos_win->key[1])
		strct->pos_win->degre -= 1;
	if (strct->pos_win->key[14])
		strct->pos_win->degre2 += 1;
	if (strct->pos_win->key[2])
		strct->pos_win->degre2 -= 1;
	if (strct->pos_win->key[15])
		strct->pos_win->degre3 += 1;
	if (strct->pos_win->key[3])
		strct->pos_win->degre3 -= 1;
}

static	void 	change_alt(t_struct *strct)
{
	if (strct->pos_win->key[69])
		strct->pos_win->mult_alt += 0.7;
	if (strct->pos_win->key[78])
		strct->pos_win->mult_alt -= 0.7;
}

static	void 	test_color(t_struct *strct, int x, int y, int x2, int y2)
{
	float	t;

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
	t = 1 / (float)strct->tab->tl;
	strct->hsv->saturation = x * t;
}

void 	color(t_struct *strct, int x, int y, int x2, int y2)
{
	if (strct->choix->color)
		test_color(strct, x, y, x2, y2);
}

static	void 	color_change(t_struct *strct)
{
	if (strct->pos_win->key[17])
		strct->hsv->hue += 5;
	if (strct->pos_win->key[5])
		strct->hsv->hue -= 5;
	if (strct->pos_win->key[16])
		strct->hsv->saturation += 0.05;
	if (strct->pos_win->key[4])
		strct->hsv->saturation -= 0.05;
	if (strct->pos_win->key[32])
		strct->hsv->value += 0.05;
	if (strct->pos_win->key[38])
		strct->hsv->value -= 0.05;
}

int 					do_change(t_struct *strct)
{
	clear_pixels(strct->pict);
	move(strct);
	change_alt(strct);
	rotate(strct);
	color_change(strct);
	ft_put_pxl(strct);
	if (strct->hsv->hue >= 360)
		strct->hsv->hue = 0;
	if (strct->hsv->hue < 0)
		strct->hsv->hue = 360;
	if (strct->hsv->saturation < 0)
		strct->hsv->saturation = 1;
	if (strct->hsv->saturation > 1.1)
		strct->hsv->saturation = 0;
	if (strct->hsv->value < 0)
		strct->hsv->value = 1;
	if (strct->hsv->value > 1.1)
		strct->hsv->value = 0;
	mlx_put_image_to_window(strct->win->mlx,
		strct->win->window, strct->pict->img, 0, 0);
	mlx_put_image_to_window(strct->win->mlx,
		strct->win->window, strct->menu->img, 0, 0);
	return (0);
}
