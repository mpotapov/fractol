/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:05:05 by mpotapov          #+#    #+#             */
/*   Updated: 2017/01/03 20:32:38 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_new_w(char *s, int first, int i)
{
	char	*dest;
	int		j;

	j = 0;
	if (!(dest = ft_strnew(i - first + 1)))
		return (NULL);
	while (i != first)
		dest[j++] = s[first++];
	dest[j] = '\0';
	return (dest);
}

char	**ft_strsplit(char *s, char c)
{
	char	**arr;
	int		first;
	int		i;
	int		c_words;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	c_words = ft_count_w(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (c_words + 1))))
		return (NULL);
	while (s[i] && c_words--)
	{
		while (s[i] == c && s[i])
			i++;
		first = i;
		while (s[i] != c && s[i])
			i++;
		arr[j++] = ft_new_w(s, first, i);
	}
	arr[j] = 0;
	return (arr);
}
