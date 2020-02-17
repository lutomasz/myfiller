#include "filler.h"

void set_values(t_struct *u)
{
	int i;
	int j;

	i = -1;
	while (u->map[++i])
	{
		j = -1;
		while (u->map[i][++j])
		{
			if (u->map[i][j] == u->my_c[0] || u->map[i][j] == u->my_c[1])
				u->h_map[i][j] = -2;
			if (u->map[i][j] == u->his_c[0] || u->map[i][j] == u->his_c[1])
				u->h_map[i][j] = -1;
		}
	}
}

void update_h_map(t_struct *u, int i, int j, int num)
{
	if (i - 1 >= 0 && u->map[i - 1][j] && u->h_map[i - 1][j] == 0)
		u->h_map[i - 1][j] = num;
	if (i - 1 >= 0 && u->map[i - 1][j - 1] && u->h_map[i - 1][j - 1] == 0)
		u->h_map[i - 1][j - 1] = num;
	if (i - 1 >= 0 && u->map[i - 1][j + 1] && u->h_map[i - 1][j + 1] == 0)
		u->h_map[i - 1][j + 1] = num;

	if (u->map[i][j - 1] && u->h_map[i][j - 1] == 0)
		u->h_map[i][j - 1] = num;
	if (u->map[i][j + 1] && u->h_map[i][j + 1] == 0)
		u->h_map[i][j + 1] = num;

	if (i + 1 < u->map_h && u->map[i + 1][j] && u->h_map[i + 1][j] == 0)
		u->h_map[i + 1][j] = num;
	if (i + 1 < u->map_h && u->map[i + 1][j - 1] && u->h_map[i + 1][j - 1] == 0)
		u->h_map[i + 1][j - 1] = num;
	if (i + 1 < u->map_h && u->map[i + 1][j + 1] && u->h_map[i + 1][j + 1] == 0)
		u->h_map[i + 1][j + 1] = num;
}

void make_heat_map(t_struct *u, int num)
{
	int i;
	int j;
	int check;

	check = 0;
	num++;
	if (num == u->map_h + u->map_w)
		return ;
	i = -1;
	while (u->map[++i] && i < u->map_h)
	{
		j = -1;
		while (u->map[i][++j] && j < u->map_w)
		{
			if (u->h_map[i][j] == num - 1 && ++check)
			{
				update_h_map(u, i, j, num);
			}	
		}
	}
	if (check == 0)
		return ;
	make_heat_map(u, num);
}


int make_first_tour(t_struct *u)
{
	int i;
	int j;
	int check;

	check = 0;
	i = (u->his_c[0] == 'o') ? u->first_o.y : u->first_x.y;
	while (u->map[i])
	{
		j = -1;
		while (u->map[i][++j])
		{
			if (u->map[i][j] == u->his_c[0] || u->map[i][j] == u->his_c[1])
			{
				check++;
				update_h_map(u, i, j, 1);
			}
		}
		i++;
	}
	if (check == 0)
		return (0);
	return (1);
}

void set_others(t_struct *u, int num)
{
	int i;
	int j;

	i = -1;
	while (u->map[++i] && i < u->map_h)
	{
		j = -1;
		while (u->map[i][++j] && j < u->map_w)
		{
			if (u->h_map[i][j] == 0)
				u->h_map[i][j] = num;
		}
	}
}

int h_map(t_struct *u)
{
	set_values(u);
	if (make_first_tour(u) == 0)
		return (0);
	make_heat_map(u, 1);
	set_others(u, 99);
	return (1);
}