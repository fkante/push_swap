/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_n_highest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:49:09 by amartino          #+#    #+#             */
/*   Updated: 2019/12/01 14:44:21 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

ssize_t		ft_get_n_highest(int32_t *tab, size_t nth, size_t size)
{
	t_heap	*heap;
	size_t	i;

	i = 0;
	heap = heap_tree(tab, size, MIN_HEAP);
	if (heap == NULL)
		return (FAILURE);
	print_heap_tree(heap, 1, 0);
	nth--;
	while (nth > 0)
	{
		delete_root(heap);
		nth--;
	}
	while (i < size)
	{
		if (tab[i] == heap->A[ROOT])
			break ;
		i++;
	}
	return (i);
}
