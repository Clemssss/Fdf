/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:52:55 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/09 19:13:01 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "libft.h"
#include "libmlx.h"

static	int		nb_digit(char *line)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
		{
			nb++;
			while (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
				i++;
		}
		else
			i++;
	}
	return (nb);
}

static	int	*concat_line(char *line)
{
	int		i;
	int		j;
	int		*tab;

	i = 0;
	j = 0;
	tab = NULL;
	if (!(tab = (int *)ft_memalloc(sizeof(int) * (nb_digit(line) + 1))))
		return (NULL);
	while (line[i])
	{
		if (line[i] != '-' && line[i] != '+' && line[i] != '\n' && line[i] != ' '
				&& line[i] != '\t' && !ft_isdigit(line[i]))
				return (NULL);
		if (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
		{
			tab[j++] = ft_atoi(&line[i]) + '0';
			while (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
				i++;
		}
		else
			i++;
	}
	tab[j] = '\0';
	return (tab);
}

static	int	**read_and_fill(t_tab *strct, char **av)
{
	int		fd;
	int		ret;
	int		**tmp;
	int		i;
	int		tl;
	int		il;
	char	*line;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (NULL);
	line = NULL;
	tmp = NULL;
	ret = 0;
	i = 0;
	strct->tl = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		tl = ft_tablen_int(tmp);
		il = ft_intlen(strct->len_coor);
		if ((!(tmp = (int**)ft_memrealloc((int**)tmp,
					tl * sizeof(*tmp), tl * sizeof(*tmp) + 1)))
				|| (!(strct->len_coor = (int*)ft_memrealloc((int*)strct->len_coor,
						il * sizeof(*strct->len_coor), il * sizeof(*strct->len_coor) + 1)))
				|| (!(tmp[i] = concat_line(line))))
			return (NULL);
		strct->len_coor[i] = ft_intlen(tmp[i]);
		i++;
		strct->tl += 1;
		ft_strdel(&line);
	}
	if (ret == -1)
		return (NULL);
	tmp[i] = NULL;
	return (tmp);
}

static	void 	init_strct(t_struct *strct)
{
	float	ratio;

	strct->pos_win->startx = 550 + WIDTH_MENU;
	strct->pos_win->starty = 550;
	ratio = 10 / (float)strct->tab->tl;
	strct->pos_win->pas = ratio * 43;
	strct->pos_win->mult_alt = 1;
	strct->hsv->hue = 30;
	strct->hsv->saturation = 1;
	strct->hsv->value = 1;
	strct->hsv->hue = 150;
	strct->hsv->saturation = 1;
	strct->hsv->value = 1;
	strct->hsv->hue_alt = 150;
	strct->hsv->saturation_alt = 1;
	strct->hsv->value_alt = 1;
	strct->choix->iso = 1;
	strct->choix->col->color_uni = 0;
	strct->choix->col->color_uni_alt = 0;
}

static	void 	ft_usage(void)
{
	ft_putstr("Usage : ./fdf file\n");
	exit(0);
}

int						main(int ac, char **av)
{
	t_struct	*strct;

	if (ac != 2)
		ft_usage();
	if ((!(strct = (t_struct *)ft_memalloc(sizeof(t_struct))))
			|| (!(strct->win = (t_window *)ft_memalloc(sizeof(t_window))))
			|| (!(strct->pict = (t_pict *)ft_memalloc(sizeof(t_pict))))
			|| (!(strct->coor = (t_coor *)ft_memalloc(sizeof(t_coor))))
			|| (!(strct->pos_iso = (t_pos_iso *)ft_memalloc(sizeof(t_pos_iso))))
			|| (!(strct->pos_win = (t_pos_win *)ft_memalloc(sizeof(t_pos_win))))
			|| (!(strct->choix = (t_choix *)ft_memalloc(sizeof(t_choix))))
			|| (!(strct->choix->col = (t_mycolor *)ft_memalloc(sizeof(t_mycolor))))
			|| (!(strct->tab = (t_tab *)ft_memalloc(sizeof(t_tab))))
			|| (!(strct->orig = (t_orig *)ft_memalloc(sizeof(t_orig))))
			|| (!(strct->hsv = (t_hsv *)ft_memalloc(sizeof(t_hsv))))
			|| (!(strct->menu = (t_menu *)ft_memalloc(sizeof(t_menu))))
			|| (!(strct->tab->coor = read_and_fill(strct->tab, av))))
		return (-1);
	init_strct(strct);
	loop_img(strct);
	return (0);
}
