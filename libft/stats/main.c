/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:41:48 by amartino          #+#    #+#             */
/*   Updated: 2019/11/26 19:40:27 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

# define HEAP_SIZE		0
# define NB_OF_SPACE	10
# define MAX_HEAP		0
# define MIN_HEAP		1
# define ROOT			1

typedef struct			s_heap
{
	int32_t			*A;
	uint8_t			type;
}						t_heap;

size_t	deepness(int32_t *tab, size_t max)
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

void	print_tree(t_heap *heap, size_t index, size_t deep)
{
	size_t		space;

	space = NB_OF_SPACE * deep;
	if (index > heap->A[HEAP_SIZE])
		return ;

	print_tree(heap, get_right_child(index), deep + 1);

	printf("\n");
    for (int i = 0; i < space; i++)
        printf(" ");
    printf("%d\n", heap->A[index]);

	print_tree(heap, get_left_child(index), deep + 1);
}

t_heap	*init_tree(int32_t *tab, size_t size, uint8_t type)
{
	t_heap		*heap;

	heap = ft_memalloc(sizeof(heap));
	if (heap != NULL)
		heap->A = ft_memalloc(sizeof(int32_t) * (size + 1));
	if (heap == NULL || heap->A == NULL)
		ft_memdel((void**)&heap);
	else
	{
		heap->type = type;
		heap->A[HEAP_SIZE] = 0;
	}
	return (heap);
}

void	swap(t_heap *heap, size_t parent, size_t child)
{
	int32_t		tmp;

	tmp = heap->A[parent];
	heap->A[parent] = heap->A[child];
	heap->A[child] = tmp;
}

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

void	insert(t_heap *heap, int32_t nb, size_t index)
{
	heap->A[index] = nb;
	heap->A[HEAP_SIZE]++;
	is_parent_valid(heap, index);
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

void	fill_tree(t_heap *heap, int32_t *tab, size_t size)
{
	size_t		i;
	size_t		parent_index;

	i = 1;
	parent_index = 1;
	heap->A[1] = tab[0];
	heap->A[HEAP_SIZE]++;;
	while (i < size)
	{
		insert(heap, tab[i], get_left_child(parent_index));
		i++;
		if (i < size)
			insert(heap, tab[i], get_right_child(parent_index));
		i++;
		parent_index++;
	}
}

int		main()
{
	t_heap		*heap;
	int32_t		base[14] = {1, 32, -7, 40, 5, 9, 8, 0, -20, 15, 22, -12, -2, 2};
	int32_t		over_half;

	over_half = (14 / 2) + 1;
	heap = init_tree(base, 14, MIN_HEAP);
	if (heap == NULL)
		return (0);
	fill_tree(heap, base, over_half);
	while (over_half < 14)
	{
		if (base[over_half] > heap->A[ROOT])
		{
			heap->A[ROOT] = base[over_half];
			heapify(heap, ROOT);
		}
		over_half++;
	}
	print_tree(heap, 1, 0);
	return (0);
}
