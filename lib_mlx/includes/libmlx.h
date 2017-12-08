/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:36:55 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/08 12:24:28 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLX_H
# define LIBMLX_H

# define ABS(Value) ((Value) < 0 ? - (Value) : (Value))
# define WIDTH 1800
# define HEIGHT 1200

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_color
{
  float         c;
  float         x;
  float         m;
  float         red;
  float         green;
  float         blue;
}               t_color;

typedef struct  s_hsv
{
  float         hue;
  float         saturation;
  float         value;
}               t_hsv;

typedef struct  s_window
{
  int           width;
  int           height;
  void          *mlx;
  void          *window;
}               t_window;

typedef struct  s_pict
{
	int           r;
  int           g;
  int           b;
  char          *data;
  void          *img;
  int           bpp;
  int           size_line;
  int           endian;
  int           x;
  int           y;
}               t_pict;

typedef	struct	s_line
{
	int						x;
	int						y;
	int						diff_x;
	int						diff_y;
	int						x_incr;
	int						y_incr;
}								t_line;

/*	clear_pixels.c */
void 	clear_pixels(t_pict *pict);

/*	convert_hsv_rgb	*/
void	conv_hsv_rgb(t_pict *pict, float, float, float);

/*	draw_pixel.c	*/
void 	draw_pixel(t_pict *pict, int x, int y);

/*	draw_line.c  */
void 	draw_line(t_pict *, int, int, int, int, int);

#endif
