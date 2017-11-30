/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:42:24 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/30 12:00:57 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void 	clear_pixels(t_struct *strct)
{
	int	x;
	int	y;

	y = 0;
	while (y < strct->pict->y)
	{
		x = 0;
		while (x < strct->pict->x)
		{
			strct->pict->data[y * strct->pict->size_line + x * strct->pict->bpp / 8] = 0;
		  strct->pict->data[y * strct->pict->size_line + x * strct->pict->bpp / 8 + 1] = 0;
		  strct->pict->data[y * strct->pict->size_line + x * strct->pict->bpp / 8 + 2] = 0;
			x++;
		}
		y++;
	}
}
