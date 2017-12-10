/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 12:40:40 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/10 12:42:24 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	coor_center(t_struct *strct, int x, int y)
{
	int		alt;

	alt = (strct->tab->coor[x][y] - '0');
	strct->orig->x_or = strct->pos_win->startx + x * strct->pos_win->pas
		+ y * strct->pos_win->pas;
	strct->orig->y_or = strct->pos_win->starty + x * strct->pos_win->pas
		- y * strct->pos_win->pas - alt;
	strct->orig->z_or = alt;
}

void			center(t_struct *strct)
{
	coor_center(strct, strct->tab->tl / 2,
			strct->tab->len_coor[strct->tab->tl / 2] / 2);
}
