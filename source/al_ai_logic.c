/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_ai_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:52:21 by prippa            #+#    #+#             */
/*   Updated: 2018/03/10 14:52:24 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	check_turn(t_stack *s)
{
	if (!(s->next))
		return (0);
	if (!check_turn(s->next))
		if (s->next->n % 4 == 1)
			return (1);
		else
			return (0);
	else if (s->next->n % 4 == 0)
		return (1);
	else
		return (0);
	return (0);
}

static int	try_to_catch(int n)
{
	if (n % 4 == 0)
		return (1);
	return (n % 4);
}

static int	turn_in(int n)
{
	if (n % 4 == 1 || n % 4 == 2)
		return (1);
	if (n % 4 == 3)
		return (2);
	if (n % 4 == 0)
		return (3);
	return (0);
}

int			al_ai_logic(t_alum1 *al)
{
	int	cmatch;

	cmatch = check_turn(al->stk);
	if (cmatch)
		return (try_to_catch(al->stk->n));
	else
		return (turn_in(al->stk->n));
}
