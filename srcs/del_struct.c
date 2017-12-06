/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:16:28 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/05 17:22:54 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	free_strct(t_struct *strct)
{
	ft_tabdel_int(strct->tab->coor);
	free(strct->tab->len_coor);
	free(strct->win);
	free(strct->pict);
	free(strct->coor);
	free(strct->pos_iso);
	free(strct->pos_win);
	free(strct->choix);
	free(strct->tab);
	free(strct->orig);
	free(strct->hsv);
	free(strct->menu);
	free(strct);
}
