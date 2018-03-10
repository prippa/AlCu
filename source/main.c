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
	ft_printf("Write name of the %~s\n->", F_GREEN, "Player 2");
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
		// else if (!ft_strcmp(argv[i], "-d"))
		// 	ps->vis.flag_debug = 1;
		// else if (!ft_strcmp(argv[i], "-s"))
		// 	ps->vis.flag_size = 1;
		// else if (!ft_strcmp(argv[i], "-h"))
		// 	ps->vis.flag_history = 1;
		else
			break ;
		i++;
	}
	return (i);
}

int			main(int argc, char **argv)
{
	t_alum1	al;
	int		skip_bonus_flags;

	al_init(&al);
	skip_bonus_flags = al_bonus_flags(&al, argv);
	if (al_parser(&al, argv[skip_bonus_flags]) == -1)
	{
		ft_dprintf(2, "%~s\n", F_RED, "ERROR");
		al_free(&al);
		system("leaks alum1");
		return (-1);
	}
	if (al.pl.flag_players && al_init_players(&al) == -1)
		return (-1);
	al_the_game(&al);
	al_free(&al);
	system("leaks alum1");
	return (0);
}
