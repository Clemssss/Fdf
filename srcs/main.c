/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:52:55 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/01 18:55:33 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "libft.h"

static	char	*read_and_fill(char **av)
{
	int		fd;
	int		ret;
	char	*tmp;
	char	*line;
	char	*l;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (NULL);
	tmp = NULL;
	line = NULL;
	ret = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		l = tmp;
		tmp = ft_strjoin(tmp, line);
		ft_strdel(&l);
	}
	if (ret == -1)
		return (NULL);
	return (tmp);
}

static	void 	init_strct(t_struct *strct)
{
	strct->pos_win->startx = 550;
	strct->pos_win->starty = 550;
	strct->pos_win->pas = 50;
	strct->pos_win->mult_alt = 1;
	strct->coor->color = 0xFFFFFF;
	strct->choix->draw = 0;
	strct->pos_win->degre = 0;
	strct->pos_win->degre2 = 0;
	strct->pos_win->degre3 = 0;
	strct->choix->x_or = 0;
	strct->choix->y_or = 0;
	strct->choix->z_or = 0;
	strct->pos_iso->xmin = 0;
	strct->pos_iso->ymin = 0;
	strct->pos_iso->xmax = 0;
	strct->pos_iso->ymax = 0;
}

int						main(int ac, char **av)
{
	t_struct	*strct;
	char			*tmp;

	(void)ac;
	if ((!(tmp = read_and_fill(av)))
			|| (!(strct = (t_struct *)ft_memalloc(sizeof(t_struct))))
			|| (!(strct->win = (t_window *)ft_memalloc(sizeof(t_window))))
			|| (!(strct->pict = (t_pict *)ft_memalloc(sizeof(t_pict))))
			|| (!(strct->coor = (t_coor *)ft_memalloc(sizeof(t_coor))))
			|| (!(strct->pos_iso = (t_pos_iso *)ft_memalloc(sizeof(t_pos_iso))))
			|| (!(strct->pos_win = (t_pos_win *)ft_memalloc(sizeof(t_pos_win))))
			|| (!(strct->choix = (t_choix *)ft_memalloc(sizeof(t_choix))))
			|| (!(strct->win->coor = ft_strsplit_int(strct, tmp, '\n'))))
		return (-1);
	ft_strdel(&tmp);
	init_strct(strct);
	loop_img(strct);
	return (0);
}
