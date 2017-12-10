/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 12:50:23 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/10 12:52:14 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int		fct_key(int keycode, t_struct *strct)
{
	if (keycode == 53)
		free_strct_exit(strct);
	if (keycode)
		strct->pos_win->key[keycode] = 1;
	return (0);
}

int		key_off(int keycode, t_struct *strct)
{
	(void)strct;
	if (keycode && keycode != 35 && keycode != 31 && keycode != 6
			&& keycode != 34 && keycode != 7 && keycode != 8)
		strct->pos_win->key[keycode] = 0;
	return (0);
}
