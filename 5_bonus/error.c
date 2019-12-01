/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 12:01:18 by fkante            #+#    #+#             */
/*   Updated: 2019/12/01 12:24:50 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int8_t ope)
{
	t_vector	*input_error;

	input_error = vct_newstr("\n\tError invalid input\n"); 
	if (ope == NB_OPE)
		vct_print(input_error);
}
