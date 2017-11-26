/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:29:02 by clegirar          #+#    #+#             */
/*   Updated: 2017/11/25 13:04:45 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(const void *s, size_t old, size_t new)
{
	void	*tmp;

	if (!(tmp = ft_memalloc(new + old)))
		return (NULL);
	if (!s)
		return (tmp);
	tmp = ft_memcpy(tmp, s, old);
	ft_memdel((void *)&s);
	return (tmp);
}
