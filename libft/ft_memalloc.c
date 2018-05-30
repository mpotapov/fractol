/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:50:39 by mpotapov          #+#    #+#             */
/*   Updated: 2016/12/29 17:52:17 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*buf;
	char	*l;

	if (!(buf = (char *)malloc(sizeof(buf) * size)))
		return (NULL);
	l = buf;
	while (size)
	{
		*buf++ = 0;
		size--;
	}
	return (l);
}
