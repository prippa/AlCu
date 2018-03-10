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

static int	al_player_vs_player_mode(t_alum1 *al)
{
	int status;

	if ((status = al_print_and_get_player_info(al)) == -1)
		return (-1);
	return (status);
}

static int	al_ai_vs_player_mode(t_alum1 *al)
{
	int status;

	status = 0;
	if (!al->turn)
	{
		if ((status = al_print_and_get_player_info(al)) == -1)
			return (-1);
	}
	else
		al->match_taken = al_ai_logic(al);
	return (status);
}

static int	al_turn(t_alum1 *al)
{
	if (al->pl.flag_players)
		return (al_player_vs_player_mode(al));
	else
		return (al_ai_vs_player_mode(al));
}

static void	al_end_game_stage(t_alum1 *al)
{
	if (al->match_taken > 0 && !al->pl.flag_players && !al->turn)
		ft_printf("%s took %d matches\n",
			(!al->turn ? al->pl.player_2 : al->pl.player_1), al->match_taken);
	al_print_winer(al);
}

int			al_the_game(t_alum1 *al)
{
	while (42)
	{
		al_print_board(al);
		if (al->input_error)
			ft_printf("%~s: Invalid matches input. Try again!\n",
				F_BOLD_MAGENTA, "Warning");
		al->input_error = al_turn(al);
		if (al->input_error == 1)
			continue ;
		else if (al->input_error == -1)
			return (-1);
		if (al->pl.flag_taken)
			al_pl_size_up_taken(al);
		al_match_taken(al);
		al->turn = (al->turn ? 0 : 1);
		if (al_game_over(al))
			break ;
	}
	al_end_game_stage(al);
	return (1);
}
