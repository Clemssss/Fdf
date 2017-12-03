/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:52:10 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/03 22:00:13 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

static	void 	coor_center(t_struct *strct, int x, int y)
{
	int		alt;

	alt = (strct->tab->coor[x][y] - '0');
	strct->orig->x_or = strct->pos_win->startx + x * strct->pos_win->pas
	+ y * strct->pos_win->pas;
	strct->orig->y_or = strct->pos_win->starty + x * strct->pos_win->pas
	- y * strct->pos_win->pas - alt;
	strct->orig->z_or = alt;
}

void 	center(t_struct *strct)
{
	coor_center(strct, strct->tab->tl / 2,
		strct->tab->len_coor[strct->tab->tl / 2] / 2);
}

int						loop_img(t_struct *strct)
{
	if (!(strct->win->mlx = mlx_init()))
		return (-1);
	strct->win->width = 1800;
	strct->win->height = 1800;
	strct->pict->x = strct->win->width;
	strct->pict->y = strct->win->height;
	if ((!(strct->win->window = mlx_new_window(strct->win->mlx,
		strct->win->width, strct->win->height, "Fdf")))
			|| (!(strct->pict->img = mlx_new_image(strct->win->mlx,
				strct->pict->x, strct->pict->y)))
			|| (!(strct->pict->data = mlx_get_data_addr(strct->pict->img,
				&strct->pict->bpp, &strct->pict->size_line, &strct->pict->endian))))
		return (-1);
	ft_put_pxl(strct);
	mlx_hook(strct->win->window, 2, 0, &fct_key, strct);
	mlx_loop_hook(strct->win->mlx, &do_change, strct);
	mlx_mouse_hook(strct->win->window, &fct_mouse, strct);
	mlx_key_hook(strct->win->window, &key_off, strct);
	mlx_loop(strct->win->mlx);
	free_strct(strct);
	return (0);
}
