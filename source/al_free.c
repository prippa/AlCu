/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:59:09 by prippa            #+#    #+#             */
/*   Updated: 2018/03/09 14:59:11 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static void	al_stack_free(t_stack **stk)
{
	while (*stk)
	{
		free(*stk);
		*stk = (*stk)->next;
	}
}

void		al_free(t_alum1 *al)
{
	if (al->stk)
		al_stack_free(&al->stk);
	if (al->buf)
		ft_str_free(&al->buf);
	// if (al->pl.player_1)
	// 	ft_str_free(&al->pl.player_1);
	// if (al->pl.player_2)
	// 	ft_str_free(&al->pl.player_2);
}
