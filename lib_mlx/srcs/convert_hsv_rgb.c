/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hsv_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:21:19 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/06 15:11:10 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

static	void 	h_180_to_360(t_color *color, float h)
{
	if (h >= 180 && h < 240)
	{
		color->red = 0;
		color->green = color->x;
		color->blue = color->c;
	}
	else if (h >= 240 && h < 300)
	{
		color->red = color->x;
		color->green = 0;
		color->blue = color->c;
	}
	else if (h >= 300 && h < 360)
	{
		color->red = color->c;
		color->green = 0;
		color->blue = color->x;
	}
}

static	void 	h_0_to_180(t_color *color, float h)
{
	if (h >= 0 && h < 60)
	{
		color->red = color->c;
		color->green = color->x;
		color->blue = 0;
	}
	else if (h >= 60 && h < 120)
	{
		color->red = color->x;
		color->green = color->c;
		color->blue = 0;
	}
	else if (h >= 120 && h < 180)
	{
		color->red = 0;
		color->green = color->c;
		color->blue = color->x;
	}
}

void					conv_hsv_rgb(t_pict *pict, float h, float s, float v)
{
	t_color		color;

	color.c = v * s;
	color.x = color.c * (1 - ((int)h / 60) % 2 - 1);
	color.m = v - color.c;
	if (h >= 0 && h < 180)
		h_0_to_180(&color, h);
	else if (h >= 180 && h < 360)
		h_180_to_360(&color, h);
	pict->r = (color.red + color.m) * 255;
	pict->g = (color.green + color.m) * 255;
	pict->b = (color.blue + color.m) * 255;
}
