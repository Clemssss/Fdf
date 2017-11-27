/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:52:10 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/27 20:50:09 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

static	int 	clear_pixels(t_struct *strct)
{
	int	x;
	int	y;

	x = 0;
	while (x < strct->win->width)
	{
		y = 0;
		while (y < strct->win->height)
		{
			strct->pict->data[y * strct->pict->size_line + x * strct->pict->bpp / 8] = 0;
		  strct->pict->data[y * strct->pict->size_line + x * strct->pict->bpp / 8 + 1] = 0;
		  strct->pict->data[y * strct->pict->size_line + x * strct->pict->bpp / 8 + 2] = 0;
			y++;
		}
		x++;
	}
	return (0);
}

static	int		fct_key(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

static	int		fct_mouse(int keycode, int x, int y, t_struct *strct)
{
	if (keycode == 4 && strct->pos_win->pas >= 2)
	{
		//dprintf(1, "here = 4\n");
		strct->pos_win->pas = strct->pos_win->pas - 1;
	}
	else if (keycode == 5)
	{
		//dprintf(1, "here = 5\n");
		strct->pos_win->pas = strct->pos_win->pas + 1;
	}
	return (0);
}

static	void 	my_pixel(t_pict *pict, int x, int y)
{
	unsigned	char	r;
	unsigned	char	g;
	unsigned	char	b;


	r = (pict->img_color & 0xFF0000) >> 16;
  g = (pict->img_color & 0xFF00) >> 8;
  b = (pict->img_color & 0xFF);

  pict->data[y * pict->size_line + x * pict->bpp / 8] = b;
  pict->data[y * pict->size_line + x * pict->bpp / 8 + 1] = g;
  pict->data[y * pict->size_line + x * pict->bpp / 8 + 2] = r;
}

static	void 	test(t_struct *strct)
{
	int		x;

	x = strct->pos_iso->xmin;
	while (x <= strct->pos_iso->xmax)
	{
		my_pixel(strct->pict, x,
			strct->pos_iso->ymin +
			((strct->pos_iso->ymax - strct->pos_iso->ymin)
			* (x - strct->pos_iso->xmin))
			/ (strct->pos_iso->xmax - strct->pos_iso->xmin));
		x++;
	}
}

static	int		nb_digit(char *tab)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (tab[i])
	{
		if (ft_isdigit(tab[i]))
		{
			nb++;
			while (ft_isdigit(tab[i]))
				i++;
		}
		i++;
	}
	return (nb);
}

static	void 	pos_iso(t_struct *strct)
{
	strct->pos_iso->xmin = strct->pos_win->startx
	+ strct->coor->imin * strct->pos_win->pas
	+ strct->coor->jmin * strct->pos_win->pas;

	strct->pos_iso->ymin = strct->pos_win->starty
	+ strct->coor->imin * strct->pos_win->pas / strct->pos_win->inclix
	- strct->coor->jmin * strct->pos_win->pas / strct->pos_win->incliy
	- strct->coor->altmin * strct->pos_win->mult_alt;

	strct->pos_iso->xmax = strct->pos_win->startx
	+ strct->coor->imax * strct->pos_win->pas
	+ strct->coor->jmax * strct->pos_win->pas;

	strct->pos_iso->ymax = strct->pos_win->starty
	+ strct->coor->imax * strct->pos_win->pas / strct->pos_win->inclix
	- strct->coor->jmax * strct->pos_win->pas / strct->pos_win->incliy
	- strct->coor->altmax * strct->pos_win->mult_alt;
}

static	void 	segment(t_struct *strct)
{
	pos_iso(strct);
	test(strct);
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

static	int		ft_put_pxl(t_struct *strct)
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

int						loop_img(t_struct *strct)
{
	if (!(strct->win->mlx = mlx_init()))
		return (-1);
	strct->win->width = 1800;
	strct->win->height = 1800;
	strct->win->name = "Fdf";
	strct->pict->x = strct->win->width;
	strct->pict->y = strct->win->height;
	if ((!(strct->win->window = mlx_new_window(strct->win->mlx,
		strct->win->width, strct->win->height, strct->win->name)))
			|| (!(strct->pict->img = mlx_new_image(strct->win->mlx,
				strct->pict->x, strct->pict->y)))
			|| (!(strct->pict->data = mlx_get_data_addr(strct->pict->img,
				&strct->pict->bpp, &strct->pict->size_line, &strct->pict->endian))))
		return (-1);
	strct->pict->img_color = mlx_get_color_value(strct->win->mlx, 0xFFFFFF);
	strct->win->coor = change_tab(strct->win->tab);
	ft_puttab_int(strct->win->coor);
	ft_put_pxl(strct);
	mlx_key_hook(strct->win->window, &fct_key, NULL);
	mlx_mouse_hook(strct->win->window, &fct_mouse, strct);
	mlx_put_image_to_window(strct->win->mlx,
		strct->win->window, strct->pict->img, 0, 0);
	mlx_loop(strct->win->mlx);
	return (0);
}
