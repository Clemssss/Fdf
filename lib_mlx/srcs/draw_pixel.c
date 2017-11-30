/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:43:25 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/30 12:57:53 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void 	draw_pixel(t_pict *pict, int x, int y, unsigned int color)
{
	unsigned	char	r;
	unsigned	char	g;
	unsigned	char	b;

	r = (color & 0xFF0000) >> 16;
  g = (color & 0xFF00) >> 8;
  b = (color & 0xFF);

  pict->data[y * pict->size_line + x * pict->bpp / 8] = b;
  pict->data[y * pict->size_line + x * pict->bpp / 8 + 1] = g;
  pict->data[y * pict->size_line + x * pict->bpp / 8 + 2] = r;
}
