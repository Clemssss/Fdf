/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:25:54 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/10 15:32:25 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	rotation_z(t_struct *strct)
{
	t_rotate	rot;

	rot.radian = strct->pos_win->degre * 3.141 / 180;
	rot.x = strct->pos_iso->xmin - strct->pos_win->startx;
	rot.y = strct->pos_iso->ymin - strct->pos_win->starty;
	rot.z = strct->coor->alt - strct->orig->z_or;
	rot.x2 = strct->pos_iso->xmax - strct->pos_win->startx;
	rot.y2 = strct->pos_iso->ymax - strct->pos_win->starty;
	rot.z2 = strct->coor->alt2 - strct->orig->z_or;
	strct->pos_iso->xmin = rot.x * cos(rot.radian)
		+ rot.y * 0 + rot.z * (sin(rot.radian) * -1)
		+ strct->pos_win->startx;
	strct->pos_iso->ymin = rot.x * 0 + rot.y * 1 + rot.z * 0
		+ strct->pos_win->starty;
	strct->coor->alt = rot.x * sin(rot.radian)
		+ rot.y * 0 + rot.z * cos(rot.radian)
		+ strct->orig->z_or;
	strct->pos_iso->xmax = rot.x2 * cos(rot.radian)
		+ rot.y2 * 0 + rot.z2 * (sin(rot.radian) * -1)
		+ strct->pos_win->startx;
	strct->pos_iso->ymax = rot.x2 * 0 + rot.y2 * 1 + rot.z2 * 0
		+ strct->pos_win->starty;
	strct->coor->alt2 = rot.x2 * sin(rot.radian)
		+ rot.y2 * 0 + rot.z2 * cos(rot.radian)
		+ strct->orig->z_or;
}

void	rotation_x(t_struct *strct)
{
	t_rotate	rot;

	rot.radian = strct->pos_win->degre2 * 3.141 / 180;
	rot.x = strct->pos_iso->xmin - strct->pos_win->startx;
	rot.y = strct->pos_iso->ymin - strct->pos_win->starty;
	rot.z = strct->coor->alt - strct->orig->z_or;
	rot.x2 = strct->pos_iso->xmax - strct->pos_win->startx;
	rot.y2 = strct->pos_iso->ymax - strct->pos_win->starty;
	rot.z2 = strct->coor->alt2 - strct->orig->z_or;
	strct->pos_iso->xmin = rot.x * cos(rot.radian)
		+ rot.y * sin(rot.radian) + rot.z * 0
		+ strct->pos_win->startx;
	strct->pos_iso->ymin = rot.x * (sin(rot.radian) * -1)
		+ rot.y * cos(rot.radian) + rot.z * 0
		+ strct->pos_win->starty;
	strct->coor->alt = rot.x * 0 + rot.y * 0 + rot.z * 1
		+ strct->orig->z_or;
	strct->pos_iso->xmax = rot.x2 * cos(rot.radian)
		+ rot.y2 * sin(rot.radian) + rot.z2 * 0
		+ strct->pos_win->startx;
	strct->pos_iso->ymax = rot.x2 * (sin(rot.radian) * -1)
		+ rot.y2 * cos(rot.radian) + rot.z2 * 0
		+ strct->pos_win->starty;
	strct->coor->alt2 = rot.x2 * 0 + rot.y2 * 0 + rot.z2 * 1
		+ strct->orig->z_or;
}

void	rotation_y(t_struct *strct)
{
	t_rotate	rot;

	rot.radian = strct->pos_win->degre3 * 3.141 / 180;
	rot.x = strct->pos_iso->xmin - strct->pos_win->startx;
	rot.y = strct->pos_iso->ymin - strct->pos_win->starty;
	rot.z = strct->coor->alt - strct->orig->z_or;
	rot.x2 = strct->pos_iso->xmax - strct->pos_win->startx;
	rot.y2 = strct->pos_iso->ymax - strct->pos_win->starty;
	rot.z2 = strct->coor->alt2 - strct->orig->z_or;
	strct->pos_iso->xmin = rot.x * 1 + rot.y * 0 + rot.z * 0
		+ strct->pos_win->startx;
	strct->pos_iso->ymin = rot.x * 0
		+ rot.y * cos(rot.radian) + rot.z * sin(rot.radian)
		+ strct->pos_win->starty;
	strct->coor->alt = rot.x * 0 + rot.y * (sin(rot.radian) * -1)
		+ rot.z * cos(rot.radian)
		+ strct->orig->z_or;
	strct->pos_iso->xmax = rot.x2 * 1 + rot.y2 * 0 + rot.z2 * 0
		+ strct->pos_win->startx;
	strct->pos_iso->ymax = rot.x2 * 0 + rot.y2 * cos(rot.radian)
		+ rot.z2 * sin(rot.radian)
		+ strct->pos_win->starty;
	strct->coor->alt2 = rot.x2 * 0 + rot.y2 * (sin(rot.radian) * -1)
		+ rot.z2 * cos(rot.radian)
		+ strct->orig->z_or;
}
