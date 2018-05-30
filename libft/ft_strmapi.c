/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 18:00:14 by mpotapov          #+#    #+#             */
/*   Updated: 2016/12/29 18:00:59 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buf;
	unsigned int	i;

	if (s == NULL || !(buf = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		buf[i] = f(i, s[i]);
	buf[i] = '\0';
	return (buf);
}
