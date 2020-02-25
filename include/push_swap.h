/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2020/02/25 11:36:18 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "define_ps.h"

typedef struct	s_stack
{
	int32_t	*a;
	int32_t	*b;
	size_t	size_a;
	size_t	size_b;
	size_t	rotation_a;
	size_t	rotation_b;
	int32_t	color_nb;
	int8_t	fd;
	uint8_t	verbose;
	uint8_t	color;
}				t_stack;

typedef struct 	s_stat
{
	int32_t		min_a;
	int32_t		max_a;
	int32_t		median_a;
	int32_t		min_b;
	int32_t		max_b;
	int32_t		median_b;
}				t_stat;

/*
** ############################################################################
** ################################# INIT #####################################
** ############################################################################
*/
t_stack			*init_struct(char **av, int ac);
t_stack			*create_stack(char **tab, size_t len);
t_stack			*fill_stack(t_stack *s, size_t start, char **tab, size_t len);
uint8_t			check_no_double(t_stack *s);
ssize_t			parse_args(char **av, int32_t ac);
int8_t			check_err(char *str, size_t j);
uint8_t			check_for_bonus(char **tab, char *chr);
int8_t			check_for_duplicate_bonus(char **tab, size_t len);

/*
** ############################################################################
** ################################ PUSH_SWAP #################################
** ############################################################################
*/
void		push_swp(t_stack *s, int ac, char **av);
void		solve(t_stack *s);
void		pb_lowest(t_stack *s, int32_t limit);
void		pa_highest(t_stack *s, int32_t limit);
size_t		pb_all_under_nb(t_stack *s, int32_t nth);
size_t		pa_all_above_nb(t_stack *s, int32_t nth);
void		pivot_on_top_a(t_stack *s, int32_t pivot);
void		pivot_on_top_b(t_stack *s, int32_t pivot);
void		sort_less_three(t_stack *s);
int8_t		is_sorted_less_than_three(t_stack *s, size_t size);
void		recursive_sort_a_to_b(t_stack *s, size_t total_size);
void		repositionning_stack_a(t_stack *s);
void		repositionning_stack_b(t_stack *s);
void		pb_all_under_nb_iterative(t_stack *s, int32_t pivot_index);

/*
** ############################################################################
** ################################ CHECKER ###################################
** ############################################################################
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

typedef	void	(*t_operfunc)(t_stack *s);
int8_t			read_checker(t_stack *s);
void			operation_checker(t_operfunc *f, char *ln, t_stack *s,
									size_t *count);

/*
** ############################################################################
** ################################# BONUS ####################################
** ############################################################################
*/
void			print_stack(t_stack *s, int8_t ope, size_t count);
void			print_command(size_t count, int8_t ope, t_stack *s);
t_stat 			*get_stat(t_stack *s);
ssize_t			get_nb_of_move();
ssize_t			collision_in_filename(t_vector *name, int8_t suffixe);
void			write_final_result(ssize_t fd);
void			save_final_result_in_file(t_stack *s);
void			show_result(t_stack *s);
void			print_with_color(t_stack *s, int8_t ope);
void			print_no_color(t_stack *s);
void			handle_stack_a(t_stack *s, size_t size, int8_t ope, t_stat *stat);
int8_t			check_ope(t_stack *s, size_t size, int8_t ope, int8_t stack);
void			handle_stack_b(t_stack *s, size_t size, int8_t ope, t_stat *stat);

/*
** ############################################################################
** ################################# TOOL #####################################
** ############################################################################
*/
void			swap_stack_a(t_stack *s);
void			swap_stack_b(t_stack *s);
void			push_stack_a(t_stack *s);
void			push_stack_b(t_stack *s);
void			shiftup_stack_a(t_stack *s);
void			shiftup_stack_b(t_stack *s);
void			shiftdown_stack_a(t_stack *s);
void			shiftdown_stack_b(t_stack *s);
void			rotate_stack_a(t_stack *s);
void			rotate_stack_b(t_stack *s);
void			reverse_rotate_stack_a(t_stack *s);
void			reverse_rotate_stack_b(t_stack *s);
void			swap_nb(int32_t *stack1, int32_t *stack2);
void			swap_both(t_stack *s);
void			rotate_both(t_stack *s);
void			reverse_both(t_stack *s);
void			pa(t_stack *s);
void			pb(t_stack *s);
void			sa(t_stack *s);
void			sb(t_stack *s);
void			ss(t_stack *s);
void			ra(t_stack *s);
void			rb(t_stack *s);
void			rra(t_stack *s);
void			rrb(t_stack *s);
void			rr(t_stack *s);
void			rrr(t_stack *s);
size_t			how_many_sorted(t_stack *s);
int8_t			is_sorted(t_stack *s);
int8_t			is_sorted_checker(t_stack *s);
size_t			get_index(int32_t *tab, int32_t nb);
void			sort_top_three(t_stack *s);
int8_t			any_value_under_nb(t_stack *s, int32_t nb);
int8_t			any_value_above_nb(t_stack *s, int32_t nb);
void			repositionning_stack_a(t_stack *s);
void			repositionning_stack_b(t_stack *s);
t_stat 			*get_stat(t_stack *s);

/*
** ############################################################################
** ################################# CLEAN ####################################
** ############################################################################
*/
void			clean_struct(t_stack **s);
void			clean_tmp(char ***tmp, size_t i);

#endif
