/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:14:37 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/08 12:44:55 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		fct_key(int keycode, t_struct *strct)
{
	if (keycode == 53)
		free_strct_exit(strct);
	if (keycode == 6)
		strct->choix->color_x = ((strct->choix->color_x) == 0 ? 1 : 0);
	if (keycode == 7)
		strct->choix->color_y = ((strct->choix->color_y) == 0 ? 1 : 0);
	if (keycode == 8)
		strct->choix->color_alt = ((strct->choix->color_alt) == 0 ? 1 : 0);
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
		&& keycode != 30 && keycode != 33 && keycode != 34 && keycode != 7)
		strct->pos_win->key[keycode] = 1;
	return (0);
}

int		fct_mouse(int button, int x, int y, t_struct *strct)
{
	if ((x > 36 && y > 69) && (x < 365 && y < 171) && button == 1)
	{
		strct->choix->iso = ((strct->choix->iso) == 0 ? 1 : 0);
		strct->choix->para = 0;
	}
	if ((x > 36 && y > 189) && (x < 365 && y < 290) && button == 1)
	{
		strct->choix->para = ((strct->choix->para) == 0 ? 1 : 0);
		strct->choix->iso = 0;
	}
	if ((x > 36 && y > 308) && (x < 365 && y < 410) && button == 1)
		strct->choix->diag = ((strct->choix->diag) == 0 ? 1 : 0);
	if ((x > 36 && y > 427) && (x < 365 && y < 529) && button == 1)
		strct->choix->draw = ((strct->choix->draw) == 0 ? 1 : 0);
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
		&& keycode != 8)
		strct->pos_win->key[keycode] = 0;
	return (0);
}
