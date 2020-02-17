/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutomasz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:01:28 by lutomasz          #+#    #+#             */
/*   Updated: 2020/01/07 20:01:29 by lutomasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_me_his(t_struct *u)
{
	u->my_c[0] = (u->player1) ? 'o' : 'x';
	u->my_c[1] = (u->player1) ? 'O' : 'X';
	u->his_c[0] = (u->player1) ? 'x' : 'o';
	u->his_c[1] = (u->player1) ? 'X' : 'O';
}

void	set_players_pos(t_struct *u)
{
	if (!u->player1)
	{
		u->first_en.x = u->first_o.x;
		u->first_en.y = u->first_o.y;
		u->last_played_en.x = u->last_played_o.x;
		u->last_played_en.y = u->last_played_o.y;
	}
	else
	{
		u->first_en.x = u->first_x.x;
		u->first_en.y = u->first_x.y;
		u->last_played_en.x = u->last_played_x.x;
		u->last_played_en.y = u->last_played_x.y;
	}
}

int		is_enemy(t_struct *u, char c)
{
	if (c == u->his_c[0] || c == u->his_c[1])
		return (1);
	return (0);
}

int		is_me(t_struct *u, char c)
{
	if (c == u->my_c[0] || c == u->my_c[1])
		return (1);
	return (0);
}

int		no_dots(t_struct *u)
{
	int i;
	int j;

	i = -1;
	while (++i < u->map_h)
	{
		j = -1;
		while (++j < u->map_w)
		{
			if (u->map[i][j] == '.')
				return (0);
		}
	}
	return (1);
}
