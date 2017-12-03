/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:13:57 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/03 17:55:59 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "libmlx.h"

static	void 	remp_strct(t_struct *strct, int **tab, int x, int y)
{
	strct->coor->alt2 = (tab[x][y] - '0') * strct->pos_win->mult_alt;
	strct->coor->imax = x;
	strct->coor->jmax = y;
}

static	void 	make(t_struct *strct, int x, int y, int c)
{
	strct->coor->alt = (strct->tab->coor[x][y] - '0') * strct->pos_win->mult_alt;
	strct->coor->imin = x;
	strct->coor->jmin = y;
	if (c == 0)
		remp_strct(strct, strct->tab->coor, x, y + 1);
	else if (c == 1)
		remp_strct(strct, strct->tab->coor, x + 1, y);
	else if (c == 2)
		remp_strct(strct, strct->tab->coor, x + 1, y + 1);
	if (strct->coor->alt > 0 || strct->coor->alt2 > 0)
		strct->pict->color = 0x8B3402;
	else if (strct->coor->alt < 0 || strct->coor->alt2 < 0)
		strct->pict->color = 0x1BABF4;
	else if (strct->coor->alt == 0 || strct->coor->alt2 == 0)
		strct->pict->color = 0xFFFFFF;
	pos_iso(strct);
	//pos_para(strct);
	rotation_z(strct);
	rotation_x(strct);
	rotation_y(strct);
	draw_line(strct->pict, strct->pos_iso->xmin, strct->pos_iso->ymin,
		strct->pos_iso->xmax, strct->pos_iso->ymax, strct->choix->draw);
}

int		ft_put_pxl(t_struct *strct)
{
	int		x;
	int		y;

	x = 0;
	center(strct);
	while (strct->tab->coor[x])
	{
		y = 0;
		while (strct->tab->coor[x][y])
		{
			if (y < strct->tab->len_coor[x] - 1)
				make(strct, x, y, 0);
			if (x < strct->tab->tl - 1 && y < strct->tab->len_coor[x + 1])
				make(strct, x, y, 1);
			if (y < strct->tab->len_coor[x] - 1
				&& x < strct->tab->tl - 1 && y < strct->tab->len_coor[x + 1]
				&& strct->choix->diag == 1)
				make(strct, x, y, 2);
			y++;
		}
		x++;
	}
	return (0);
}
