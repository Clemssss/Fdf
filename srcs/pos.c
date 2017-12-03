/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:12:18 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/03 22:26:10 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	pos_iso(t_struct *strct)
{
	strct->pos_iso->xmin = strct->pos_win->startx
	+ strct->coor->imin * strct->pos_win->pas
	+ strct->coor->jmin * strct->pos_win->pas
	- strct->orig->x_or + strct->pos_win->startx;

	strct->pos_iso->ymin = strct->pos_win->starty
	+ strct->coor->imin * strct->pos_win->pas
	- strct->coor->jmin * strct->pos_win->pas
	- strct->coor->alt - strct->orig->y_or + strct->pos_win->starty;

	strct->pos_iso->xmax = strct->pos_win->startx
	+ strct->coor->imax * strct->pos_win->pas
	+ strct->coor->jmax * strct->pos_win->pas
	- strct->orig->x_or + strct->pos_win->startx;

	strct->pos_iso->ymax = strct->pos_win->starty
	+ strct->coor->imax * strct->pos_win->pas
	- strct->coor->jmax * strct->pos_win->pas
	- strct->coor->alt2 - strct->orig->y_or + strct->pos_win->starty;
}

void 	pos_para(t_struct *strct)
{
	strct->pos_iso->xmin = strct->pos_win->startx
	+ strct->coor->imin * strct->pos_win->pas
	- strct->coor->alt;
	strct->pos_iso->ymin = strct->pos_win->starty
	+ strct->coor->jmin * strct->pos_win->pas
	- strct->coor->alt;
	strct->pos_iso->xmax = strct->pos_win->startx
	+ strct->coor->imax * strct->pos_win->pas
	- strct->coor->alt2;
	strct->pos_iso->ymax = strct->pos_win->starty
	+ strct->coor->jmax * strct->pos_win->pas
	- strct->coor->alt2;
}
