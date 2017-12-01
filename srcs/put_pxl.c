/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:13:57 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/01 19:38:18 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "libmlx.h"

static	void 	remp_strct_y(t_struct *strct, int **tab, int x, int y)
{
	strct->coor->alt = (tab[x][y] - '0') * strct->pos_win->mult_alt;
	strct->coor->alt2 = (tab[x][y + 1] - '0') * strct->pos_win->mult_alt;
	if (strct->coor->alt > 0 || strct->coor->alt2 > 0)
		strct->coor->color = 0xF20A0A;
	else if (strct->coor->alt < 0 || strct->coor->alt2 < 0)
		strct->coor->color = 0x1BABF4;
	else if (strct->coor->alt == 0 || strct->coor->alt2 == 0)
		strct->coor->color = 0xFFFFFF;
	strct->coor->imin = x;
	strct->coor->jmin = y;
	strct->coor->imax = x;
	strct->coor->jmax = y + 1;
}

static	void 	remp_strct_x(t_struct *strct, int **tab, int x, int y)
{
	strct->coor->alt = (tab[x][y] - '0') * strct->pos_win->mult_alt;
	strct->coor->alt2 = (tab[x + 1][y] - '0') * strct->pos_win->mult_alt;
	if (strct->coor->alt > 0 || strct->coor->alt2 > 0)
		strct->coor->color = 0xF20A0A;
	else if (strct->coor->alt < 0 || strct->coor->alt2 < 0)
		strct->coor->color = 0x1BABF4;
	else if (strct->coor->alt == 0 || strct->coor->alt2 == 0)
		strct->coor->color = 0xFFFFFF;
	strct->coor->imin = x;
	strct->coor->jmin = y;
	strct->coor->imax = x + 1;
	strct->coor->jmax = y;
}

static	void 	segment(t_struct *strct, int x, int y, int c)
{
	if (c == 0)
		remp_strct_y(strct, strct->win->coor, x, y);
	else if (c == 1)
		remp_strct_x(strct, strct->win->coor, x, y);
	pos_iso(strct);
	rotation_z(strct);
	rotation_x(strct);
	rotation_y(strct);
	draw_line(strct);
}

int		ft_put_pxl(t_struct *strct)
{
	int		x;
	int		y;
	int		il;

	x = 0;
	center(strct);
	while (strct->win->coor[x])
	{
		y = 0;
		il = ft_intlen(strct->win->coor[x]);
		while (strct->win->coor[x][y])
		{
			if (y < il - 1)
				segment(strct, x, y, 0);
			if (x < strct->win->tl - 1 && y < ft_intlen(strct->win->coor[x + 1]))
				segment(strct, x, y, 1);
			y++;
		}
		x++;
	}
	return (0);
}
