/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:01:53 by fkante            #+#    #+#             */
/*   Updated: 2020/02/26 16:57:38 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
**void		*ft_malloc_debug(size_t size, const char *file, int line,
**							const char *function)
**{
**	void	*ptr;
**	srand(time(NULL)); 		  // Initialization, should only be called once.
**	uint32_t r = rand();      // Returns a pseudo-random integer between 0
**								and RAND_MAX.
**	uint32_t res;
**
**	if (file != NULL && function != NULL)
**		printf("Allocated bytes:\t%-10zu in %-40s at line %8d |\t%-20s\n",
**	size, file, line, function);
**
**	ptr = (void *)malloc(size);
**	ft_bzero(ptr, size);
**
**	res = (1 + r * (int)ptr * (size / line)) % 15;
**	printf("res %d\n", res);
**	if (res == 0)
**	{
**		printf("FAILED\n");
**		free(ptr);
**		ptr = NULL;
**	}
**	return (ptr);
**}
*/
