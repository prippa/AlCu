/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:58:52 by prippa            #+#    #+#             */
/*   Updated: 2018/03/09 14:58:53 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int			al_init_players(t_alum1 *al)
{
	ft_clear();
	ft_putstr("\tPlayers initialization mode\n\n");
	ft_printf("Write name of the %~s\n->", F_GREEN, "Player 1");
	ft_str_free(&al->buf);
	if ((get_next_line(0, &al->buf)) == -1)
		return (-1);
	if (!(al->pl.player_1 = ft_strdup(al->buf)))
		return (-1);
	ft_str_free(&al->buf);
	ft_printf("Write name of the %~s\n->", F_MAGENTA, "Player 2");
	if ((get_next_line(0, &al->buf)) == -1)
		return (-1);
	if (!(al->pl.player_2 = ft_strdup(al->buf)))
		return (-1);
	return (1);
}

int			al_init_player_vs_ai(t_alum1 *al)
{
	if (!(al->pl.player_1 = ft_strdup("Player")))
		return (-1);
	if (!(al->pl.player_2 = ft_strdup("AI")))
		return (-1);
	return (1);
}

static void	pl_init(t_players *pl)
{
	pl->player_1 = NULL;
	pl->player_2 = NULL;
	pl->flag_players = 0;
	pl->flag_taken = 0;
	pl->taken_player_1 = 0;
	pl->taken_player_2 = 0;
}

void		al_init(t_alum1 *al)
{
	al->stk = NULL;
	al->buf = NULL;
	al->turn = 0;
	al->match_taken = 0;
	pl_init(&al->pl);
}
