/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:49:02 by fkante            #+#    #+#             */
/*   Updated: 2020/04/27 09:50:44 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_top_three_continued(t_stack *s)
{
	size_t	top;

	top = s->size_a - 1;
	if (s->a[top - 1] < s->a[top - 2])
	{
		sa(s);
		pb(s);
		sa(s);
		pa(s);
	}
	if (s->a[top - 1] > s->a[top - 2])
	{
		sa(s);
		pb(s);
		sa(s);
		pa(s);
		sa(s);
	}
}

void		sort_top_three(t_stack *s)
{
	size_t	top;

	top = s->size_a - 1;
	if ((s->a[top] < s->a[top - 1] && s->a[top - 1] < s->a[top - 2]))
		return ;
	if (s->a[top] < s->a[top - 1] && s->a[top] < s->a[top - 2])
	{
		pb(s);
		sa(s);
		pa(s);
	}
	else if (s->a[top] < s->a[top - 1] || s->a[top] < s->a[top - 2])
	{
		if (s->a[top] > s->a[top - 1])
			sa(s);
		else if (s->a[top] > s->a[top - 2])
		{
			pb(s);
			sa(s);
			pa(s);
			sa(s);
		}
	}
	else
		sort_top_three_continued(s);
}

/*
** 3 2 1 -
** 3 1 2 -
** 2 3 1 -
** 2 1 3 -
** 1 3 2 -
** 1 2 3 -
*/

static void	sort_only_two(t_stack *s)
{
	size_t top;

	top = s->size_a - 1;
	if (s->a[top] > s->a[top - 1])
		sa(s);
	else
		return ;
}

static void	sort_only_three_continued(t_stack *s)
{
	size_t	top;

	top = s->size_a - 1;
	if (s->a[top - 1] < s->a[top - 2])
		ra(s);
	if (s->a[top - 1] > s->a[top - 2])
	{
		ra(s);
		sa(s);
	}
}

void		sort_only_three(t_stack *s)
{
	size_t	top;

	if (s->size_a == 2)
	{
		sort_only_two(s);
		return ;
	}
	top = s->size_a - 1;
	if ((s->a[top] < s->a[top - 1] && s->a[top - 1] < s->a[top - 2]))
		return ;
	if (s->a[top] < s->a[top - 1] && s->a[top] < s->a[top - 2])
	{
		pb(s);
		sa(s);
		pa(s);
	}
	else if (s->a[top] < s->a[top - 1] || s->a[top] < s->a[top - 2])
	{
		if (s->a[top] > s->a[top - 1])
			sa(s);
		else if (s->a[top] > s->a[top - 2])
			rra(s);
	}
	else
		sort_only_three_continued(s);
}
