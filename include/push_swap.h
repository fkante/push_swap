/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2019/11/28 14:05:48 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "define.h"

# define NB_OF_OPER			11
# define SA					"sa"	
# define SB					"sb"
# define SS					"ss"
# define PA					"pa"	
# define PB					"pb"
# define RA					"ra"
# define RB					"rb"
# define RR					"rr"
# define RRA				"rra"
# define RRB				"rrb"
# define RRR				"rrr"

typedef struct	s_stack
{
	int32_t	*a;
	int32_t	*b;
	size_t	size_init;
	size_t	size_a;
	size_t	size_b;
	uint8_t	verbose;
	uint8_t	color;
}				t_stack;

/*
**********************
**       INIT	    **
**********************
*/
t_stack		*init_struct(char **av, int ac);
t_stack		*create_stack(char **tab, size_t len);
t_stack		*fill_stack(t_stack *s, size_t start, char **tab, size_t len);
uint8_t		check_no_double(t_stack *s);
int8_t		parse_args(char **av, int32_t ac);
int8_t		check_err(char *str, size_t j);
uint8_t		check_for_bonus(char **tab, char *chr);

/*
**********************
**    	PUSH_SWAP    **
**********************
*/

/*
**********************
**      CHECKER	    **
**********************
*/
enum	e_operations
{
	E_SA,
	E_SB,
	E_SS,
	E_PA,
	E_PB,
	E_RA,
	E_RB,
	E_RR,
	E_RRA,
	E_RRB,
	E_RRR
};

typedef	int8_t	(*operfunc)(t_stack *s);
int8_t			read_checker(t_stack *s);

/*
**********************
**      BONUS	    **
**********************
*/
void		print_stack(t_stack *s);

/*
**********************
**      TOOL	    **
**********************
*/
int8_t		swap_stack_a(t_stack *s);
int8_t		swap_stack_b(t_stack *s);
int8_t		push_stack_a(t_stack *s);
int8_t		push_stack_b(t_stack *s);
int8_t		shiftup_stack_a(t_stack *s);
int8_t		shiftup_stack_b(t_stack *s);
int8_t		shiftdown_stack_a(t_stack *s);
int8_t		shiftdown_stack_b(t_stack *s);
int8_t		rotate_stack_a(t_stack *s);
int8_t		rotate_stack_b(t_stack *s);
int8_t		reverse_rotate_stack_a(t_stack *s);
int8_t		reverse_rotate_stack_b(t_stack *s);
int8_t		loop_swap_stack(int32_t *stack1, int32_t *stack2);
int8_t		swap_both(t_stack *s);
int8_t		rotate_both(t_stack *s);
int8_t		reverse_both(t_stack *s);

/*
**********************
**       CLEAN	    **
**********************
*/
void		clean_struct(t_stack **s);
void		clean_tmp(char ***tmp, size_t i);

#endif
