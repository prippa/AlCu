/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:13:45 by prippa            #+#    #+#             */
/*   Updated: 2018/03/09 16:13:47 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int			al_pl_join_color(t_alum1 *al)
{
	ft_str_free(&al->buf);
	al->buf = ft_strjoin(BOLD_GREEN, al->pl.player_1);
	ft_str_free(&al->pl.player_1);
	if (!(al->pl.player_1 = ft_strdup(al->buf)))
		return (-1);
	ft_str_free(&al->buf);
	al->buf = ft_strjoin(al->pl.player_1, COLOR_RESET);
	ft_str_free(&al->pl.player_1);
	if (!(al->pl.player_1 = ft_strdup(al->buf)))
		return (-1);
	ft_str_free(&al->buf);
	al->buf = ft_strjoin(BOLD_CYAN, al->pl.player_2);
	ft_str_free(&al->pl.player_2);
	if (!(al->pl.player_2 = ft_strdup(al->buf)))
		return (-1);
	ft_str_free(&al->buf);
	al->buf = ft_strjoin(al->pl.player_2, COLOR_RESET);
	ft_str_free(&al->pl.player_2);
	if (!(al->pl.player_2 = ft_strdup(al->buf)))
		return (-1);
	return (1);
}

int			al_print_and_get_player_info(t_alum1 *al)
{
	int				take;
	long long int	input_take;

	take = al_get_valid_matches(al->stk);
	if (al->match_taken > 0)
		ft_printf("%s took %d matches\n",
			(!al->turn ? al->pl.player_2 : al->pl.player_1), al->match_taken);
	ft_printf("%s take 1 - %d matches\n",
		(al->turn ? al->pl.player_2 : al->pl.player_1), take);
	ft_printf("%~s", F_BOLD_WHITE, "->");
	ft_str_free(&al->buf);
	if ((get_next_line(0, &al->buf)) == -1)
		return (-1);
	if (!ft_isstrdigit(al->buf))
		return (0);
	input_take = ft_atoi_max(al->buf);
	if (input_take > take || input_take < 1)
		return (0);
	return ((int)input_take);
}

void		al_print_winer(t_alum1 *al)
{
	if ((al->turn && al->stk) || (!al->turn && !al->stk))
		ft_printf("\n\tThe %s WON!\n", al->pl.player_1);
	else
		ft_printf("\n\tThe %s WON!\n", al->pl.player_2);
	if (al->pl.flag_taken)
	{
		ft_printf("The %s took - (%~d) matches\n",
			al->pl.player_1, F_BOLD_YELLOW, al->pl.taken_player_1);
		ft_printf("The %s took - (%~d) matches\n",
			al->pl.player_2, F_BOLD_YELLOW, al->pl.taken_player_2);
	}
}

static int	al_get_max_n(t_stack *stk)
{
	int max;

	max = stk->n;
	stk = stk->next;
	while (stk)
	{
		if (max < stk->n)
			max = stk->n;
		stk = stk->next;
	}
	return (max);
}

void		al_print_board(t_alum1 *al)
{
	t_stack	*tmp;
	int		max;
	int		width;

	ft_clear();
	al_stack_revers(&al->stk);
	tmp = al->stk;
	max = al_get_max_n(tmp);
	while (tmp)
	{
		ft_str_free(&al->buf);
		al->buf = ft_strnew(tmp->n);
		al->buf = ft_memset(al->buf, '|', tmp->n);
		width = ((tmp->n + max) / 2) + (ft_nbrlen(max) - ft_nbrlen(tmp->n));
		ft_printf("%d) %s%*s%s\n", tmp->n, BOLD_YELLOW, width, al->buf, COLOR_RESET);
		tmp = tmp->next;
	}
	ft_putchar('\n');
	al_stack_revers(&al->stk);
}
