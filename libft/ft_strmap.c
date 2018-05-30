/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:59:05 by mpotapov          #+#    #+#             */
/*   Updated: 2016/12/29 18:00:08 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *buf;
	char *d;

	if (s == NULL || !(buf = ft_strnew(ft_strlen(s))))
		return (NULL);
	d = buf;
	while (*s)
		*buf++ = f(*s++);
	*buf = '\0';
	return (d);
}
