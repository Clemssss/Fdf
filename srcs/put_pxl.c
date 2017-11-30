/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:13:57 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/30 12:15:39 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "libmlx.h"

static	void 	segment(t_struct *strct)
{
	pos_iso(strct);
	draw_line(strct);
}

static	void 	remp_strct_y(t_struct *strct, int **tab, int x, int y)
{
	if (tab[x][y] == 48)
		strct->coor->altmin = 0;
	else
		strct->coor->altmin = tab[x][y];
	if (tab[x][y + 1] == 48)
		strct->coor->altmax = 0;
	else
		strct->coor->altmax = tab[x][y + 1];
	strct->coor->imin = x;
	strct->coor->jmin = y;
	strct->coor->imax = x;
	strct->coor->jmax = y + 1;
}

static	void 	remp_strct_x(t_struct *strct, int **tab, int x, int y)
{
	if (tab[x][y] == 48)
		strct->coor->altmin = 0;
	else
		strct->coor->altmin = tab[x][y];
	if (tab[x + 1][y] == 48)
		strct->coor->altmax = 0;
	else
		strct->coor->altmax = tab[x + 1][y];
	strct->coor->imin = x;
	strct->coor->jmin = y;
	strct->coor->imax = x + 1;
	strct->coor->jmax = y;
}

int		ft_put_pxl(t_struct *strct)
{
	int		x;
	int		y;
	int		il;
	int		tl;

	x = 0;
	tl = ft_tablen_int(strct->win->coor);
	while (strct->win->coor[x])
	{
		y = 0;
		il = ft_intlen(strct->win->coor[x]);
		while (strct->win->coor[x][y])
		{
			if (y < il - 1)
			{
				remp_strct_y(strct, strct->win->coor, x, y);
				segment(strct);
			}
			if (x < tl - 1 && y < ft_intlen(strct->win->coor[x + 1]))
			{
				remp_strct_x(strct, strct->win->coor, x, y);
				segment(strct);
			}
			y++;
		}
		x++;
	}
	return (0);
}
