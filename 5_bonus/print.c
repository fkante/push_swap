/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:23:57 by amartino          #+#    #+#             */
/*   Updated: 2020/02/25 11:36:17 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_command(size_t count, int8_t ope, t_stack *s)
{
	ft_printf("\tCount = %u\n\tSize = %zu\tSize_a = %zu \tSize_b = %zu\n\n\t",
				count, (s->size_a + s->size_b), s->size_a, s->size_b);
	if (s->color == TRUE && (ope >= 0 && ope <= 2))
		ft_printf("{c_b_green}Swap\t\tA: sa\tB: sb\tBoth: ss{c_end}\n", count);
	else
		ft_printf("Swap\t\tA: sa\tB: sb\tBoth: ss\n", count);
	if (s->color == TRUE && (ope == 3 || ope == 4))
		ft_printf("\t{c_b_green}Push\t\tA: pa\tB: pb{c_end}\n");
	else
		ft_printf("\tPush\t\tA: pa\tB: pb\n");
	if (s->color == TRUE && (ope >= 5 && ope <= 7))
		ft_printf("\t{c_b_green}Rotate up\tA: ra\tB: rb\tBoth: rr{c_end}\n");
	else
		ft_printf("\tRotate up\tA: ra\tB: rb\tBoth: rr\n");
	if (s->color == TRUE && (ope >= 8 && ope <= 10))
		ft_printf("\t{c_b_green}Rotate down\tA: rra\tB: rrb\tBoth: rrr\n");
	else
		ft_printf("\tRotate down\tA: rra\tB: rrb\tBoth: rrr\n");
	if (s->color == TRUE)
	{
		ft_printf("{c_end}\n\tCOLOR:\n\t{c_b_green}Last action{c_end}\n");
		ft_printf("\t{c_yellow}Minimum{c_end}\n\t{c_blue}Median{c_end}\n");
		ft_printf("\t{c_red}Maximum{c_end}\n");
	}
}

int8_t	check_ope(t_stack *s, size_t size, int8_t ope, int8_t stack)
{
	size_t	ret;
	size_t	len;

	ret = 0;
	len = s->size_a - 1;
	if (stack == STACK_A && ope != NO_OPE)
	{
		if ((ope == 7 && size == 0) || (ope == 10 && size == len)
				|| (ope == 0 && size == len - 1) || (s->a[size] == s->color_nb)
				|| (ope == 2 && (size == len || size == len - 1)))
			ret = ft_printf("\t|\t\t{c_b_green}%d{c_end}\t\t| |\t", s->a[size]);
	}
	else if (stack == STACK_B && ope != NO_OPE)
	{
		if ((ope == 1 && size == s->size_b - 2) || (s->b[size] == s->color_nb)
				|| (ope == 2 && size == s->size_b - 2))
			ret = ft_printf("\t{c_b_green}%d{c_end}\t\t|\n", s->b[size]);
	}
	return (ret > 0 ? TRUE : FALSE);
}

void	handle_stack_a(t_stack *s, size_t size, int8_t ope, t_stat *stat)
{
	if ((check_ope(s, size, ope, STACK_A) == TRUE))
		return ;
	else if (s->a[size] == stat->min_a && s->size_a > 4)
		ft_printf("\t|\t\t{c_yellow}%d{c_end}\t\t| |\t", s->a[size]);
	else if (s->a[size] == stat->max_a && s->size_a > 4)
		ft_printf("\t|\t\t{c_red}%d{c_end}\t\t| |\t", s->a[size]);
	else if (s->a[size] == stat->median_a && s->size_a > 4)
		ft_printf("\t|\t\t{c_blue}%d{c_end}\t\t| |\t", s->a[size]);
	else
		ft_printf("\t|\t\t%d\t\t| |\t", s->a[size]);
}

void	handle_stack_b(t_stack *s, size_t size, int8_t ope, t_stat *stat)
{
	if ((check_ope(s, size, ope, STACK_B) == TRUE))
		return ;
	else if (s->b[size] == stat->min_b && s->size_b > 4)
		ft_printf("\t{c_yellow}%d{c_end}\t\t|\n", s->b[size]);
	else if (s->b[size] == stat->max_b && s->size_b > 4)
		ft_printf("\t{c_red}%d{c_end}\t\t|\n", s->b[size]);
	else if (s->b[size] == stat->median_b && s->size_b > 4)
		ft_printf("\t{c_blue}%d{c_end}\t\t|\n", s->b[size]);
	else
		ft_printf("\t%d\t\t|\n", s->b[size]);
}

void	print_stack(t_stack *s, int8_t ope, size_t count)
{
	t_vector	*head;
	t_vector	*foot;

	head = vct_newstr("\t _______________________________   \
_____________________________\n\t|\t\tSTACK A\t\t| |\t\tSTACK B\t\t|\n\
\t ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔   ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n\
\t _______________________________   _____________________________\n");
	foot = vct_newstr("\t ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔   \
▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
	ft_printf("\e[1;1H\e[2J");
	vct_print(head);
	vct_del(&head);
	s->color == TRUE ? print_with_color(s, ope) : print_no_color(s);
	vct_print(foot);
	vct_del(&foot);
	print_command(count, ope, s);
}
