/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/01/22 17:09:03 by fkante           ###   ########.fr       */
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
	size_t	subdiv;

	ft_printf("unsorted nb = %d\n", pivot);
	pb_all_under_nb(s, pivot);
	pivot_on_top_a(s, pivot);
	subdiv = s->size_b + 1;
	while (s->size_b > 0)
		pa_highest(s, s->size_b);
	while (subdiv-- > 0)
		ra(s);
	pb_subdiv_above_pivot(s, pivot, 10);
}

void	insertion_sort_style(t_stack *s)
{
	t_stat	*stat;
	char	*line = NULL;
	size_t	i;
	size_t	unsorted_nb;

	i = s->size_a - 1;
	unsorted_nb = 0;
	stat = get_stat(s);
	while (get_next_line(0, &line) > 0)
	{
		print_stack(s, NO_OPE, 0);
		if (is_sorted(s->a[i], s->a[i - 1]) == SUCCESS)
			i--;
		else
		{
			unsorted_nb = i - 1;
			pb_under_pivot_unsorted(s, s->a[unsorted_nb]);
			i = s->size_a - 1;
		}
		ft_strdel(&line);
	}
	ft_memdel((void**)&stat);
}

void	solve(t_stack *s)
{
	print_stack(s, NO_OPE, 0);
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
