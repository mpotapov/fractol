/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:10:07 by mpotapov          #+#    #+#             */
/*   Updated: 2017/01/03 19:11:43 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_w(char *s, char c)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (s[j] == c && s[j])
		j++;
	while (s[j])
	{
		while (s[j] != c && s[j])
			j++;
		i++;
		while (s[j] == c && s[j])
			j++;
	}
	return (i);
}
