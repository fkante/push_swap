/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/02/06 17:32:31 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_subdiv_above_pivot(t_stack *s, int32_t pivot, size_t limit)
{
	while (limit > 0)
	{
		pb_one_above_nb(s, pivot);
		limit--;
	}
}

void	pb_under_pivot_unsorted(t_stack *s, int32_t pivot)
{
	pb_all_under_nb(s, pivot);
}

void	insertion_sort_style(t_stack *s)
{
	t_stat	*stat;
	size_t	pivot;

	pivot = 0;
	while (s->size_a > 1)
	{
		stat = get_stat(s);
		pivot = ft_get_n_smallest(s->a, s->size_a/2, 0, s->size_a);
		pb_under_pivot_unsorted(s, pivot);
		ft_memdel((void**)&stat);
	}
	while (s->size_b > 0)
		pa_highest(s, s->size_b);
}

void	solve(t_stack *s)
{
	insertion_sort_style(s);
}

void	push_swp(t_stack *s, int ac, char **av)
{
	s = init_struct(av, ac);
	if (s == NULL)
		return ;
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
}
