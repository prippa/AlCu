/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:13:45 by prippa            #+#    #+#             */
/*   Updated: 2018/03/09 16:13:47 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void		al_print_winer(t_alum1 *al)
{
	if (al->turn)
		ft_printf("The %~s WON!\n", F_GREEN, "Player");
	else
		ft_printf("The %~s WON!\n", F_GREEN, "AI");
}

void		al_print_board(t_alum1 *al)
{
	t_stack	*tmp;
	int		len;

	ft_clear();
	len = 1;
	tmp = al->stk;
	while (tmp)
	{
		ft_str_free(&al->buf);
		al->buf = ft_strnew(tmp->n);
		al->buf = ft_memset(al->buf, '|', tmp->n);
		ft_printf("%d) %~s\n", len, F_YELLOW, al->buf);
		len++;
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
