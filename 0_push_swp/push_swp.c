/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:28:51 by amartino          #+#    #+#             */
/*   Updated: 2020/02/14 16:17:44 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
 ** //MASTER_BA(sent total)
 ** 		sent = ba(size);
 ** 		master_ab(sent);
 ** 		master_ba(size - sent);
 **
 ** //MASTER_AB(sent total)
 ** 		sent = ab(size);
 ** 		master_ab(size - sent);
 ** 		master_ba(sent);
 */

void	second_step_recursive(t_stack *s, size_t total_size)
{
	size_t	nb_sent_to_a;
//	char	*line = NULL;

//	while (get_next_line(0, &line) > 0)
//		print_stack(s, NO_OPE, 0);
//	ft_printf("-------B TO A--------\ns->size_b = %d\ttotal_size = %d\n", s->size_b, total_size);
	nb_sent_to_a = pa_all_above_nb(s, total_size);
//	ft_printf("nb_sent_to_a = %d\n", nb_sent_to_a);
	if (nb_sent_to_a < 1)
		return ;
	recursive_sort_a_to_b(s, nb_sent_to_a);
	second_step_recursive(s, total_size - nb_sent_to_a);
}

void	recursive_sort_a_to_b(t_stack *s, size_t total_size)
{
	size_t	nb_sent_to_b;
//	char	*line = NULL;

//	while (get_next_line(0, &line) > 0)
//		print_stack(s, NO_OPE, 0);
//	ft_printf("is_sorted = %d\n", is_sorted(s));
	if (is_sorted(s) == FAILURE)
	{
		if (total_size == 3)
		{
			sort_top_three(s);
			return ;
		}
		else if (total_size == 2)
			sa(s);
		else
		{
		//	ft_printf("-------A TO B--------\ns->size_a = %d\ttotal_size = %d\n", s->size_a, total_size);
			nb_sent_to_b = pb_all_under_nb(s, total_size);
			repositionning_highest(s);
			//ft_printf("nb_sent_to_b = %d\n", nb_sent_to_b);
			recursive_sort_a_to_b(s, total_size - nb_sent_to_b);
			second_step_recursive(s, nb_sent_to_b);
		}
	}
}
/*
   void	select_sort_style(t_stack *s)
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
   */ 
void	push_swp(t_stack *s, int ac, char **av)
{
	size_t	size;

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
	size = s->size_a;
	if (s->size_a > 1 && is_sorted(s) == FAILURE)
		s->size_a <= 3 ? sort_less_three(s) : recursive_sort_a_to_b(s, size);
	//	s->size_a <= 3 ? sort_less_three(s) : select_sort_style(s);
	if (s->verbose == TRUE)
		print_stack(s, NO_OPE, 0);
	ft_printf("done\n");
	save_final_result_in_file(s);
	clean_struct(&s);
}
