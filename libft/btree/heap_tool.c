/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:52:13 by amartino          #+#    #+#             */
/*   Updated: 2020/02/26 17:06:24 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

size_t	deepness(size_t max)
{
	size_t	deep;

	deep = 0;
	while (max != 0)
	{
		max = max / 2;
		deep++;
	}
	return (deep);
}

void	swap(t_heap *heap, size_t parent, size_t child)
{
	int32_t		tmp;

	tmp = heap->a[parent];
	heap->a[parent] = heap->a[child];
	heap->a[child] = tmp;
}

size_t	get_parent(size_t index)
{
	return (index == 1 ? 1 : index / 2);
}

size_t	get_left_child(size_t index)
{
	return (index * 2);
}

size_t	get_right_child(size_t index)
{
	return ((index * 2) + 1);
}
