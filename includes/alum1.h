/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:09:16 by prippa            #+#    #+#             */
/*   Updated: 2018/03/09 13:09:20 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include "libft.h"
# include "ft_printf.h"

typedef	struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef	struct		s_alum1
{
	t_stack			*stk;
	char			*buf;
	int				turn;
	int				match_taken;
	int				input_error;
}					t_alum1;

void				al_print_winer(t_alum1 *al);
void				al_print_board(t_alum1 *al);
void				al_the_game(t_alum1 *al);
int					al_parser(t_alum1 *al, char *file_name);
int					al_stack_push(t_stack **stk, int n);
void				al_stack_pop(t_stack **stk);
void				al_stack_revers(t_stack **stk);
void				al_init(t_alum1 *al);
void				al_free(t_alum1 *al);

#endif
