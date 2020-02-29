/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/02/27 13:11:38 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	second_step_recursive(t_stack *s, ssize_t total_size)
{
	ssize_t	nb_sent_to_a;

	nb_sent_to_a = pa_all_above_nb(s, total_size);
	repositionning_stack_b(s);
	if (nb_sent_to_a < 1)
		return ;
	recursive_sort_a_to_b(s, nb_sent_to_a);
	second_step_recursive(s, total_size - nb_sent_to_a);
}

void		recursive_sort_a_to_b(t_stack *s, ssize_t total_size)
{
	ssize_t	nb_sent_to_b;

	if (is_sorted(s) == FAILURE)
	{
		if (total_size == 3 || (total_size == 0 && s->size_b == 3))
		{
			sort_top_three(s);
			while (total_size == 0 && s->size_b > 0)
				sort_last(s);
			return ;
		}
		else if (total_size == 2)
			sa(s);
		else
		{
			nb_sent_to_b = pb_all_under_nb(s, total_size);
			repositionning_stack_a(s);
			recursive_sort_a_to_b(s, total_size - nb_sent_to_b);
			second_step_recursive(s, nb_sent_to_b);
		}
	}
}

/*
**	iterative solution for 100 and less numbers:
*/
static void	sort_for_five(t_stack *s)
{
	t_stat	*stat;
	size_t	pivot;

	stat = get_stat(s);
	pivot = get_index(s->a, stat->median_a);
	pb_all_under_nb_five(s, pivot);
	ft_memdel((void**)&stat);
	sort_only_three(s);
	while (s->size_b > 0)
	{
		stat = get_stat(s);
		pa_highest(s, stat->max_b);
		ft_memdel((void**)&stat);
	}
}

static void	select_sort_style(t_stack *s)
{
	t_stat	*stat;
	size_t	pivot;

	if (s->size_a == 5)
	{
		sort_for_five(s);
		return ;
	}
	while (s->size_a > 1)
	{
		stat = get_stat(s);
		pivot = get_index(s->a, stat->median_a);
		pb_all_under_nb_iterative(s, pivot);
		ft_memdel((void**)&stat);
	}
	while (s->size_b > 0)
	{
		stat = get_stat(s);
		pa_highest(s, stat->max_b);
		ft_memdel((void**)&stat);
	}
}

void		push_swp(t_stack *s, int ac, char **av)
{
	ssize_t	size;

	s = init_struct(av, ac);
	if (s == NULL)
		return ;
	mkdir("result", 0700);
	s->fd = open("result/tmp.txt", O_RDWR | O_CREAT | O_TRUNC, 0744);
	if (s->fd == FAILURE)
	{
		clean_struct(&s);
		ft_print_err_void("when creating result file", STD_ERR);
		return ;
	}
	size = s->size_a;
	if (s->size_a > 1 && is_sorted(s) == FAILURE)
	{
		if (s->size_a <= 100)
			s->size_a <= 3 ? sort_only_three(s) : select_sort_style(s);
		else
			recursive_sort_a_to_b(s, size);
	}
	if (s->verbose == TRUE)
		print_stack(s, NO_OPE, 0);
	save_final_result_in_file(s);
	clean_struct(&s);
}
