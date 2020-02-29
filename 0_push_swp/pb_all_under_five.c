#include "push_swap.h"

void	pb_all_under_nb_five(t_stack *s, int32_t pivot_index)
{
	size_t	i;
	size_t	last;
	int32_t pivot_value;

	if (pivot_index >= 0 && pivot_index < (int32_t)s->size_a)
	{
		pivot_value = s->a[pivot_index];
		i = s->size_a > 0 ? s->size_a - 1 : 0;
		while (i > 0)
		{
			last = s->size_a - 1;
			s->a[last] < pivot_value ? pb(s) : ra(s);
			i--;
		}
	}
}
