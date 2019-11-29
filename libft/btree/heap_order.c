/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:03:55 by amartino          #+#    #+#             */
/*   Updated: 2019/11/29 12:18:28 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void 	is_parent_valid(t_heap *heap, size_t child)
{
	size_t		parent;

	parent = get_parent(child);
	if ((heap->type == MIN_HEAP && heap->A[parent] > heap->A[child]) == TRUE
		|| (heap->type == MAX_HEAP && heap->A[parent] < heap->A[child]) == TRUE)
	{
		swap(heap, parent, child);
		is_parent_valid(heap, parent);
	}
}

void	heapify(t_heap *heap, size_t parent)
{
	size_t		l;
	size_t		r;
	size_t		extremum;

	l = get_left_child(parent);
	r = get_right_child(parent);
	extremum = parent;
	if ((int32_t)l > heap->A[HEAP_SIZE] || (int32_t)r > heap->A[HEAP_SIZE])
		return ;
	if (heap->type == MIN_HEAP)
	{
		extremum = heap->A[extremum] > heap->A[l] ? l : extremum;
		extremum = heap->A[extremum] > heap->A[r] ? r : extremum;
	}
	else if (heap->type == MAX_HEAP)
	{
		extremum = heap->A[extremum] < heap->A[l] ? l : extremum;
		extremum = heap->A[extremum] < heap->A[r] ? r : extremum;
	}
	if (extremum != parent)
	{
		swap(heap, parent, extremum);
		heapify(heap, extremum);
	}
}
