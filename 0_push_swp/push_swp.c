/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/01/27 17:48:15 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 		split_stack_in_2_big_part(t_stack *s)
{
	size_t		sublist_size;
	int32_t		pivot;

	sublist_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, (s->exponent_max - 1));
	pivot = s->sorted_s[sublist_size - 1];
	pb_under_pivot(s, pivot, s->size_a);
}

int8_t		organize_stack_b_in_unsorted_sublist(t_stack *s)
{
	int32_t 	pivot;
	int32_t 	pivot_index;
	int8_t		ret;

	ret = SUCCESS;
	if (s->size_b > SUBLIST_MIN_SIZE)
	{
		pivot_index = ft_get_n_highest(s->b, (s->size_b / 2), 0, s->size_b);
		if (pivot_index == FAILURE)
			return (ft_print_err_failure("malloc, finding pivot index", STD_ERR));
		pivot = s->b[pivot_index];
		pa_above_pivot(s, pivot, s->size_b);
		ret = organize_stack_b_in_unsorted_sublist(s);
	}
	return (ret);
}

int8_t		let_the_magic_of_recursion_happen(t_stack *s, size_t exponent, size_t exponent_max)
{
	size_t		sublist_size;
	int8_t		ret;

	ret = SUCCESS;
	sublist_size = SUBLIST_MIN_SIZE * ft_pow_positive(2, exponent);
	push_next_sublist_on_b(s, sublist_size);
	if (exponent > 0)
	{
		ret = organize_stack_b_in_unsorted_sublist(s);
		if (ret == FAILURE)
			return (FAILURE);
		sort_sublist_on_b(s);
		ret = let_the_magic_of_recursion_happen(s, 0, (exponent - 1));
	}
	else
		sort_sublist_on_b(s);
	if (exponent < exponent_max && ret == SUCCESS)
		ret = let_the_magic_of_recursion_happen(s, (exponent + 1), exponent_max);
	return (SUCCESS);
}

int8_t		pb_second_half(t_stack *s);
void		sort_remainder(t_stack *s);

// ft_printf("before magic function first\n");
// ft_printf("after pb second half\n");

int8_t		solve(t_stack *s)
{
	int8_t		ret;

	ret = SUCCESS;
	if (s->exponent_max > 0)
	{
		split_stack_in_2_big_part(s);
		ret = organize_stack_b_in_unsorted_sublist(s);
		sort_sublist_on_b(s);
		if (s->exponent_max > 1 && ret == SUCCESS)
			ret = let_the_magic_of_recursion_happen(s, 0, (s->exponent_max - 2));
		if (ret == SUCCESS)
			ret = pb_second_half(s);
		if (ret == SUCCESS)
			ret = organize_stack_b_in_unsorted_sublist(s);
		sort_sublist_on_b(s);
		if (s->exponent_max > 1 && ret == SUCCESS)
			ret = let_the_magic_of_recursion_happen(s, 0, (s->exponent_max - 2));
	}
	if (ret == SUCCESS)
		sort_remainder(s);
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

void		sort_remainder(t_stack *s)
{
	size_t		remainder_size;
	size_t		largest_sublist;

	ft_printf("s->exponent_max %zu\n", s->exponent_max);
	if (s->exponent_max > 0)
	{
		largest_sublist = SUBLIST_MIN_SIZE * ft_pow_positive(2, s->exponent_max);
		remainder_size = s->size_a + s->size_b - largest_sublist;
	}
	else
		remainder_size = s->size_a + s->size_b;
	push_next_sublist_on_b(s, remainder_size);
	sort_sublist_on_b(s);
}
