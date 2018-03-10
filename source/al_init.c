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

void	pl_init(t_players *pl)
{
	pl->player_1 = NULL;
	pl->player_2 = NULL;
	pl->flag_players = 0;
}

void	al_init(t_alum1 *al)
{
	al->stk = NULL;
	al->buf = NULL;
	al->turn = 0;
	al->match_taken = 0;
	pl_init(&al->pl);
}
