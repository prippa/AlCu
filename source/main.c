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

static void	al_print_help(void)
{
	ft_printf("flag: \"%~s\" - the Player 2 goes first. \
In standart Player 1 always goes first.\n", F_BOLD_WHITE, "-t");
	ft_printf("flag: \"%~s\" - (Player VS Player) mode\n",
		F_BOLD_WHITE, "-players");
	ft_printf("flag: \"%~s\" - Print at the end of \
game total turn sum\n", F_BOLD_WHITE, "-turns");
	ft_printf("flag: \"%~s\" - Print at the end of \
game taken (n) matches of the Player 1 and Player 2\n", F_BOLD_WHITE, "-taken");
}

static int	al_exit_free(t_alum1 *al)
{
	al_free(al);
	return (0);
}

static int	al_exit_error_free(t_alum1 *al)
{
	ft_dprintf(2, "%~s\n", F_BOLD_RED, "ERROR");
	al_free(al);
	return (-1);
}

static int	al_bonus_flags(t_alum1 *al, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-t"))
			al->turn = 1;
		else if (!ft_strcmp(argv[i], "-players"))
			al->pl.flag_players = 1;
		else if (!ft_strcmp(argv[i], "-taken"))
			al->pl.flag_taken = 1;
		else if (!ft_strcmp(argv[i], "-turns"))
			al->pl.flag_turns = 1;
		else if (!ft_strcmp(argv[i], "-help"))
		{
			al_print_help();
			return (0);
		}
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

	argc = 42;
	al_init(&al);
	if (!(skip_bonus_flags = al_bonus_flags(&al, argv)))
		return (al_exit_free(&al));
	if (al_parser(&al, argv[skip_bonus_flags]) == -1)
		return (al_exit_error_free(&al));
	if (al.pl.flag_players)
	{
		if (al_init_players(&al) == -1)
			return (al_exit_error_free(&al));
	}
	else if (al_init_player_vs_ai(&al) == -1)
		return (al_exit_error_free(&al));
	if (al_pl_join_color(&al) == -1)
		return (al_exit_error_free(&al));
	if (al_the_game(&al) == -1)
		return (al_exit_error_free(&al));
	al_free(&al);
	return (0);
}
