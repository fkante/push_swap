/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:41:48 by amartino          #+#    #+#             */
/*   Updated: 2019/11/25 18:45:52 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	deepness(int32_t *tab, size_t max)
{
	size_t	deep;

	deep = 0;
	while (max != 0)
	{
		max = (max - 1) / 2;
		deep++;
	}
	return (deep);
}

size_t	get_parent(size_t index)
{
	return ((index - 1) / 2);
}

size_t	get_1st_child(size_t index)
{
	return ((index * 2) + 1);
}

size_t	get_2nd_child(size_t index)
{
	return ((index * 2) + 2);
}

void	print(int32_t *tab, size_t index, size_t deep, size_t max)
{
	size_t		space;

	space = 6 * deep;
	if (index > max)
		return ;

	print(tab, get_2nd_child(index), deep + 1, max);

	printf("\n");
    for (int i = 0; i < space; i++)
        printf(" ");
    printf("%d\n", tab[index]);

	print(tab, get_1st_child(index), deep + 1, max);
}

void 	is_valid(int32_t *tab)

void	insert(int32_t *tab, int32_t nb, size_t index)
{
	tab[index] = nb;
}

int		main()
{
	int32_t		base[12] = {1, 33, -7, 40, 5, 9, 8, 0, -20, 15, 22, -12};
	int32_t		size = 12;
	int32_t		over_half = (size / 2) + 1;
	int32_t		tab[over_half];
	size_t		i;
	size_t		index;
	size_t		parent_index;

	tab[0] = base[0];
	i = 1;
	parent_index = 0;
	while (i < over_half)
	{
		index = get_1st_child(parent_index);
		insert(tab, base[i], index);
		i++;
		if (i < over_half)
		{
			index = get_2nd_child(parent_index);
			insert(tab, base[i], index);
		}
		i++;
		parent_index++;
	}
	print(tab, 0, 0, index);
	return (0);
}
