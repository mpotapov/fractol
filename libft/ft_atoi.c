/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:49:01 by mpotapov          #+#    #+#             */
/*   Updated: 2017/01/04 19:33:06 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			num;
	int			minus_f;
	int			i;
	const char	*tmp;

	tmp = str;
	i = 0;
	minus_f = 0;
	num = 0;
	while ((*tmp == ' ') || (*tmp == '\t') || (*tmp == '0') ||
		(*tmp == '\n') || (*tmp == '\f') || (*tmp == '\v') || (*tmp == '\r'))
		tmp++;
	if (*tmp == '-' || *tmp == '+')
		if (*tmp++ == '-')
			minus_f = 1;
	while (tmp[i] <= 57 && tmp[i] >= 48)
	{
		num = num + (tmp[i] - '0');
		if (tmp[i + 1] <= 57 && tmp[i + 1] >= 48)
			num = num * 10;
		i++;
	}
	return (minus_f ? -num : num);
}
