/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:01:11 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/10 13:25:40 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "libft.h"

static	int	nb_digit(char *line)
{
	int		nb;
	int		i;

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
		if (line[i] != '-' && line[i] != '+' && line[i] != '\n'
				&& line[i] != ' ' && line[i] != '\t' && !ft_isdigit(line[i]))
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

static	int	**stock_map(t_tab *strct, int **tmp, char *line, int *i)
{
	int		tl;
	int		il;

	tl = ft_tablen_int(tmp);
	il = ft_intlen(strct->len_coor);
	if ((!(tmp = (int**)ft_memrealloc((int**)tmp,
						tl * sizeof(*tmp), tl * sizeof(*tmp) + 1)))
			|| (!(strct->len_coor =
					(int*)ft_memrealloc((int*)strct->len_coor,
						il * sizeof(*strct->len_coor),
						il * sizeof(*strct->len_coor) + 1)))
			|| (!(tmp[*i] = concat_line(line))))
		return (NULL);
	strct->len_coor[*i] = ft_intlen(tmp[*i]);
	*i += 1;
	strct->tl += 1;
	ft_strdel(&line);
	return (tmp);
}

int			**read_and_fill(t_tab *strct, char **av)
{
	int		fd;
	int		ret;
	int		**tmp;
	int		i;
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
		if (!(tmp = stock_map(strct, tmp, line, &i)))
			return (NULL);
	}
	if (ret == -1)
		return (NULL);
	tmp[i] = NULL;
	return (tmp);
}
