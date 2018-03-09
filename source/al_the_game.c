/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_the_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:13:31 by prippa            #+#    #+#             */
/*   Updated: 2018/03/09 16:13:33 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	al_turn(t_alum1 *al)
{
	int				take;
	long long int	input_take;

	if (!al->turn)//Player
	{
		take = al_get_valid_matches(al->stk);
		if (al->match_taken)
			ft_printf("AI taked %d matches\n", al->match_taken);
		ft_printf("Take 1 - %d matches\n->", take);
		ft_str_free(&al->buf);
		get_next_line(0, &al->buf);
		if (!ft_isstrdigit(al->buf))
			return (0);
		input_take = ft_atoi_max(al->buf);
		if (input_take > take || input_take < 1)
			return (0);
	}
	else//AI
		input_take = al_ai_logic(al);
	return ((int)input_take);
}

void		al_the_game(t_alum1 *al)
{
	while (42)
	{
		al_print_board(al);
		if (al->input_error && !(al->input_error = 0))
			ft_printf("%~s Invalid matches input. Try again!\n",
				F_RED, "ERROR:");
		if (!(al->match_taken = al_turn(al)))
		{
			al->input_error = 1;
			continue ;
		}
		al_match_taken(al);
		al->turn = (al->turn ? 0 : 1);
		if (al_game_over(al))
			break ;
	}
	al_print_winer(al);
}
