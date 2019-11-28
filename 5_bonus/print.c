/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:23:57 by amartino          #+#    #+#             */
/*   Updated: 2019/11/28 17:53:50 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_no_color(t_stack *s)
{
	size_t		a;
	size_t		b;

	a = s->size_a;
	b = s->size_b;
	while (a > 0 || b > 0)
	{
		if (a > 0)
		{
			a--;
			ft_printf("\t\t\t|\t\t%d\t\t| |\t", s->a[a]);
		}
		else
			ft_printf("\t\t\t|\t\t\t\t| |\t");
		if (b > 0)
		{
			b--;
			ft_printf("\t%d\t\t|\n", s->b[b]);
		}
		else
			ft_printf("\t\t\t|\n");
	}
}

// s->color_nb == s->b[b] ? ft_printf("\t{c_red}%d{c_end}\t\t|\n", s->b[b]) : ft_printf("\t%d\t\t|\n", s->b[b]);

// t_stat 	*get_stat(t_stack *s)
// {
// 	t_stat		stat;
//
// 	stat = ft_memalloc(sizeof(t_stat));
	// if (stat != NULL)
	// {
		// min_a = ;
		// max_a = ;
		// median_a = ;
		// min_b = ;
		// max_b = ;
		// median_b = ;
	// }
// 	return (stat);
// }
//
// void	handle_stack_a(int32_t nb, int8_t ope, t_stat *stat)
// {
// 	ft_printf("\t\t\t|\t\t{c_red}%d{c_end}\t\t| |\t", s->a[a]);
// 	ft_printf("\t\t\t|\t\t%d\t\t| |\t", s->a[a]);
// }
//
// void	handle_stack_b(int32_t nb, int8_t ope, t_stat *stat)
// {
//
// }
//
// void	print_with_color(t_stack *s, int8_t ope)
// {
// 	t_stat		stat;
// 	size_t		size_a;
// 	size_t		size_b;
//
// 	size_a = s->size_a;
// 	size_b = s->size_b;
// 	stat = get_stat(t_stack *s);
// 	if (stat != NULL)
// 	{
// 		while (size_a > 0 || size_b > 0)
// 		{
// 			if (size_a-- > 0)
// 				handle_stack_a(s->a[size_a], s->color_nb, ope, stat);
// 			else
// 				ft_printf("\t\t\t|\t\t\t\t| |\t");
// 			if (size_b-- > 0)
// 				handle_stack_b(s->b[size_b], ope, stat);
// 			else
// 				ft_printf("\t\t\t|\n");
// 		}
// 	}
// 	ft_memdel((void**)&stat);
// }

void	print_stack(t_stack *s, int8_t ope)
{
	t_vector	*head;
	t_vector	*foot;
	(void)ope;

	head = vct_newstr("\t\t\t _______________________________   \
_____________________________\n\t\t\t|\t\tSTACK A\t\t| |\t\tSTACK B\t\t|\n\
\t\t\t ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔   ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n\
\t\t\t _______________________________   _____________________________\n");
	foot = vct_newstr("\t\t\t ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔   \
▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
	system("clear");
	vct_print(head);
	// s->color == TRUE ? print_with_color(s, ope) : print_no_color(s);
	print_no_color(s);
	vct_print(foot);
}
