/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 05:37:54 by mpotapov          #+#    #+#             */
/*   Updated: 2017/01/03 20:42:09 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_count_words(char *str)
{
	int		i;
	int		words;
	char	**arr;

	i = 0;
	words = 0;
	while (str[i] == '\n' || str[i] == 32 || str[i] == 9)
		i++;
	while (str[i] != '\0')
	{
		i++;
		if ((str[i] == '\n' || str[i] == ' ' || str[i] == 9 || '\0'))
		{
			words++;
			while ((str[i] == '\n' || str[i] == ' ' || str[i] == 9))
				i++;
		}
	}
	if (!(str[i - 1] == '\n' || str[i - 1] == ' ' || str[i - 1] == 9))
		words++;
	arr = (char**)malloc(sizeof(*arr) * (words + 1));
	return (arr);
}

static char		**ft_count_letters(char *str, char **arr)
{
	int i;
	int letters;
	int a;

	a = 0;
	i = 0;
	letters = 0;
	while (str[i] == '\n' || str[i] == 32 || str[i] == 9)
		i++;
	while (str[i] != '\0')
	{
		i++;
		letters++;
		if (str[i] == '\n' || str[i] == ' ' || str[i] == 9 || str[i] == '\0')
		{
			arr[a] = (char*)malloc(sizeof(arr) * (letters + 1));
			letters = 0;
			a++;
			while (str[i] == '\n' || str[i] == ' ' || str[i] == 9)
				i++;
		}
	}
	return (arr);
}

static char		**into_arr(char *str, char **arr)
{
	int row;
	int i;
	int col;

	i = 0;
	row = 0;
	col = 0;
	while (str[i] == '\n' || str[i] == 32 || str[i] == 9)
		i++;
	while (str[i] != '\0')
	{
		i++;
		arr[row][col] = str[i - 1];
		col++;
		if (str[i] == '\n' || str[i] == ' ' || str[i] == 9 || str[i] == '\0')
		{
			arr[row][col] = '\0';
			col = 0;
			row++;
			while (str[i] == '\n' || str[i] == ' ' || str[i] == 9)
				i++;
		}
	}
	arr[row] = 0;
	return (arr);
}

char			**ft_split_whitespaces(char *str)
{
	char **arr;

	arr = ft_count_words(str);
	arr = ft_count_letters(str, arr);
	arr = into_arr(str, arr);
	return (arr);
}
