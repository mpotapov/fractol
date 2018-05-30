/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:46:53 by mpotapov          #+#    #+#             */
/*   Updated: 2017/01/04 18:35:32 by mpotapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;

	if (*alst == NULL)
		return ;
	while (*alst)
	{
		new = *alst;
		*alst = (*alst)->next;
		del(new->content, new->content_size);
	}
	free(new);
	new = NULL;
}
