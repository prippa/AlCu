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

static int	al_bonus_flags(t_alum1 *al, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-turn"))
			al->turn = 1;
		// else if (!ft_strcmp(argv[i], "-c"))
		// 	ps->vis.flag_col = 1;
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
	if (al_parser(&al, argv[skip_bonus_flags]) == -1)
	{
		ft_dprintf(2, "%~s\n", F_RED, "ERROR");
		al_free(&al);
		system("leaks alum1");
		return (-1);
	}
	al_the_game(&al);
	system("leaks alum1");
	al_free(&al);
	return (0);
}
