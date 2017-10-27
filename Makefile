# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/19 22:17:21 by vpluchar          #+#    #+#              #
#    Updated: 2017/10/27 17:10:37 by vpluchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Name

NAME	=	fdf

## Compilation
GCC		=	gcc $(FLAGS)
FLAGS	=	-Wall -Wextra -Werror
INC		=	-I./inc -I./libft/includes
FRAM	=	-I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit

## git pull && gcc -Wall -Wextra -Werror -I./inc libft/libft.a -I./libft/includes src/*c -I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit

## Directories

LIB		=	libft/

DOBJ	=	obj
SDIR	=	src

## Colors

R		=	\x1b[31m
G		=	\x1b[32m
Y		=	\x1b[33m
NC		=	\x1b[0m

## Files

SRC		=	src/print.c\
			src/fdf.c\
			src/init.c\
			src/key.c\
			src/map.c\
			src/clr.c

## Utils

OBJ 	=	$(patsubst %.c, $(DOBJ)/%.o, $(SRC))
ODIR	=	$(addprefix $(DOBJ)/, $(SDIR))

## Rules

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(GCC) $(FRAM) -o $(NAME) $(INC) $(OBJ) -L$(LIB) -lft
	@echo "${G}make $(NAME)${NC}"

$(DOBJ)/%.o:%.c
	@mkdir -p $(ODIR) 
	@$(GCC) $(INC) -c $< -o $@

e:
	$(CC) -o $(NAME) $(INC) $(LIB) $(SRC) $(FRAMEW)

clean:
	@make clean -C $(LIB)
	@rm -rf $(DOBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB)

re: fclean all
