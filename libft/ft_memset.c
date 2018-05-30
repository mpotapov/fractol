/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:34:12 by mpotapov          #+#    #+#             */
/*   Updated: 2016/12/30 18:00:09 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cc;
	int				i;

	i = 0;
	cc = b;
	while ((size_t)i < len)
	{
		*cc = c;
		cc++;
		i++;
	}
	return (b);
}
