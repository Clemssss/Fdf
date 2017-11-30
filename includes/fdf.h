/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:25:47 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/30 10:47:38 by clegirar         ###   ########.fr       */
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
  int           width;
  int           height;
  void          *mlx;
  void          *window;
  int           **coor;
}               t_window;

typedef struct  s_pict
{
  char          *data;
  void          *img;
  int           bpp;
  int           size_line;
  int           endian;
  int           x;
  int           y;
}               t_pict;

typedef struct  s_coor
{
  int           altmin;
  int           altmax;
  int           imin;
  int           jmin;
  int           imax;
  int           jmax;
}               t_coor;

typedef struct  s_pos_iso
{
  int           xmin;
  int           ymin;
  int           xmax;
  int           ymax;
}               t_pos_iso;

typedef struct  s_pos_win
{
  int           startx;
  int           starty;
  float         pas;
  float         inclix;
  float         incliy;
  float         mult_alt;
  int           key[269];
}               t_pos_win;

typedef struct  s_struct
{
  t_window      *win;
  t_pict        *pict;
  t_coor        *coor;
  t_pos_iso     *pos_iso;
  t_pos_win     *pos_win;
}               t_struct;

int             loop_img(t_struct *strct);
int             **change_tab(char *tab);
void            set_0(int *key);
void			      free_strct(t_struct *strct);

#endif
