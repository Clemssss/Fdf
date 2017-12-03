/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:25:47 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/03 17:47:11 by clegirar         ###   ########.fr       */
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
# include "../lib_mlx/includes/libmlx.h"

typedef struct  s_tab
{
  int           **coor;
  int           *len_coor;
  int           tl;
}               t_tab;

typedef struct  s_coor
{
  int           alt;
  int           alt2;
  unsigned  int color;
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
  float         degre;
  float         degre2;
  float         degre3;
  int           startx;
  int           starty;
  float         pas;
  float         mult_alt;
  int           key[269];
}               t_pos_win;

typedef struct  s_choix
{
  int           draw;
  int           diag;
}               t_choix;

typedef struct  s_orig
{
  int           x_or;
  int           y_or;
  int           z_or;
}               t_orig;

typedef struct  s_struct
{
  t_window      *win;
  t_pict        *pict;
  t_coor        *coor;
  t_pos_iso     *pos_iso;
  t_pos_win     *pos_win;
  t_choix       *choix;
  t_tab         *tab;
  t_orig        *orig;
}               t_struct;

/*  del_struct.c  */
void			      free_strct(t_struct *strct);

/*  do_change */
int             do_change(t_struct *strct);

/*  events.c  */
int             choice(int keycode, t_struct *strct);
int             fct_key(int keycode, t_struct *strct);
int             fct_mouse(int button, int x, int y, t_struct *strct);
int             key_off(int keycode, t_struct *strct);

/*  loop_img.c  */
int             loop_img(t_struct *strct);
void            center(t_struct *strct);

/*  pos.c */
void            pos_iso(t_struct *strct);
void            pos_para(t_struct *strct);

/*  put_pxl.c */
int             ft_put_pxl(t_struct *strct);

/*  rotations.c */
void            rotation_z(t_struct *strct);
void            rotation_x(t_struct *strct);
void            rotation_y(t_struct *strct);

#endif
