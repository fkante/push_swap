/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/01/21 19:41:08 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int32_t		find_pivot(t_stack *s, int8_t wrong_name)
{
	int32_t		pivot_pos;
	int32_t		pivot;

	pivot_pos = SUBLIST_SIZE * ft_pow_positive(2, (s->exponent + wrong_name));
	pivot = s->sorted_s[pivot_pos - 1];
	return (pivot);
}

void		sort_sublist_on_b(t_stack *s)
{
	size_t		size;

	size = s->size_b;
	while (s->size_b > 0)
		pa_highest(s, s->size_b);
	while (size > 0)
	{
		ra(s);
		size--;
	}
}

void		push_next_sublist_on_b(t_stack *s)
{
	size_t		size;

	size = SUBLIST_SIZE;
	while (size > 0)
	{
		pb(s);
		size--;
	}
}

void 		sort_sublist(t_stack *s)
{
	sort_sublist_on_b(s);
	push_next_sublist_on_b(s);
	pause_and_show(s);
	sort_sublist_on_b(s);
}


void		organize_in_unsorted_sublist(t_stack *s, int8_t wrong_name)
{
	int32_t pivot_index;
	int32_t pivot;
	int32_t pos;

	if ((wrong_name * -1) > s->exponent)
		wrong_name = -1 * s->exponent;
	pos = SUBLIST_SIZE * (int32_t)ft_pow_positive(2, (s->exponent + wrong_name));
	pivot_index = ft_get_n_highest(s->b, pos, s->size_b);
	pivot = s->b[pivot_index];
	ft_printf("pivot is %d\npos is: %d\ndegré de profondeur %d\nexponent max %d\n", pivot, pos, wrong_name, s->exponent);
	pa_all_above_nb(s, pivot);
	pause_and_show(s);
	if (s->size_b > SUBLIST_SIZE)
	{
		wrong_name--;
		organize_in_unsorted_sublist(s, wrong_name);
	}
}

void		solve(t_stack *s)
{
	int32_t		pivot;

	pivot = find_pivot(s, -1);
	pause_and_show(s);
	pb_all_under_nb(s, pivot);
	pause_and_show(s);
	organize_in_unsorted_sublist(s, -2);
	pause_and_show(s);
	sort_sublist(s);
	pause_and_show(s);
}

void		push_swp(t_stack *s, int ac, char **av)
{
	t_stat		*stat;

	stat = NULL;
	s = init_struct(av, ac);
	if (s == NULL)
		return ;
	stat = get_stat(s);
	mkdir("result", 0700);
	s->fd = open("result/tmp.txt", O_RDWR | O_CREAT, 0744);
	if (s->fd == FAILURE)
	{
		clean_struct(&s);
		return (ft_print_err_void("when creating result file", STD_ERR));
	}
	solve(s);
	if (s->verbose == TRUE)
		print_stack(s, NO_OPE, 0);
	save_final_result_in_file(s);
	clean_struct(&s);
	ft_memdel((void**)&stat);
}
