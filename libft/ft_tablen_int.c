/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:41:10 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/27 12:41:42 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tablen_int(int **tab)
{
	int	x;

	x = 0;
	while (tab[x])
		x++;
	return (x);
}
