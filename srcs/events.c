/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:14:37 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/08 17:54:17 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		fct_key(int keycode, t_struct *strct)
{
	if (keycode == 53)
		free_strct_exit(strct);
	if (keycode == 6)
	{
		strct->choix->color_x = ((strct->choix->color_x) == 0 ? 1 : 0);
		strct->choix->color_y = 0;
	}
	if (keycode == 7)
	{
		strct->choix->color_y = ((strct->choix->color_y) == 0 ? 1 : 0);
		strct->choix->color_x = 0;
	}
	if (keycode == 8)
		strct->choix->color_alt = ((strct->choix->color_alt) == 0 ? 1 : 0);
	if (keycode == 9)
		strct->choix->t = ((strct->choix->t) == 0 ? 1 : 0);
	if (keycode == 35)
		strct->choix->draw = ((strct->choix->draw) == 0 ? 1 : 0);
	if (keycode == 31)
		strct->choix->diag = ((strct->choix->diag) == 0 ? 1 : 0);
	if (keycode == 34)
	{
		strct->choix->iso = ((strct->choix->iso) == 0 ? 1 : 0);
		strct->choix->para = ((strct->choix->para) == 0 ? 1 : 0);
	}
	if (keycode == 30)
		strct->pos_win->pas += 1;
	if (keycode == 33)
		strct->pos_win->pas -= 1;
	if (keycode && keycode != 35 && keycode != 31 && keycode != 6
		&& keycode != 30 && keycode != 33 && keycode != 34 && keycode != 7
		&& keycode != 8 && keycode != 9)
		strct->pos_win->key[keycode] = 1;
	return (0);
}

/*static	void 	test_color_alt(t_struct *strct, int x, int y)
{
	strct->hsv->hue = x - 21;
}
*/
static	void 	test_color_base(t_struct *strct, int x)
{
	strct->hsv->hue = x;
	if (x % 60 == 0)
		strct->hsv->saturation = 1;
	else
		strct->hsv->saturation = 1 / (float)60 * (float)(x % 60);
	strct->hsv->value = 1;
}

int		fct_mouse(int button, int x, int y, t_struct *strct)
{
	//dprintf(1, "x = %d, y = %d, button = %d\n", x, y, button);
	if ((x > 74 && y > 62) && (x < 332 && y < 106) && button == 1)
	{
		strct->choix->iso = ((strct->choix->iso) == 0 ? 1 : 0);
		strct->choix->para = 0;
	}
	if ((x > 102 && y > 184) && (x < 295 && y < 222) && button == 1)
	{
		strct->choix->para = ((strct->choix->para) == 0 ? 1 : 0);
		strct->choix->iso = 0;
	}
	if ((x > 136 && y > 311) && (x < 256 && y < 349) && button == 1)
		strct->choix->draw = ((strct->choix->draw) == 0 ? 1 : 0);
	if ((x > 93 && y > 439) && (x < 305 && y < 485) && button == 1)
		strct->choix->diag = ((strct->choix->diag) == 0 ? 1 : 0);
	if ((x > 147 && y > 572) && (x < 244 && y < 594) && button == 1)
		strct->choix->color_alt = ((strct->choix->color_alt) == 0 ? 1 : 0);
	//if ((x >= 21 && y >= 604) && (x <= 381 && y <= 654) && button == 1)
		//test_color_alt(strct, x, y);
	if ((x >= 20 && y >= 725) && (x <= 380 && y <= 775) && button == 1)
		test_color_base(strct, x);
	if ((x > 168 && y > 693) && (x < 225 && y < 716) && button == 1)
		strct->choix->color_alt = 0;
	if ((x > 100 && y > 856) && (x < 314 && y < 897) && button == 1)
	{
		strct->choix->color_x = ((strct->choix->color_x) == 0 ? 1 : 0);
		strct->choix->color_y = 0;
	}
	if ((x > 100 && y > 969) && (x < 314 && y < 1012) && button == 1)
	{
		strct->choix->color_y = ((strct->choix->color_y) == 0 ? 1 : 0);
		strct->choix->color_x = 0;
	}
	if (button == 5)
		strct->pos_win->pas += 0.5;
	if (button == 4 && strct->pos_win->pas > 0.000001)
		strct->pos_win->pas -= 0.5;
	return (0);
}

int 	key_off(int keycode, t_struct *strct)
{
	(void)strct;
	if (keycode && keycode != 35 && keycode != 31 && keycode != 6
		&& keycode != 30 && keycode != 33 && keycode != 34 && keycode != 7
		&& keycode != 8 && keycode != 9)
		strct->pos_win->key[keycode] = 0;
	return (0);
}
