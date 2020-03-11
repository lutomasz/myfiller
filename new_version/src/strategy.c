/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutomasz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:01:04 by lutomasz          #+#    #+#             */
/*   Updated: 2020/01/07 20:01:05 by lutomasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		place_piece3(t_struct *u, int cheat, int **sol)
{
	if (u->ret != 0 && !cheat)
	{
		u->bst_i = find_best_sol(u, sol);
		if (u->bst_i == u->piece.total)
		{
			if (!other_place(u))
			{
				ft_putnbr(0);
				ft_putchar(' ');
				ft_putnbr(0);
				ft_putchar('\n');
				free_double_int(sol, u->piece.total);
				return (0);
			}
			free_double_int(sol, u->piece.total);
			return (1);
		}
		u->sol_x = u->trimmed_pos[u->best_pos][0] - u->piece.coord[u->bst_i][0];
		u->sol_y = u->trimmed_pos[u->best_pos][1] - u->piece.coord[u->bst_i][1];
	}
	free_double_int(sol, u->piece.total);
	return (1);
}

int		place_piece2(t_struct *u, int **sol)
{
	int cheat;

	cheat = 0;
	if (u->ret == 0 || (u->trimmed_pos[u->best_pos][0]
		- u->piece.coord[u->bst_i][0] <= 0 && u->trimmed_pos[u->best_pos][1]
		- u->piece.coord[u->bst_i][1] <= 0))
	{
		cheat = 1;
		if (!other_place(u))
		{
			ft_putnbr(0);
			ft_putchar(' ');
			ft_putnbr(0);
			ft_putchar('\n');
			free_double_int(sol, u->piece.total);
			return (0);
		}
	}
	return (place_piece3(u, cheat, sol));
}

int		place_piece(t_struct *u, int *is_opp_enclosed)
{
	int **solutions;

	solutions = NULL;
	if (!(solutions = malloc_2d_int_arr(solutions, u->piece.total, 2)))
		return (0);
	u->i = -1;
	while (++u->i < u->piece.total)
	{
		solutions[u->i][0] = 0;
		solutions[u->i][1] = 0;
	}
	if (is_not_enclosed(u, is_opp_enclosed))
	{
		if ((u->ret = place_all_poss(u, solutions)) == 0)
		{
			u->best_pos = 0;
			while (u->ret == 0 && u->best_pos < u->num_me)
			{
				u->ret = place_all_poss(u, solutions);
				u->best_pos++;
			}
			u->best_pos--;
		}
	}
	return (place_piece2(u, solutions));
}
