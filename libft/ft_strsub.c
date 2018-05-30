/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 18:04:16 by mpotapov          #+#    #+#             */
/*   Updated: 2016/12/29 18:05:59 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *buf;
	char *bufstart;

	if (s == NULL)
		return (NULL);
	if (!(buf = ft_strnew(len)))
		return (NULL);
	bufstart = buf;
	while (len--)
		*buf++ = s[start++];
	*buf = '\0';
	return (bufstart);
}
