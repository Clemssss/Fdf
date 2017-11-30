/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:42:59 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/30 12:23:46 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

static  void  draw_x(t_struct *strct, t_line line)
{
  int   i;
  int   cumul;

  cumul = line.diff_x / 2;
  i = 1;
  while (i <= line.diff_x)
  {
    line.x += line.x_incr;
    cumul += line.diff_y;
    if (cumul >= line.diff_x)
    {
      cumul -= line.diff_x;
      line.y += line.y_incr;
    }
    draw_pixel(strct->pict, line.x, line.y, 0xFFFFFF);
    i++;
  }
}

static  void  draw_y(t_struct *strct, t_line line)
{
  int   i;
  int   cumul;

  cumul = line.diff_y / 2;
  i = 1;
  while (i <= line.diff_y)
  {
    line.y += line.y_incr;
    cumul += line.diff_x;
    if (cumul >= line.diff_y)
    {
      cumul -= line.diff_y;
      line.x += line.x_incr;
    }
    draw_pixel(strct->pict, line.x, line.y, 0xFFFFFF);
    i++;
  }
}

void draw_line(t_struct *strct)
{
  t_line  line;

  line.x = strct->pos_iso->xmin;
  line.y = strct->pos_iso->ymin;
  line.diff_x = strct->pos_iso->xmax - strct->pos_iso->xmin;
  line.diff_y = strct->pos_iso->ymax - strct->pos_iso->ymin;
  line.x_incr = (line.diff_x > 0) ? 1 : -1;
  line.y_incr = (line.diff_y > 0) ? 1 : -1;
  line.diff_x = ABS(line.diff_x);
  line.diff_y = ABS(line.diff_y);
	draw_pixel(strct->pict, line.x, line.y, 0xFFFFFF);
  if (line.diff_x > line.diff_y)
    draw_x(strct, line);
  else
    draw_y(strct, line);
}
