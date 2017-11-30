/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:52:55 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/30 10:59:42 by clegirar         ###   ########.fr       */
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
	strct->pos_win->startx = 300;
	strct->pos_win->starty = 700;
	strct->pos_win->pas = 50;
	strct->pos_win->inclix = 1.7;
	strct->pos_win->incliy = 1.7;
	strct->pos_win->mult_alt = 16;
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
			|| (!(strct->win->coor = change_tab(tmp))))
		return (-1);
	ft_strdel(&tmp);
	init_strct(strct);
	loop_img(strct);
	return (0);
}
