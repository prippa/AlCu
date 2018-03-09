#include "alum1.h"

void	al_match_taken(t_alum1 *al)
{
	al->stk->n -= al->match_taken;
	if (!al->stk->n)
		al_stack_pop(&al->stk);
}

int		al_game_over(t_alum1 *al)
{
	if (!al->stk || (!al->stk->next && al->stk->n < 2))
		return (1);
	return (0);
}

int		al_get_valid_matches(t_stack *stk)
{
	if (stk->n == 1)
		return (1);
	else
		return (stk->n >= 3 ? 3 : 2);
}
