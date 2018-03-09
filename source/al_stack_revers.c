/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_stack_revers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:54:58 by prippa            #+#    #+#             */
/*   Updated: 2018/03/09 14:54:59 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	al_stack_revers(t_stack **stk)
{
	t_stack *prev;
	t_stack *current;
	t_stack *next;

	prev = NULL;
	current = *stk;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*stk = prev;
}
