/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:14:37 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/09 20:03:50 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static	void	mouse_pos(int button, int x, int y, t_struct *strct)
{
	if ((x > 39 && y > 41) && (x < 127 && y < 63) && button == 1)
	{
		strct->choix->iso = ((strct->choix->iso) == 0 ? 1 : 0);
		strct->choix->para = 0;
	}
	if ((x > 44 && y > 225) && (x < 129 && y < 247) && button == 1)
	{
		strct->choix->para = ((strct->choix->para) == 0 ? 1 : 0);
		strct->choix->iso = 0;
	}
	if ((x > 266 && y > 41) && (x < 367 && y < 64) && button == 1)
		strct->choix->draw = ((strct->choix->draw) == 0 ? 1 : 0);
	if ((x > 269 && y > 224) && (x < 352 && y < 253) && button == 1)
		strct->choix->diag = ((strct->choix->diag) == 0 ? 1 : 0);
}

static	void	mouse_moove(int button, int x, int y, t_struct *strct)
{
	if ((x > 165 && y > 9) && (x < 228 && y < 92) && button == 1)
		strct->pos_win->starty -= 10;
	if ((x > 257 && y > 114) && (x < 341 && y < 171) && button == 1)
		strct->pos_win->startx += 10;
	if ((x > 171 && y > 192) && (x < 233 && y < 271) && button == 1)
		strct->pos_win->starty += 10;
	if ((x > 47 && y > 109) && (x < 132 && y < 171) && button == 1)
		strct->pos_win->startx -= 10;
}

static	void	mouse_zoom(int button, int x, int y, t_struct *strct)
{
	if ((((x > 73 && y > 334) && (x < 117 && y < 348) && button == 1)
				|| button == 4)
			&& strct->pos_win->pas > 0.000001)
		strct->pos_win->pas -= 0.5;
	if (((x > 280 && y > 325) && (x < 315 && y < 357) && button == 1)
			|| button == 5)
		strct->pos_win->pas += 0.5;
}

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
	mouse_moove(button, x, y, strct);
	mouse_zoom(button, x, y, strct);
	mouse_alt(button, x, y, strct);
	mouse_base(button, x, y, strct);
	mouse_deg_color(button, x, y, strct);
	return (0);
}

int				fct_key(int keycode, t_struct *strct)
{
	if (keycode == 53)
		free_strct_exit(strct);
	if (keycode)
		strct->pos_win->key[keycode] = 1;
	return (0);
}

int				key_off(int keycode, t_struct *strct)
{
	(void)strct;
	if (keycode && keycode != 35 && keycode != 31 && keycode != 6
			&& keycode != 34 && keycode != 7 && keycode != 8)
		strct->pos_win->key[keycode] = 0;
	return (0);
}
