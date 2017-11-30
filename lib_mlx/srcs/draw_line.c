/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:42:59 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/30 11:45:08 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void draw_line(t_pict *pict, int xi,int yi,int xf,int yf)
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
	draw_pixel(pict, x, y, 0xFFFFFF);
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
			draw_pixel(pict, x, y, 0xFFFFFF);
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
			draw_pixel(pict, x, y, 0xFFFFFF);
		}
	}
}
