/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:23:57 by amartino          #+#    #+#             */
/*   Updated: 2019/11/30 16:20:06 by amartino         ###   ########.fr       */
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

int32_t		ft_high(int32_t *tab, size_t size)
{
	int32_t		high;
	size_t		i;

	i = 0;
	high = tab[i];
	while (i < size)
	{
		if (high < tab[i])
			high = tab[i];
		i++;
	}
	return (high);
}

int32_t		ft_low(int32_t *tab, size_t size)
{
	int32_t		low;
	size_t		i;

	i = 0;
	low = tab[i];
	while (i < size)
	{
		if (low > tab[i])
			low = tab[i];
		i++;
	}
	return (low);
}

t_stat 	*get_stat(t_stack *s)
{
	t_stat		*stat;

	stat = ft_memalloc(sizeof(t_stat));
	if (stat != NULL)
	{
		stat->min_a = ft_low(s->a, s->size_a);;
		stat->max_a = ft_high(s->a, s->size_a);
		stat->median_a = 2;
		stat->min_b = 0;
		stat->max_b = 0;
		stat->median_b = 0;
	}
	return (stat);
}

void	check_ope(int32_t nb, int8_t ope, int8_t stack)
{
	(void)ope;
	if (stack == STACK_A)
		ft_printf("\t\t\t|\t\t{c_green}%d{c_end}\t\t| |\t", nb);
	else
		ft_printf("\t{c_green}%d{c_end}\t\t|\n", nb);
}

void	handle_stack_a(int32_t nb, int32_t color_nb, int8_t ope, t_stat *stat)
{
	if (nb == color_nb)
		check_ope(nb, ope, STACK_A);
	else if (nb == stat->min_a)
		ft_printf("\t\t\t|\t\t{c_yellow}%d{c_end}\t\t| |\t", nb);
	else if (nb == stat->max_a)
		ft_printf("\t\t\t|\t\t{c_red}%d{c_end}\t\t| |\t", nb);
	else if (nb == stat->median_a)
		ft_printf("\t\t\t|\t\t{c_blue}%d{c_end}\t\t| |\t", nb);
	else
		ft_printf("\t\t\t|\t\t%d\t\t| |\t", nb);
}

void	handle_stack_b(int32_t nb, int32_t color_nb, int8_t ope, t_stat *stat)
{
	if (nb == color_nb)
		check_ope(nb, ope, STACK_B);
	else if (nb == stat->min_b)
		ft_printf("\t{c_yellow}%d{c_end}\t\t|\n", nb);
	else if (nb == stat->max_b)
		ft_printf("\t{c_red}%d{c_end}\t\t|\n", nb);
	else if (nb == stat->median_b)
		ft_printf("\t{c_blue}%d{c_end}\t\t|\n", nb);
	else
		ft_printf("\t%d\t\t|\n", nb);
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
				handle_stack_a(s->a[size_a], s->color_nb, ope, stat);
			}
			else
				ft_printf("\t\t\t|\t\t\t\t| |\t");
			if (size_b > 0)
			{
				size_b--;
				handle_stack_b(s->b[size_b], s->color_nb, ope, stat);
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
