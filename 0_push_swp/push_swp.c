/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/02/06 15:12:31 by fkante           ###   ########.fr       */
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
	pivot_on_top_a(s, pivot);
}

void	insertion_sort_style(t_stack *s)
{
	t_stat	*stat;
	char	*line = NULL;
	size_t	i;
	size_t	pivot;

	(void)line;
	pivot = 0;
	while (get_next_line(0, &line) > 0)
//	while (s->size_a > 3)
	{
		i = s->size_a - 1;
		stat = get_stat(s);
		print_stack(s, NO_OPE, 0);
//		ft_printf("size a = %d\n", s->size_a);
		ft_printf("pivot = %d\n", pivot);
		pivot = ft_get_n_smallest(s->a, s->size_a/3, 0, s->size_a);
		if (s->size_a < 3 && is_sorted(s->a[i], s->a[i - 1]) == SUCCESS)
			break ;
		pb_under_pivot_unsorted(s, pivot);
		ft_strdel(&line);
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
