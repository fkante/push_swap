#!/bin/bash

clang test_generator.c ../libft/libft.a ../libft/ft_printf/libftprintf.a -I./../libft/includes -o number_gen
