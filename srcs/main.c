/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:52:55 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/10 14:18:37 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "libmlx.h"

static	void	init_strct(t_struct *strct)
{
	float	ratio;

	strct->pos_win->startx = 550 + WIDTH_MENU;
	strct->pos_win->starty = 550;
	ratio = 10 / (float)strct->tab->tl;
	strct->pos_win->pas = ratio * 43;
	strct->pos_win->mult_alt = 0.1;
	strct->hsv->hue = 30;
	strct->hsv->saturation = 1;
	strct->hsv->value = 1;
	strct->hsv->hue = 150;
	strct->hsv->saturation = 1;
	strct->hsv->value = 1;
	strct->hsv->hue_alt = 150;
	strct->hsv->saturation_alt = 1;
	strct->hsv->value_alt = 1;
	strct->choix->iso = 1;
	strct->choix->col->color_uni = 0;
	strct->choix->col->color_uni_alt = 0;
}

static	void	ft_usage(void)
{
	ft_putstr("Usage : ./fdf file\n");
	exit(0);
}

int				main(int ac, char **av)
{
	t_struct	*strct;

	if (ac != 2)
		ft_usage();
	if ((!(strct = (t_struct *)ft_memalloc(sizeof(t_struct))))
			|| (!(strct->win = (t_window *)ft_memalloc(sizeof(t_window))))
			|| (!(strct->pict = (t_pict *)ft_memalloc(sizeof(t_pict))))
			|| (!(strct->coor = (t_coor *)ft_memalloc(sizeof(t_coor))))
			|| (!(strct->pos_iso = (t_pos_iso *)ft_memalloc(sizeof(t_pos_iso))))
			|| (!(strct->pos_win = (t_pos_win *)ft_memalloc(sizeof(t_pos_win))))
			|| (!(strct->choix = (t_choix *)ft_memalloc(sizeof(t_choix))))
			|| (!(strct->choix->col =
					(t_mycolor *)ft_memalloc(sizeof(t_mycolor))))
			|| (!(strct->tab = (t_tab *)ft_memalloc(sizeof(t_tab))))
			|| (!(strct->orig = (t_orig *)ft_memalloc(sizeof(t_orig))))
			|| (!(strct->hsv = (t_hsv *)ft_memalloc(sizeof(t_hsv))))
			|| (!(strct->menu = (t_menu *)ft_memalloc(sizeof(t_menu))))
			|| (!(strct->tab->coor = read_and_fill(strct->tab, av))))
		return (-1);
	init_strct(strct);
	loop_img(strct);
	return (0);
}
