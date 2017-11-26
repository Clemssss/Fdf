/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:16:28 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/24 17:52:53 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void 	del_window(t_window **win)
{
	dprintf(1, "here\n");
	if ((*win)->name)
		ft_strdel(&(*win)->name);
	(*win)->width = 0;
	(*win)->height = 0;
	if ((*win)->mlx)
		ft_memdel(&(*win)->mlx);
	if ((*win)->window)
		ft_memdel(&(*win)->window);
	if (*win)
		free(*win);
	*win = NULL;
}

void 	del_pict(t_pict **pict)
{
	ft_strdel(&(*pict)->data);
	ft_memdel(&(*pict)->img);
	(*pict)->bpp = 0;
	(*pict)->size_line = 0;
	(*pict)->endian = 0;
	(*pict)->img_color = 0;
	(*pict)->x = 0;
	(*pict)->y = 0;
	free(*pict);
	*pict = NULL;
}
