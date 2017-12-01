/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:25:54 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/01 19:52:44 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void 	rotation_z(t_struct *strct)
{
	float	radian;
	int		x;
	int		y;
	int		x2;
	int		y2;
	int		z;
	int		z2;

	radian = strct->pos_win->degre * 3.141 / 180;
	x = strct->pos_iso->xmin - strct->choix->x_or;
	y = strct->pos_iso->ymin - strct->choix->y_or;
	z = strct->coor->alt - strct->choix->z_or;
	x2 = strct->pos_iso->xmax - strct->choix->x_or;
	y2 = strct->pos_iso->ymax - strct->choix->y_or;
	z2 = strct->coor->alt2 - strct->choix->z_or;
	strct->pos_iso->xmin = x * cos(radian) + y * 0 + z * (sin(radian) * -1)
	+ strct->choix->x_or;
	strct->pos_iso->ymin = x * 0 + y * 1 + z * 0
	+ strct->choix->y_or;
	strct->coor->alt = x * sin(radian) + y * 0 + z * cos(radian)
	+ strct->choix->z_or;
	strct->pos_iso->xmax = x2 * cos(radian) + y2 * 0 + z2 * (sin(radian) * -1)
	+ strct->choix->x_or;
	strct->pos_iso->ymax = x2 * 0 + y2 * 1 + z2 * 0
	+ strct->choix->y_or;
	strct->coor->alt2 = x2 * sin(radian) + y2 * 0 + z2 * cos(radian)
	+ strct->choix->z_or;
}

void 	rotation_x(t_struct *strct)
{
	float	radian;
	int		x;
	int		y;
	int		x2;
	int		y2;
	int		z;
	int		z2;

	radian = strct->pos_win->degre2 * 3.141 / 180;
	x = strct->pos_iso->xmin - strct->choix->x_or;
	y = strct->pos_iso->ymin - strct->choix->y_or;
	z = strct->coor->alt - strct->choix->z_or;
	x2 = strct->pos_iso->xmax - strct->choix->x_or;
	y2 = strct->pos_iso->ymax - strct->choix->y_or;
	z2 = strct->coor->alt2 - strct->choix->z_or;
	strct->pos_iso->xmin = x * cos(radian) + y * sin(radian) + z * 0
	+ strct->choix->x_or;
	strct->pos_iso->ymin = x * (sin(radian) * -1) + y * cos(radian) + z * 0
	+ strct->choix->y_or;
	strct->coor->alt = x * 0 + y * 0 + z * 1
	+ strct->choix->z_or;
	strct->pos_iso->xmax = x2 * cos(radian) + y2 * sin(radian) + z2 * 0
	+ strct->choix->x_or;
	strct->pos_iso->ymax = x2 * (sin(radian) * -1) + y2 * cos(radian) + z2 * 0
	+ strct->choix->y_or;
	strct->coor->alt2 = x2 * 0 + y2 * 0 + z2 * 1
	+ strct->choix->z_or;
}

void 	rotation_y(t_struct *strct)
{
	float	radian;
	int		x;
	int		y;
	int		x2;
	int		y2;
	int		z;
	int		z2;

	radian = strct->pos_win->degre3 * 3.141 / 180;
	x = strct->pos_iso->xmin - strct->choix->x_or;
	y = strct->pos_iso->ymin - strct->choix->y_or;
	z = strct->coor->alt - strct->choix->z_or;
	x2 = strct->pos_iso->xmax - strct->choix->x_or;
	y2 = strct->pos_iso->ymax - strct->choix->y_or;
	z2 = strct->coor->alt2 - strct->choix->z_or;
	strct->pos_iso->xmin = x * 1 + y * 0 + z * 0
	+ strct->choix->x_or;
	strct->pos_iso->ymin = x * 0 + y * cos(radian) + z * sin(radian)
	+ strct->choix->y_or;
	strct->coor->alt = x * 0 + y * (sin(radian) * -1) + z * cos(radian)
	+ strct->choix->z_or;
	strct->pos_iso->xmax = x2 * 1 + y2 * 0 + z2 * 0
	+ strct->choix->x_or;
	strct->pos_iso->ymax = x2 * 0 + y2 * cos(radian) + z2 * sin(radian)
	+ strct->choix->y_or;
	strct->coor->alt2 = x2 * 0 + y2 * (sin(radian) * -1) + z2 * cos(radian)
	+ strct->choix->z_or;
}
