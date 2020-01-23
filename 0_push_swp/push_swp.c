/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/01/23 22:01:05 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int8_t		organize_stack_b_in_unsorted_sublist(t_stack *s)
{
	int32_t 	pivot;
	int32_t 	pivot_index;
	int8_t		ret;

	ret = SUCCESS;
	pivot_index = ft_get_n_highest(s->b, (s->size_b / 2), 0, s->size_b);
	if (pivot_index == FAILURE)
		return (ft_print_err_failure("malloc, finding pivot index", STD_ERR));
	pivot = s->b[pivot_index];
	// ft_printf("pivot index %zu\t pivot is %d\n", pivot_index, pivot);
	pa_above_pivot(s, pivot, s->size_b);
	if (s->size_b > SUBLIST_MIN_SIZE)
		ret = organize_stack_b_in_unsorted_sublist(s);
	return (ret);
}

void 		split_stack_in_2_big_part(t_stack *s)
{
	size_t		sublist_size;
	int32_t		pivot;

	sublist_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, (s->exponent_max - 1));
	ft_printf("sublist size is %zu\n", sublist_size);
	pivot = s->sorted_s[sublist_size - 1];
	pb_under_pivot(s, pivot, s->size_a);
}

int8_t		sort_stack_b(t_stack *s, size_t exponent)
{
	size_t		sublist_size;
	int8_t		ret;

	ret = SUCCESS;
	sublist_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, exponent);
	// pause_and_show(s);
	push_next_sublist_on_b(s, sublist_size);
	// pause_and_show(s);
	ret = organize_stack_b_in_unsorted_sublist(s);
	if (ret == FAILURE)
		return (FAILURE);
	sort_min_size_sublist_available(s);
	// pause_and_show(s);
	if (exponent < (s->exponent_max - 2))
	{
		exponent++;
		ret = sort_stack_b(s, exponent);
	}
	return (ret);
}

int8_t		pb_second_half(t_stack *s)
{
	size_t		sublist_size;
	size_t		size;
	int32_t 	pivot_index;
	int32_t		pivot;

	sublist_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, (s->exponent_max - 1));
	size = s->size_a - sublist_size;
	pivot_index = ft_get_n_smallest(s->a, sublist_size, sublist_size, size);
	if (pivot_index == FAILURE)
		return (ft_print_err_failure("malloc, finding pivot index", STD_ERR));
	pivot = s->a[pivot_index];
	pb_under_pivot(s, pivot, size);
	rra_the_remainder(s);
	return (SUCCESS);
}

int8_t		let_the_magic_of_recursion_happen(t_stack *s)
{
	int8_t		res;

	res = SUCCESS;
	res = organize_stack_b_in_unsorted_sublist(s);
	if (res == FAILURE)
		return (FAILURE);
	sort_min_size_sublist_available(s);
	sort_stack_b(s, 1);
	return (SUCCESS);
}

void		sort_remainder(t_stack *s)
{
	size_t		remainder_size;
	size_t		largest_sublist;

	largest_sublist = SUBLIST_MIN_SIZE * ft_pow_positive(2, s->exponent_max);
	remainder_size = s->size_a + s->size_b - largest_sublist;
	push_next_sublist_on_b(s, remainder_size);
	sort_sublist_on_b(s);
}

int8_t		solve(t_stack *s)
{
	int8_t		ret;

	split_stack_in_2_big_part(s);
	pause_and_show(s);
	ret = let_the_magic_of_recursion_happen(s);
	// pause_and_show(s);
	if (ret == SUCCESS)
		ret = pb_second_half(s);
	// pause_and_show(s);
	if (ret == SUCCESS)
		ret = let_the_magic_of_recursion_happen(s);
	// pause_and_show(s);
	if (ret == SUCCESS)
		sort_remainder(s);
	// pause_and_show(s);
	return (ret);
}
