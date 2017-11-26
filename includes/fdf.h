/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:25:47 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/26 16:27:20 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <math.h>

# define ABS(Value) ((Value) < 0 ? - (Value) : (Value))

typedef struct  s_window
{
  char          *name;
  int           width;
  int           height;
  void          *mlx;
  void          *window;
  char          **tab;
}               t_window;

typedef struct  s_pict
{
  char          *data;
  void          *img;
  int           bpp;
  int           size_line;
  int           endian;
  unsigned  int img_color;
  int           x;
  int           y;
}               t_pict;

int             loop_img(t_window *win);
void 	          del_window(t_window **win);
void 	          del_pict(t_pict **pict);
int             **ft_strsplit_int(char *tmp, char c);

#endif
