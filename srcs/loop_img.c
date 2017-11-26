/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:52:10 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/26 18:21:50 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

static	int		fct_out(int keycode, void *param)
{
	t_window	*win;

	win = (t_window *)param;
	if (keycode == 53)
		exit(0);
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

  pict->data[y * pict->size_line + x * 4] = b;
  pict->data[y * pict->size_line + x * 4 + 1] = g;
  pict->data[y * pict->size_line + x * 4 + 2] = r;
}

static	void 	test(int x1, int y1, int x2, int y2, t_pict *pict)
{
	int		x;

	x = x1;
	while (x <= x2)
	{
		my_pixel(pict, x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1));
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

static	void 	pos_iso(int i, int j, int alt, int *outx, int *outy)
{
	int startx;
	int	starty;
  int pas;

	pas = 20;
  startx = 200;
 	starty = 200;
  *outx = startx + i * pas + j * pas;
  *outy = starty + i * pas / 2 - j * pas / 2 - alt;
}

static	int		get_alt(int i, int j)
{
    return (int)(15*cos(i*1.0/3)+15*sin(j*1.0/3));
}

static	void 	segment(t_pict *pict, int imin, int jmin, int imax, int jmax)
{
	int		xmin;
	int		ymin;
	int		xmax;
	int		ymax;

	pos_iso(imin, jmin, get_alt(imin, jmin), &xmin, &ymin);
	pos_iso(imax, jmax, get_alt(imax, jmax), &xmax, &ymax);
	test(xmin, ymin, xmax, ymax, pict);
}

static	int		ft_put_pxl(t_pict *pict, char **tab)
{
	int		x;
	int		y;

	x = 0;
	while (x < ft_tablen(tab))
	{
		y = 0;
		while (y < nb_digit(tab[x]))
		{
			segment(pict, y, x, y + 1, x);
			segment(pict, y, x, y, x + 1);
			y++;
		}
		x++;
	}
	return (0);
}

int						loop_img(t_window *win)
{
	t_pict		*pict;

	if ((!(pict = (t_pict *)ft_memalloc(sizeof(t_pict))))
			|| (!(win->mlx = mlx_init())))
		return (-1);
	win->width = 800;
	win->height = 800;
	win->name = "Fdf";
	pict->x = win->width;
	pict->y = win->height;
	if ((!(win->window = mlx_new_window(win->mlx, win->width, win->height, win->name)))
			|| (!(pict->img = mlx_new_image(win->mlx, pict->x, pict->y)))
			|| (!(pict->data = mlx_get_data_addr(pict->img, &pict->bpp, &pict->size_line, &pict->endian))))
		return (-1);
	pict->img_color = mlx_get_color_value(win->mlx, 0xF00ED1);
	mlx_key_hook(win->window, fct_out, win);
	ft_put_pxl(pict, win->tab);
	mlx_put_image_to_window(win->mlx, win->window, pict->img, 0, 0);
	mlx_loop(win->mlx);
	return (0);
}
