/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:06:00 by mpotapov          #+#    #+#             */
/*   Updated: 2016/12/30 17:47:59 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	int i;

	if (!(*lit))
		return ((char *)big);
	while (*big != '\0' && len)
	{
		if (*big == *lit)
		{
			i = 0;
			while (big[i] == lit[i] && i < (int)len && lit[i] != '\0')
				i++;
			if (lit[i] == '\0')
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
