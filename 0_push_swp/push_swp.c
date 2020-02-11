/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/02/11 15:28:18 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	second_recursive(t_stack *s, size_t counter)
{
	t_stat	*stat;
	
	ft_printf("counter = %d\n", counter);
	while (counter > 0)
	{
		stat = get_stat(s);
		pa_highest(s, stat->max_b);
		ft_memdel((void**)&stat);
		counter--;
	}
}

void	recursive_sort_style(t_stack *s)
{
	t_stat	*stat;
	size_t	pivot;
	size_t	counter;

	counter = s->size_a / 2;
	if (s->size_a > 1)
	{
		stat = get_stat(s);
		pivot = get_index(s->a, stat->median_a);
		pb_all_under_nb(s, pivot);
		ft_memdel((void**)&stat);
		recursive_sort_style(s);
	}
	//ft_printf("size_a = %d\tcounter = %d\n", s->size_a, counter);
	second_recursive(s, counter);
}

void	insertion_sort_style(t_stack *s)
{
	t_stat	*stat;
	size_t	pivot;

	while (s->size_a > 1)
	{
		stat = get_stat(s);
		pivot = get_index(s->a, stat->median_a);
		pb_all_under_nb(s, pivot);
		ft_memdel((void**)&stat);
	}
	while (s->size_b > 0)
	{
		stat = get_stat(s);
		pivot = get_index(s->b, stat->median_b);
		pa_highest(s, stat->max_b);
		ft_memdel((void**)&stat);
	}
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
	if (s->size_a > 1 && is_sorted(s) == FAILURE)
		s->size_a <= 3 ? sort_less_three(s) : recursive_sort_style(s);
//	if (s->verbose == TRUE)
//		print_stack(s, NO_OPE, 0);
	save_final_result_in_file(s);
	clean_struct(&s);
}
