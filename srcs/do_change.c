/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:16:00 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/01 18:42:08 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libmlx.h"

static	void 	move(t_struct *strct)
{
	if (strct->pos_win->key[126])
		strct->pos_win->starty -= 15;
	if (strct->pos_win->key[125])
		strct->pos_win->starty += 15;
	if (strct->pos_win->key[123])
		strct->pos_win->startx -= 15;
	if (strct->pos_win->key[124])
		strct->pos_win->startx += 15;
}

static	void 	rotate(t_struct *strct)
{
	if (strct->pos_win->key[13])
		strct->pos_win->degre += 1;
	if (strct->pos_win->key[1])
		strct->pos_win->degre -= 1;
	if (strct->pos_win->key[14])
		strct->pos_win->degre2 += 1;
	if (strct->pos_win->key[2])
		strct->pos_win->degre2 -= 1;
	if (strct->pos_win->key[15])
		strct->pos_win->degre3 += 1;
	if (strct->pos_win->key[3])
		strct->pos_win->degre3 -= 1;
}

static	void 	change_alt(t_struct *strct)
{
	if (strct->pos_win->key[69])
		strct->pos_win->mult_alt += 1;
	if (strct->pos_win->key[78])
		strct->pos_win->mult_alt -= 1;
}

int 					do_change(t_struct *strct)
{
	clear_pixels(strct);
	move(strct);
	change_alt(strct);
	rotate(strct);
	ft_put_pxl(strct);
	mlx_put_image_to_window(strct->win->mlx,
		strct->win->window, strct->pict->img, 0, 0);
	return (0);
}
