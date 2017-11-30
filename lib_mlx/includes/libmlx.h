/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:36:55 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/30 12:18:32 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLX_H
# define LIBMLX_H

# include "../../includes/fdf.h"

# define ABS(Value) ((Value) < 0 ? - (Value) : (Value))

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
void 	clear_pixels(t_struct *strct);

/*	draw_pixel.c	*/
void 	draw_pixel(t_pict *pict, int x, int y, unsigned int color);

/*	draw_line.c	*/
void 	draw_line(t_struct *strct);

#endif
