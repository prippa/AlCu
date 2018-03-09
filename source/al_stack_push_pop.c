/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_stack_push_pop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:54:39 by prippa            #+#    #+#             */
/*   Updated: 2018/03/09 14:54:43 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		al_stack_push(t_stack **stk, int n)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (-1);
	new->n = n;
	new->next = *stk;
	*stk = new;
	return (1);
}

void	al_stack_pop(t_stack **stk)
{
	t_stack *tmp;

	tmp = *stk;
	*stk = (*stk)->next;
	free(tmp);
}
