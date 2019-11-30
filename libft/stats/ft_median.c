/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:01:11 by amartino          #+#    #+#             */
/*   Updated: 2019/11/30 15:48:06 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
// #include <stdio.h>

int8_t		ft_median(int32_t *tab, size_t size, int32_t *median)
{
	t_heap		*heap;
	int32_t		over_half;

	over_half = (size / 2) + 1;
	heap = heap_tree(tab, over_half, MIN_HEAP);
	if (heap == NULL)
		return (FAILURE);
	while (over_half < size)
	{
		if (tab[over_half] > heap->A[ROOT])
		{
			// printf("nb is %d\n", tab[over_half]);
			// print_heap_tree(heap, 1, 0);
			// printf("\n_____________________________\n");
			heap->A[ROOT] = tab[over_half];
			heapify(heap, ROOT);
		}
		over_half++;
	}
	return (heap->A[ROOT]);
}

// int main()
// {
// 	int32_t		base[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
// 	int32_t		over_half;
// 	int32_t		median;
//
// 	printf("median is %d\n", ft_median(base, 11, &median));
// 	return (0);
// }
