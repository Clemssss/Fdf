/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:36:55 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/03 17:53:23 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLX_H
# define LIBMLX_H

# define ABS(Value) ((Value) < 0 ? - (Value) : (Value))

typedef struct  s_window
{
  int           width;
  int           height;
  void          *mlx;
  void          *window;
}               t_window;

typedef struct  s_pict
{
	unsigned	int	color;
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

/*	draw_pixel.c	*/
void 	draw_pixel(t_pict *pict, int x, int y, unsigned int color);

/*	draw_line.c	*/
void 	draw_line(t_pict *, int, int, int, int, int);

#endif
