/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_2d_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutomasz <lutomasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:28:52 by lutomasz            #+#    #+#           */
/*   Updated: 2019/12/01 18:41:07 by lutomasz           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**malloc_2d_int_arr(int **arr, int size_i, int size_j)
{
	int		iter;

	arr = (int**)malloc(sizeof(int*) * size_i);
	iter = -1;
	while (++iter < size_i)
		arr[iter] = (int*)malloc(sizeof(int) * size_j);
	return (arr);
}
