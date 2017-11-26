/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 08:47:11 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/09 19:27:07 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		len_malloc(long n)
{
	int		len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		len;
	long	n2;

	i = 0;
	n2 = n;
	len = len_malloc(n2);
	if (!(ret = (char *)ft_memalloc(len + 1)))
		return (NULL);
	if (n2 == 0)
		ret[i++] = '0';
	else if (n2 < 0)
	{
		n2 = n2 * -1;
		ret[i++] = '-';
	}
	while (n2 > 0)
	{
		ret[--len] = n2 % 10 + '0';
		i++;
		n2 = n2 / 10;
	}
	ret[i] = '\0';
	return (ret);
}
