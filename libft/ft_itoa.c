/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:13:14 by mpotapov          #+#    #+#             */
/*   Updated: 2017/01/03 20:11:52 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				num_of_n;
	char			*str;
	int				i;
	unsigned int	k;

	i = 0;
	num_of_n = ft_count_n_itoa(n);
	if (!(str = ft_strnew(num_of_n)))
		return (NULL);
	k = n;
	if (n < 0)
		k = -n;
	if (n == 0)
		str[i++] = '0';
	while (k > 0)
	{
		str[i++] = k % 10 + '0';
		k = k / 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	str = ft_reverse_str(str, num_of_n);
	return (str);
}
