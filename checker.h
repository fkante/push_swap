/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2019/11/21 15:15:53 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "ft_printf.h"
#include "define.h"

# define FALSE				0
# define TRUE				1
# define VERBOSE 			0
# define COLOR				0

typedef struct	s_stack
{
	int32_t	*a;
	int32_t	*b;
	size_t	size_a;
	size_t	size_b;
}				t_stack;

#endif
