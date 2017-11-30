/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:11:24 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/30 10:57:15 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static	int		size_tab(char *tab)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (tab[i])
	{
		if (tab[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

static	int		size_dig(char *tab, int i)
{
	int	nb;

	nb = 0;
	while (tab[i] && tab[i] != '\n')
	{
		if (ft_isdigit(tab[i]))
		{
			nb++;
			while (ft_isdigit(tab[i]))
				i++;
		}
		else
			i++;
	}
	return (nb);
}

int		**change_tab(char *tab)
{
	int	**ret;
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	if(!(ret = (int **)ft_memalloc(sizeof(int *) * (size_tab(tab) + 1))))
		return (NULL);
	while (tab[i])
	{
		if (tab[i] != '\n')
		{
			y = 0;
			if (!(ret[x] = (int *)ft_memalloc(sizeof(int) * (size_dig(tab, i) + 1))))
				return (NULL);
			while (tab[i] && tab[i] != '\n')
			{
				if (ft_isdigit(tab[i]))
				{
					if (tab[i] == '0')
						ret[x][y++] = '0';
					else
						ret[x][y++] = ft_atoi(&tab[i]);
					while (ft_isdigit(tab[i]))
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
	return (ret);
}
