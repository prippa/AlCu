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

void		al_print_stack(t_stack *stk)
{
	while (stk)
	{
		ft_printf("%d\n", stk->n);
		stk = stk->next;
	}
}

// static int	al_init_players(t_alum1 *al)
// {
// 	ft_clear();
// 	ft_putstr("\tPlayers initialization mode\n\n");
// 	ft_putstr("Write name of the Player 1\n->");
// 	ft_str_free(&al->buf);
// 	if ((get_next_line(0, &al->buf)) == -1)
// 		return (-1);
// 	if (!(al->pl.player_1 = ft_strdup(al->buf)))
// 		return (-1);
// 	ft_str_free(&al->buf);
// 	ft_putstr("Write name of the Player 2\n->");
// 	if ((get_next_line(0, &al->buf)) == -1)
// 		return (-1);
// 	if (!(al->pl.player_2 = ft_strdup(al->buf)))
// 		return (-1);
// 	return (1);
// }

static int	al_bonus_flags(t_alum1 *al, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-turn"))
			al->turn = 1;
		// else if (!ft_strcmp(argv[i], "-players"))
		// 	al->pl.flag_players = 1;
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

	skip_bonus_flags = al_bonus_flags(&al, argv);
	printf("%s\n", "1");
	if (al_parser(&al, argv[skip_bonus_flags]) == -1)
	{
		printf("%s\n", "2");
		ft_dprintf(2, "%~s\n", F_RED, "ERROR");
		al_free(&al);
		system("leaks alum1");
		return (-1);
	}
	printf("%s\n", "3");
	// if (al.pl.flag_players && al_init_players(&al) == -1)
	// 	return (-1);
	al_the_game(&al);
	//ft_printf("%s\n%s\n", al.pl.player_1, al.pl.player_2);
	al_free(&al);
	system("leaks alum1");
	return (0);
}
