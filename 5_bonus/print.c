/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:23:57 by amartino          #+#    #+#             */
/*   Updated: 2019/11/30 19:33:15 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_command(size_t count)
{
	ft_printf("Count = %u\n\nSwap\t\tA: sa\tB: sb\tBoth: ss\n", count);
	ft_printf("Push\t\tA: pa\tB: pb\nRotate up\tA: ra\tB: rb\tBoth: rr\n");
	ft_printf("Rotate down\tA: rra\tB: rrb\tBoth: rrr\n");
}

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

t_stat 	*get_stat(t_stack *s)
{
	t_stat		*stat;

	stat = ft_memalloc(sizeof(t_stat));
	if (stat != NULL)
	{
		stat->min_a = ft_low(s->a, s->size_a);
		stat->max_a = ft_high(s->a, s->size_a);
		ft_median(s->a, s->size_a, &stat->median_a);
		stat->min_b = ft_low(s->b, s->size_b);
		stat->max_b = ft_high(s->b, s->size_b);
		ft_median(s->b, s->size_b, &stat->median_b);
	}
	return (stat);
}

void	check_ope(int32_t nb, int8_t ope, int8_t stack)
{
	if (stack == STACK_A && ope != NO_OPE)
			ft_printf("\t\t\t|\t\t{c_b_green}%d{c_end}\t\t| |\t", nb);
	else if (stack == STACK_B && ope != NO_OPE)
			ft_printf("\t{c_b_green}%d{c_end}\t\t|\n", nb);
	else
		ft_printf("\t\t\t|\t\t%d\t\t| |\t", nb);
}

void	handle_stack_a(t_stack *s, size_t size, int8_t ope, t_stat *stat)
{
	if (ope == 7 && size == 0)
		ft_printf("\t\t\t|\t\t{c_b_green}%d{c_end}\t\t| |\t", s->a[size]);
	else if (s->a[size] == s->color_nb)
		check_ope(s->a[size], ope, STACK_A);
	else if (s->a[size] == stat->min_a && s->size_a > 4)
		ft_printf("\t\t\t|\t\t{c_yellow}%d{c_end}\t\t| |\t", s->a[size]);
	else if (s->a[size] == stat->max_a && s->size_a > 4)
		ft_printf("\t\t\t|\t\t{c_red}%d{c_end}\t\t| |\t", s->a[size]);
	else if (s->a[size] == stat->median_a && s->size_a > 4)
		ft_printf("\t\t\t|\t\t{c_blue}%d{c_end}\t\t| |\t", s->a[size]);
	else
		ft_printf("\t\t\t|\t\t%d\t\t| |\t", s->a[size]);
}

void	handle_stack_b(t_stack *s, size_t size, int8_t ope, t_stat *stat)
{
	if (s->b[size] == s->color_nb)
		check_ope(s->b[size], ope, STACK_B);
	else if (s->b[size] == stat->min_b && s->size_b > 4)
		ft_printf("\t{c_yellow}%d{c_end}\t\t|\n", s->b[size]);
	else if (s->b[size] == stat->max_b && s->size_b > 4)
		ft_printf("\t{c_red}%d{c_end}\t\t|\n", s->b[size]);
	else if (s->b[size] == stat->median_b && s->size_b > 4)
		ft_printf("\t{c_blue}%d{c_end}\t\t|\n", s->b[size]);
	else
		ft_printf("\t%d\t\t|\n", s->b[size]);
}

void	print_with_color(t_stack *s, int8_t ope)
{
	t_stat		*stat;
	size_t		size_a;
	size_t		size_b;

	size_a = s->size_a;
	size_b = s->size_b;
	stat = get_stat(s);
	if (stat != NULL)
	{
		while (size_a > 0 || size_b > 0)
		{
			if (size_a > 0)
			{
				size_a--;
				handle_stack_a(s, size_a, ope, stat);
			}
			else
				ft_printf("\t\t\t|\t\t\t\t| |\t");
			if (size_b > 0)
			{
				size_b--;
				handle_stack_b(s, size_b, ope, stat);
			}
			else
				ft_printf("\t\t\t|\n");
		}
	}
	ft_memdel((void**)&stat);
}

void	print_stack(t_stack *s, int8_t ope, size_t count)
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
	s->color == TRUE ? print_with_color(s, ope) : print_no_color(s);
	vct_print(foot);
	print_command(count);
}
