/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_ps.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:16:29 by amartino          #+#    #+#             */
/*   Updated: 2020/02/27 10:31:52 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_PS_H
# define DEFINE_PS_H

# define FALSE				0
# define TRUE				1
# define SUCCESS			0
# define FAILURE			-1
# define FAILURE_OPE		-2
# define MALLOC_ERR			-1
# define TEST_ERR			-1
# define INPUT_ERR			-1
# define FD_ERR				-1
# define STD_IN				0
# define STD_OUT			1
# define STD_ERR			2
# define READ_LIMIT			80000

# define VERBOSE 			0
# define NB_OPE				11
# define NO_OPE				-1
# define STACK_A			0
# define STACK_B			1

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

/*
** ############################################################################
** ################################# ERROR ####################################
** ############################################################################
*/
# define STD_OUT_ERROR		"couldn't write to stdout"
# define WRONG_OPERATION	"please type in a valid input"
# define INPUT_TOO_LONG		"read error"
# define DUPLICATES			"duplicates of numbers input by user"
# define ONLY_INT			"program only accept integer value from input"
# define ERROR_BONUS		"flag must be used once after program name"

#endif
