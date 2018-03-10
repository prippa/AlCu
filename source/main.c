/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:09:43 by prippa            #+#    #+#             */
/*   Updated: 2018/03/09 13:09:45 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	al_init_player_vs_ai(t_alum1 *al)
{
	if (!(al->pl.player_1 = ft_strdup("Player")))
		return (-1);
	if (!(al->pl.player_2 = ft_strdup("AI")))
		return (-1);
	return (1);
}

static int	al_init_players(t_alum1 *al)
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

static int	al_bonus_flags(t_alum1 *al, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-turn"))
			al->turn = 1;
		else if (!ft_strcmp(argv[i], "-players"))
			al->pl.flag_players = 1;
		else if (!ft_strcmp(argv[i], "-taken"))
			al->pl.flag_taken = 1;
		else
			break ;
		i++;
	}
	return (i);
}

static int	al_print_error_free(t_alum1 *al)
{
	ft_dprintf(2, "%~s\n", F_RED, "ERROR");
	al_free(al);
	system("leaks -quiet alum1");
	return (-1);
}

int			main(int argc, char **argv)
{
	t_alum1	al;
	int		skip_bonus_flags;

	al_init(&al);
	skip_bonus_flags = al_bonus_flags(&al, argv);
	if (al_parser(&al, argv[skip_bonus_flags]) == -1)
		return (al_print_error_free(&al));
	if (al.pl.flag_players)
	{
		if (al_init_players(&al) == -1)
			return (al_print_error_free(&al));
	}
	else if (al_init_player_vs_ai(&al) == -1)
		return (al_print_error_free(&al));
	if (al_pl_join_color(&al) == -1)
		return (al_print_error_free(&al));
	if (al_the_game(&al) == -1)
		return (al_print_error_free(&al));
	al_free(&al);
	system("leaks -quiet alum1");
	return (0);
}
