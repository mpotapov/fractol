/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:42:04 by mpotapov          #+#    #+#             */
/*   Updated: 2016/12/29 18:59:11 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;

	dst1 = dst;
	if (dst > src)
	{
		len--;
		while (len != (size_t)-1)
		{
			dst1[len] = ((const unsigned char *)src)[len];
			len--;
		}
	}
	else
	{
		while (len)
		{
			*dst1++ = *(const unsigned char *)src++;
			len--;
		}
	}
	return (dst);
}
