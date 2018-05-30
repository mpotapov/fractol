/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:53:22 by mpotapov          #+#    #+#             */
/*   Updated: 2017/01/03 20:12:26 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_str(char *str, int n)
{
	char	*dest;
	int		i;

	i = 0;
	dest = ft_strnew(n);
	n--;
	while (str[i] != '\0')
	{
		dest[i] = str[n];
		i++;
		n--;
	}
	return (dest);
}
