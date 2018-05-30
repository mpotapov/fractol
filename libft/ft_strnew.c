/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:53:31 by mpotapov          #+#    #+#             */
/*   Updated: 2017/03/25 17:28:00 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*buf;
	int		i;

	i = 0;
	if (!(buf = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while ((size_t)i < size)
	{
		buf[i] = '\0';
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
