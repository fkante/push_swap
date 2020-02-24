/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:24:51 by amartino          #+#    #+#             */
/*   Updated: 2020/02/24 17:46:10 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_result(t_stack *s)
{
	char	*line;
	
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		print_stack(s, NO_OPE, 0);
		ft_strdel(&line);
	}
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
				ft_printf("\t|\t\t\t\t| |\t");
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
			ft_printf("\t|\t%d\t%d\t\t| |\t", a ,s->a[a]);
		}
		else
			ft_printf("\t|\t\t\t\t| |\t");
		if (b > 0)
		{
			b--;
			ft_printf("\t%d\t\t|\n", s->b[b]);
		}
		else
			ft_printf("\t\t\t|\n");
	}
}
