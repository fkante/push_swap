/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/01/21 14:00:26 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_sublist_on_b(t_stack *s)
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

void	push_next_sublist_on_b(t_stack *s)
{
	size_t		size;

	size = SUBLIST_SIZE;
	while (size > 0)
	{
		pb(s);
		size--;
	}
}

void 	sort_all_sublist(t_stack *s, int32_t pivot)
{
	if (s->size_b > 0)
		sort_sublist_on_b(s);
	else
		push_next_sublist_on_b(s);
	if (s->a[s->size_a - 1] != pivot)
		sort_all_sublist(s, pivot);
	if (s->size_b > 0)
		sort_sublist_on_b(s);
}


void 	organize_in_unsorted_sublist(t_stack *s)
{
	int32_t		median;

	if (ft_median(s->b, s->size_b, &median) == FAILURE)
		return ;
	pa_all_above_nb(s, median);
	if (s->size_b > SUBLIST_SIZE)
		organize_in_unsorted_sublist(s);
}

void	solve(t_stack *s)
{
	int32_t		median;

	if (ft_median(s->a, s->size_a, &median) == FAILURE)
		return ;
	pause_and_show(s);
	pb_all_under_nb(s, median);
	pause_and_show(s);
	pivot_on_top_a(s, median);
	pause_and_show(s);
	organize_in_unsorted_sublist(s);
	pause_and_show(s);
	sort_all_sublist(s, median);
	pause_and_show(s);
	ra(s);
	pause_and_show(s);
}

void	push_swp(t_stack *s, int ac, char **av)
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

// organize_in_unsorted_sublist
