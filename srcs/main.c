/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:52:55 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/25 18:34:18 by clegirar         ###   ########.fr       */
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

int						main(int ac, char **av)
{
	t_window	*win;
	char			*tmp;

	(void)ac;
	if ((!(tmp = read_and_fill(av)))
			|| (!(win = (t_window *)ft_memalloc(sizeof(t_window))))
			|| (!(win->tab = ft_strsplit(tmp, '\n'))))
		return (-1);
	ft_strdel(&tmp);
	ft_puttab(win->tab, 1);
	loop_img(win);
	return (0);
}
