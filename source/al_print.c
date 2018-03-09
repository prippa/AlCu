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
	if ((al->turn && al->stk) || (!al->turn && !al->stk))
		ft_printf("The %~s WON!\n", F_GREEN, "Player");
	else
		ft_printf("The %~s WON!\n", F_GREEN, "AI");
}

static int	al_get_max_n(t_stack *stk)
{
	int max;

	max = stk->n;
	stk = stk->next;
	while (stk)
	{
		if (max < stk->n)
			max = stk->n;
		stk = stk->next;
	}
	return (max);
}

void		al_print_board(t_alum1 *al)
{
	t_stack	*tmp;
	int		len;
	int		max;
	int		width;

	ft_clear();
	len = 1;
	tmp = al->stk;
	max = al_get_max_n(tmp);
	while (tmp)
	{
		ft_str_free(&al->buf);
		al->buf = ft_strnew(tmp->n);
		al->buf = ft_memset(al->buf, '|', tmp->n);
		width = (tmp->n + max) / 2;
		ft_printf("%d) %*~s\n", len, width, F_YELLOW, al->buf);
		len++;
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
