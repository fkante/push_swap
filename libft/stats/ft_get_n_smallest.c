/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_n_smallest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:01:16 by fkante            #+#    #+#             */
/*   Updated: 2020/02/24 11:41:05 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

ssize_t		ft_get_n_smallest(int32_t *tab, size_t nth, size_t start,
								size_t limit)
{
	t_heap	*heap;
	size_t	i;

	i = start;
	heap = heap_tree((tab + start), limit, MIN_HEAP);
	if (heap == NULL || nth == 0)
		return (FAILURE);
	while (nth > 1)
	{
		delete_root(heap);
		nth--;
	}
	while (i < (limit + start))
	{
		if (tab[i] == heap->A[ROOT])
			break ;
		i++;
	}
	clean_heap_tree(&heap);
	return (i);
}
