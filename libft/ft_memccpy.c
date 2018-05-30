/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:26:31 by mpotapov          #+#    #+#             */
/*   Updated: 2016/12/30 18:03:59 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
					const void *restrict src, int c, size_t n)
{
	unsigned char	*s1;

	s1 = dst;
	while (n)
	{
		*s1 = *(const unsigned char *)src++;
		if (*s1 == (unsigned char)c)
			return (s1 + 1);
		s1++;
		n--;
	}
	return (NULL);
}
