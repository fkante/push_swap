# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <amartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/26 11:56:39 by amartino          #+#    #+#              #
#    Updated: 2020/05/04 10:13:31 by francis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
                     ####################################
                     #                   				#
                     #       	MAIN VARIABLES 			#
                     #                   				#
                     ####################################
NAME_PUSH_SWP = push_swap
NAME_CHECKER = checker
LIB_DIR = ./libft/ft_printf
LIB = libftprintf.a
CC = clang
#override CFLAGS += -Wall -Wextra -Werror
CFLAGS += -Wall -Wextra -Werror
DFLAGS =  -Wall -Wextra -Werror -fsanitize=address,undefined -g3
INCLUDES += -I./include
INCLUDES += -I./libft/includes
INCLUDES += -I./libft/ft_printf/includes
HEAD += ./include/define_ps.h
HEAD += ./include/push_swap.h

                     ####################################
                     #                   				#
                     #       		PATHS     			#
                     #                   				#
                     ####################################
# LIB
LIB_PATH = $(LIB_DIR)/$(LIB)

# SRCS
PATH_SRC += 0_push_swp/
PATH_SRC += 1_checker/
PATH_SRC += 2_init/
PATH_SRC += 3_tool/
PATH_SRC += 4_clean/
PATH_SRC += 5_bonus/

vpath %.c $(PATH_SRC)

                     ####################################
                     #                   				#
                     #       	   SOURCE      			#
                     #                   				#
                     ####################################
# main
MAIN_PUSH = main_pushswap
MAIN_CHECK = main_check

# push_swap
SRCS += push_swp
SRCS += pivot_on_top
SRCS += operation_on_stack
SRCS +=	pb_all_under_five 
SRCS += repositionning_stack

# checker
SRCS += checker

# initialize
SRCS += init
SRCS += parse

# tool
SRCS += get_index
SRCS += get_stat
SRCS += push_stack
SRCS += swap_stack
SRCS += swap_both
SRCS += shift_stack
SRCS += rotate_both
SRCS += rotate_stack
SRCS += sorted_check
SRCS += sort_top_three 
SRCS += reverse_rotate_stack
SRCS += find_value_in_stack 

# clean
SRCS += clean

#bonus
SRCS += print
SRCS += color
SRCS += output_file

                     ####################################
                     #                   				#
                     #       	  VARIABLES    			#
                     #                   				#
                     ####################################
T ?= sample
VAL ?= no
REQUEST = 'read -p "Enter a commit message:" pwd; echo $$pwd'
COMMIT_MESSAGE ?= $(shell bash -c $(REQUEST))

                     ####################################
                     #                   				#
                     #              OBJS	   			#
                     #                   				#
                     ####################################
BUILD_DIR = build/

MAIN_OBJ_PS = $(patsubst %, %.o, $(MAIN_PUSH))
MAIN_OBJ_C = $(patsubst %, %.o, $(MAIN_CHECK))
OBJS = $(patsubst %, $(BUILD_DIR)%.o, $(SRCS))

                     ####################################
                     #                   				#
                     #       	   RULES      			#
                     #                   				#
                     ####################################
all: $(NAME_CHECKER) $(NAME_PUSH_SWP)
	@echo "\n$(CYAN)MAKE COMPLETE$(END)"

$(NAME_PUSH_SWP): $(BUILD_DIR) $(MAIN_OBJ_PS) $(OBJS) $(LIB_PATH)
	@$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ_PS) $(OBJS) $(LIB_PATH) $(INCLUDES)

$(NAME_CHECKER): $(BUILD_DIR) $(MAIN_OBJ_C) $(OBJS) $(LIB_PATH)
	@$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ_C) $(OBJS) $(LIB_PATH) $(INCLUDES)

$(BUILD_DIR):
	mkdir $@

$(MAIN_OBJ_PS): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

$(MAIN_OBJ_C): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

$(OBJS): $(BUILD_DIR)%.o: %.c $(HEAD) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

$(LIB_PATH): FORCE
	$(MAKE) -C $(LIB_DIR)

t: all $(VAL)
	$(VALGRIND) ./ft_printf examples/$(T) #to be changed

clean:
	rm -f $(OBJS)
	rm -f $(MAIN_OBJ_PS) $(MAIN_OBJ_C)
	rm -rf ./$(BUILD_DIR)
	echo "$(YELLOW)OBJS$(END) \t\t were \t\t $(GREEN)clean$(END)\n"
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -rf $(NAME_PUSH_SWP) $(NAME_CHECKER)
	echo "$(YELLOW)$(NAME_PUSH_SWP)$(END) and $(YELLOW)$(NAME_CHECKER)$(END) \t were \t $(GREEN)clean$(END)\n"
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean
	$(MAKE)

FORCE:
	true

.PHONY: clean fclean all re t FORCE git
.SILENT: $(NAME) $(OBJS) $(BUILD_DIR) $(MAIN_OBJ_PS) $(MAIN_OBJ_C) $(LIB_PATH) clean fclean re t FORCE


                     ####################################
                     #                   				#
                     #       	  	IFEQ	   			#
                     #                   				#
                     ####################################

# FLAGS
ifeq ($(f), no)
CFLAGS = -g
else ifeq ($(f), f)
CFLAGS = $(DFLAGS)
endif

# VALGRIND
$(VAL):
ifeq ($(VAL), no)
VALGRIND =
else
CFLAGS += -g
SHOW_LEAK = --show-leak-kinds=definite
VALGRIND = valgrind --track-origins=yes --leak-check=full $(SHOW_LEAK)
endif

                     ####################################
                     #                   				#
                     #        		GIT       			#
                     #                   				#
                     ####################################
git:
	@git add -f -A
	@git commit -m "$(COMMIT_MESSAGE)"
	@git push

                     ####################################
                     #                   				#
                     #       		COLOR     			#
                     #                  				#
                     ####################################
RED = \033[0;31m
GREEN = \033[0;32m 
YELLOW = \033[0;33m 
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m 
END = \033[0m

#Linux
#RED = \e[31m
#GREEN = \e[32m
#YELLOW = \e[33m
#BLUE = \e[34m
#MAGENTA = \e[35m
#CYAN = \e[36m
#END = \e[0m
