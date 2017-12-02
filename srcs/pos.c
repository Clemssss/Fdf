/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:12:18 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/02 18:20:16 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	pos_iso(t_struct *strct)
{
	strct->pos_iso->xmin = strct->pos_win->startx
	+ strct->coor->imin * strct->pos_win->pas
	+ strct->coor->jmin * strct->pos_win->pas
	- strct->choix->x_or + strct->pos_win->startx;

	strct->pos_iso->ymin = strct->pos_win->starty
	+ strct->coor->imin * strct->pos_win->pas
	- strct->coor->jmin * strct->pos_win->pas
	- strct->coor->alt - strct->choix->y_or + strct->pos_win->starty;

	strct->pos_iso->xmax = strct->pos_win->startx
	+ strct->coor->imax * strct->pos_win->pas
	+ strct->coor->jmax * strct->pos_win->pas
	- strct->choix->x_or + strct->pos_win->startx;

	strct->pos_iso->ymax = strct->pos_win->starty
	+ strct->coor->imax * strct->pos_win->pas
	- strct->coor->jmax * strct->pos_win->pas
	- strct->coor->alt2 - strct->choix->y_or + strct->pos_win->starty;
}
