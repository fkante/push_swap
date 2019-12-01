/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:17:18 by amartino          #+#    #+#             */
/*   Updated: 2019/12/01 14:17:18 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdio.h>

void	print_heap_tree(t_heap *heap, size_t index, size_t deep)
{
	size_t		space;

	space = NB_OF_SPACE * deep;
	if ((int32_t)index > heap->A[HEAP_SIZE])
		return ;

	print_heap_tree(heap, get_right_child(index), deep + 1);

	// printf("\n");
    for (size_t i = 0; i < space; i++)
        printf(" ");
    printf("%d\n", heap->A[index]);

	print_heap_tree(heap, get_left_child(index), deep + 1);
}
