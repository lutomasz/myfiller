/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutomasz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 07:05:51 by lutomasz          #+#    #+#             */
/*   Updated: 2020/01/09 07:05:53 by lutomasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "stdio.h"

int		init_parse(t_struct *u, int *i, char *map)
{
	if (init_utils(u, map) == -1)
		return (-1);
	if ((ft_get_size_map(u, i)) == -1)
		return (-1);
	//printf("ok\n");
	if (get_map(u) == 0)
		return (-1);
	if (!(get_piece(u)))
		return (-1);
	return (1);
}

/*
** main with infinite loop
*/

int		main2(t_struct *u, int *is_opp_enclosed, int *i, char *argv)
{
	if (init_parse(u, i, argv) == -1)
		return (-1);
	set_me_his(u);
	set_players_pos(u);
	*is_opp_enclosed = h_map(u);
	printf("%d\n", *is_opp_enclosed);
	return (1);
}

int		main(int argc, char **argv)
{
	t_struct	u;
	static int	i;
	int			is_opp_enclosed;

	argc = 0;
	i = 0;
	is_opp_enclosed = 0;
	u.map_h = 0;
	// while (1)
	// {
	main2(&u, &is_opp_enclosed, &i, argv[1]);
	//printf("%s\n", u.map[0]);

	print_int2(u.h_map, u.map_w, u.map_h);
	ft_print_tab2(u.map);
	// 	if (ret != 1)
	// 		break ;
	// }
	// free_all(&u, 0);
	// if (u.h_map != 0)
	// 	free_double_int(u.h_map, u.map_h);
	return (0);
}