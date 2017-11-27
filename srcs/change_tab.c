/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <clegirar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:11:24 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/27 14:00:30 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

static	int	size_dig(char *str)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			nb++;
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (nb);
}

int		**change_tab(char **tab)
{
	int	**ret;
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	if(!(ret = (int **)ft_memalloc(sizeof(int *) * (ft_tablen(tab) + 1))))
		return (NULL);
	while (tab[i])
	{
		j = 0;
		y = 0;
		if (!(ret[x] = (int *)ft_memalloc(sizeof(int) * (size_dig(tab[i]) + 1))))
			return (NULL);
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]))
			{
				if (tab[i][j] == '0')
					ret[x][y++] = '0';
				else
					ret[x][y++] = ft_atoi(&tab[i][j]);
				while (ft_isdigit(tab[i][j]))
					j++;
			}
			else
				j++;
		}
		ret[x][y] = '\0';
		x++;
		i++;
	}
	ret[x] = NULL;
	return (ret);
}
