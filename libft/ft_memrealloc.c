/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:29:02 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/03 16:21:50 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *s, size_t old, size_t new)
{
	void	*tmp;

	if (!(tmp = ft_memalloc(new)))
		return (NULL);
	if (!s)
		return (tmp);
	ft_memcpy(tmp, s, old);
	free(s);
	return (tmp);
}
