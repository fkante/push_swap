# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <amartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/26 11:56:39 by amartino          #+#    #+#              #
#    Updated: 2019/11/23 20:12:54 by amartinod        ###   ########.fr        #
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
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS =  -Wall -Wextra -Werror -fsanitize=address,undefined -g3
INCLUDES += -I./include
INCLUDES += -I./libft/includes
INCLUDES += -I./libft/ft_printf/includes
HEAD += ./include/define.h
HEAD += ./include/push_swap.h

                     ####################################
                     #                   				#
                     #       		PATHS     			#
                     #                   				#
                     ####################################
# LIB
LIB_PATH = $(LIB_DIR)/$(LIB)

# SRCS
PATH_SRC += push_swp/
PATH_SRC += check/
PATH_SRC += tool/
PATH_SRC += init/
PATH_SRC += clean/
PATH_SRC += bonus/

vpath %.c $(PATH_SRC)

                     ####################################
                     #                   				#
                     #       	   SOURCE      			#
                     #                   				#
                     ####################################
# main
SRCS += main

# push_swap
SRCS += push_swp

# checker
SRCS += checker

# initialize
SRCS += init
SRCS += parse

# tool
SRCS += push_stack
SRCS += rotate_stack
SRCS += swap_stack

# clean
SRCS += clean

#bonus
SRCS += print
SRCS += color
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

OBJS = $(patsubst %, $(BUILD_DIR)%.o, $(SRCS))
ALLOBJS += $(OBJS)
ALLOBJS += $(LIB_DIR)$(BUILD_DIR)*.o

                     ####################################
                     #                   				#
                     #       	   RULES      			#
                     #                   				#
                     ####################################
all: $(NAME_CHECKER) $(NAME_PUSH_SWP)

$(NAME_PUSH_SWP): $(BUILD_DIR) $(OBJS) $(LIB_PATH)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB_PATH)
	@echo "\n$(CYAN)MAKE COMPLETE$(END)"

$(NAME_CHECKER): $(BUILD_DIR) $(OBJS) $(LIB_PATH)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIB_PATH)
	@echo "\n$(CYAN)MAKE COMPLETE$(END)"

$(BUILD_DIR):
	mkdir $@

$(OBJS): $(BUILD_DIR)%.o: %.c $(HEAD) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

$(LIB_PATH): FORCE
	make -C $(LIB_DIR)

t: all $(VAL)
	$(VALGRIND) ./ft_printf examples/$(T) #to be changed

clean:
	rm -f $(OBJS)
	rm -rf ./build
	echo "$(YELLOW)OBJS$(END) \t\t were \t\t $(GREEN)clean$(END)\n"
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -rf $(NAME_PUSH_SWP) $(NAME_CHECKER)
	echo "$(YELLOW)$(NAME)$(END) \t were \t $(GREEN)clean$(END)\n"
	$(MAKE) fclean -C $(LIB_DIR)

re: fclean all

.PHONY: clean fclean all re t FORCE git
.SILENT: $(NAME) $(OBJS) $(BUILD_DIR) $(LIB_PATH) clean fclean re t FORCE
FORCE:


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
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
MAGENTA = \x1b[35m
CYAN = \x1b[36m
END = \x1b[0m
