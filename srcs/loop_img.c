/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:52:10 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/28 15:53:33 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

static	int 	clear_pixels(t_struct *strct)
{
	int	x;
	int	y;

	y = 0;
	while (y < strct->win->width)
	{
		x = 0;
		while (x < strct->win->height)
		{
			strct->pict->data[y * strct->pict->size_line + x * strct->pict->bpp / 8] = 0;
		  strct->pict->data[y * strct->pict->size_line + x * strct->pict->bpp / 8 + 1] = 0;
		  strct->pict->data[y * strct->pict->size_line + x * strct->pict->bpp / 8 + 2] = 0;
			x++;
		}
		y++;
	}
	return (0);
}

static	int		fct_key(int keycode, t_struct *strct)
{
	if (keycode == 53)
		exit(0);
	if (keycode)
	{
		dprintf(1, "keycode = %d\n", keycode);
		strct->pos_win->key[keycode] = 1;
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

void line(t_pict *pict, int xi,int yi,int xf,int yf)
{
  int dx,dy,i,xinc,yinc,cumul,x,y ;
  x = xi ;
  y = yi ;
  dx = xf - xi ;
  dy = yf - yi ;
  xinc = ( dx > 0 ) ? 1 : -1 ;
  yinc = ( dy > 0 ) ? 1 : -1 ;
  dx = ABS(dx) ;
  dy = ABS(dy) ;
	my_pixel(pict, x, y);
  if ( dx > dy )
	{
    cumul = dx / 2 ;
    for ( i = 1 ; i <= dx ; i++ )
		{
      x += xinc ;
      cumul += dy ;
      if ( cumul >= dx )
			{
        cumul -= dx ;
        y += yinc ;
			}
			my_pixel(pict, x, y);
		}
	}
  else
	{
    cumul = dy / 2 ;
  	for ( i = 1 ; i <= dy ; i++ )
		{
			y += yinc ;
    	cumul += dx ;
      if ( cumul >= dy )
			{
      	cumul -= dy ;
      	x += xinc ;
			}
			my_pixel(pict, x, y);
		}
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
	line(strct->pict, strct->pos_iso->xmin, strct->pos_iso->ymin, strct->pos_iso->xmax, strct->pos_iso->ymax);
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

void 	set_0(int *key)
{
	int 	i;

	i = 0;
	while (key[i])
		key[i] = 0;
}

static	void 	zoom(t_struct *strct)
{
	if (strct->pos_win->key[126])
		strct->pos_win->mult_alt += 1;
	if (strct->pos_win->key[125])
		strct->pos_win->mult_alt -= 1;
	if (strct->pos_win->key[12])
		strct->pos_win->startx -= 5;
	if (strct->pos_win->key[13])
		strct->pos_win->startx += 5;
	if (strct->pos_win->key[14] && strct->pos_win->starty > 295)
		strct->pos_win->starty -= 5;
	if (strct->pos_win->key[15])
		strct->pos_win->starty += 5;
	if (strct->pos_win->key[69] && strct->pos_win->mult_alt < 57)
		strct->pos_win->pas += 1;
	if (strct->pos_win->key[78])
		strct->pos_win->pas -= 1;
}

static	int 	test(t_struct *strct)
{
	clear_pixels(strct);
	zoom(strct);
	ft_put_pxl(strct);
	mlx_put_image_to_window(strct->win->mlx,
		strct->win->window, strct->pict->img, 0, 0);
	return (0);
}

static	int 	key_off(int keycode, t_struct *strct)
{
	if (keycode)
		strct->pos_win->key[keycode] = 0;
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
	mlx_hook(strct->win->window, 2, 0, &fct_key, strct);
	mlx_loop_hook(strct->win->mlx, &test, strct);
	mlx_key_hook(strct->win->window, &key_off, strct);
	mlx_loop(strct->win->mlx);
	free_strct(strct);
	return (0);
}
