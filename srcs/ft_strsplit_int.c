/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:11:24 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/01 19:38:35 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static	int		size_tab(char *tab, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

static	int		size_dig(char *tab, int i, char c)
{
	int	nb;

	nb = 0;
	while (tab[i] && tab[i] != c)
	{
		if (ft_isdigit(tab[i]) || tab[i] == '-' || tab[i] == '+')
		{
			nb++;
			while (ft_isdigit(tab[i]) || tab[i] == '-' || tab[i] == '+')
				i++;
		}
		else
			i++;
	}
	return (nb);
}

int						**ft_strsplit_int(t_struct *strct, char *tab, char c)
{
	int	**ret;
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	strct->win->tl = size_tab(tab, c);
	if(!(ret = (int **)ft_memalloc(sizeof(int *) * (strct->win->tl + 1))))
		return (NULL);
	while (tab[i])
	{
		if (tab[i] != c)
		{
			y = 0;
			if (!(ret[x] = (int *)ft_memalloc(sizeof(int) * (size_dig(tab, i, c) + 1))))
				return (NULL);
			while (tab[i] && tab[i] != c)
			{
				if (ft_isdigit(tab[i]) || tab[i] == '-' || tab[i] == '+')
				{
					ret[x][y++] = ft_atoi(&tab[i]) + '0';
					while (ft_isdigit(tab[i]) || tab[i] == '-' || tab[i] == '+')
						i++;
				}
				else
					i++;
			}
			ret[x][y] = 0;
			x++;
		}
		else
			i++;
	}
	ret[x] = NULL;
	strct->win->il = ft_intlen(ret[strct->win->tl / 2]);
	return (ret);
}
