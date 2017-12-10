/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pos_move_zoom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 12:54:37 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/10 12:57:38 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	mouse_pos(int button, int x, int y, t_struct *strct)
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

void	mouse_move(int button, int x, int y, t_struct *strct)
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

void	mouse_zoom(int button, int x, int y, t_struct *strct)
{
	if ((((x > 73 && y > 334) && (x < 117 && y < 348) && button == 1)
				|| button == 4)
			&& strct->pos_win->pas > 0.000001)
		strct->pos_win->pas -= 0.5;
	if (((x > 280 && y > 325) && (x < 315 && y < 357) && button == 1)
			|| button == 5)
		strct->pos_win->pas += 0.5;
}
