/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:14:37 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/02 15:05:21 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int		fct_key(int keycode, t_struct *strct)
{
	if (keycode == 53)
	{
		mlx_destroy_image(strct->win->mlx, strct->pict->img);
		mlx_destroy_window(strct->win->mlx, strct->win->window);
		free_strct(strct);
		exit(0);
	}
	if (keycode == 35)
		strct->choix->draw = ((strct->choix->draw) == 0 ? 1 : 0);
	if (keycode && keycode != 35)
		strct->pos_win->key[keycode] = 1;
	return (0);
}

int		fct_mouse(int button, int x, int y, t_struct *strct)
{
	(void)x;
	(void)y;
	if (button == 5)
		strct->pos_win->pas += 1;
	if (button == 4 && strct->pos_win->pas > 1)
		strct->pos_win->pas -= 1;
	return (0);
}

int 	key_off(int keycode, t_struct *strct)
{
	(void)strct;
	if (keycode && keycode != 35)
		strct->pos_win->key[keycode] = 0;
	return (0);
}
