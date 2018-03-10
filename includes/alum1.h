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

typedef	struct		s_players
{
	char			*player_1;
	char			*player_2;
	int				flag_players;
	int				flag_taken;
	int				taken_player_1;
	int				taken_player_2;
}					t_players;

typedef	struct		s_alum1
{
	t_stack			*stk;
	char			*buf;
	int				turn;
	int				match_taken;
	int				input_error;
	t_players		pl;
}					t_alum1;

void				al_pl_size_up_taken(t_alum1 *al);
int					al_pl_join_color(t_alum1 *al);
int					al_print_and_get_player_info(t_alum1 *al);
int					al_ai_logic(t_alum1 *al);
void				al_print_winer(t_alum1 *al);
void				al_print_board(t_alum1 *al);
int					al_the_game(t_alum1 *al);
void				al_match_taken(t_alum1 *al);
int					al_get_valid_matches(t_stack *stk);
int					al_game_over(t_alum1 *al);
int					al_parser(t_alum1 *al, char *file_name);
int					al_stack_push(t_stack **stk, int n);
void				al_stack_pop(t_stack **stk);
void				al_stack_revers(t_stack **stk);
void				al_init(t_alum1 *al);
void				al_free(t_alum1 *al);

#endif
