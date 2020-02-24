/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:49:02 by fkante            #+#    #+#             */
/*   Updated: 2020/02/24 16:24:25 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less_three(t_stack *s)
{
	if (s->size_a == 3)
		pb(s);
	if (s->a[0] < s->a[1])
		ra(s);
	if (s->size_b > 0)
		pa(s);
}

void	sort_top_three_continued(t_stack *s)
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

void	sort_top_three(t_stack *s)
{
	size_t	top;

	top = s->size_a - 1;
	if ((s->a[top] < s->a[top - 1] && s->a[top - 1] < s->a[top - 2]) || top < 3)
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
