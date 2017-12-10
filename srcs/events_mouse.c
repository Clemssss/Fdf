/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:14:37 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/10 14:18:56 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static	void	mouse_alt(int button, int x, int y, t_struct *strct)
{
	if ((x > 74 && y > 416) && (x < 116 && y < 428) && button == 1)
		strct->pos_win->mult_alt -= 0.5;
	if ((x > 284 && y > 401) && (x < 316 && y < 435) && button == 1)
		strct->pos_win->mult_alt += 0.5;
	if ((x >= 18 && y >= 453) && (x <= 378 && y <= 503) && button == 1)
		strct->hsv->hue_alt = x - 18;
	if ((x > 111 && y > 517) && (x < 145 && y < 551) && button == 1)
		strct->hsv->saturation_alt += 0.05;
	if ((x > 112 && y > 619) && (x < 154 && y < 632) && button == 1)
		strct->hsv->saturation_alt -= 0.05;
	if ((x > 238 && y > 516) && (x < 270 && y < 549) && button == 1)
		strct->hsv->value_alt += 0.05;
	if ((x > 233 && y > 621) && (x < 279 && y < 632) && button == 1)
		strct->hsv->value_alt -= 0.05;
}

static	void	mouse_base(int button, int x, int y, t_struct *strct)
{
	if ((x >= 19 && y >= 729) && (x <= 379 && y <= 779) && button == 1)
		strct->hsv->hue = x - 20;
	if ((x > 117 && y > 795) && (x < 148 && y < 827) && button == 1)
		strct->hsv->saturation += 0.05;
	if ((x > 115 && y > 903) && (x < 159 && y < 916) && button == 1)
		strct->hsv->saturation -= 0.05;
	if ((x > 241 && y > 794) && (x < 274 && y < 825) && button == 1)
		strct->hsv->value += 0.05;
	if ((x > 236 && y > 903) && (x < 281 && y < 919) && button == 1)
		strct->hsv->value -= 0.05;
}

static	void	mouse_deg_color(int button, int x, int y, t_struct *strct)
{
	if ((x > 50 && y > 1002) && (x < 151 && y < 1028) && button == 1)
	{
		strct->choix->col->color_x =
			((strct->choix->col->color_x) == 0 ? 1 : 0);
		strct->choix->col->color_y = 0;
	}
	if ((x > 54 && y > 1101) && (x < 150 && y < 1131) && button == 1)
	{
		strct->choix->col->color_y =
			((strct->choix->col->color_y) == 0 ? 1 : 0);
		strct->choix->col->color_x = 0;
	}
	if ((x > 189 && y > 1104) && (x < 365 && y < 1130) && button == 1)
		strct->choix->col->color_uni =
			((strct->choix->col->color_uni) == 0 ? 1 : 0);
	if ((x > 201 && y > 1001) && (x < 352 && y < 1024) && button == 1)
		strct->choix->col->color_uni_alt =
			((strct->choix->col->color_uni_alt) == 0 ? 1 : 0);
}

int				fct_mouse(int button, int x, int y, t_struct *strct)
{
	mouse_pos(button, x, y, strct);
	mouse_move(button, x, y, strct);
	mouse_zoom(button, x, y, strct);
	mouse_alt(button, x, y, strct);
	mouse_base(button, x, y, strct);
	mouse_deg_color(button, x, y, strct);
	return (0);
}
