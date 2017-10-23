# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/19 22:17:21 by vpluchar          #+#    #+#              #
#    Updated: 2017/10/23 21:26:57 by vpluchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Name

NAME	=	fdf

## Compilation
CC		=	gcc $(FLAGS)
FLAGS	=	-Wall -Wextra -Werror
INC		=	-I./inc -I./libft/includes
FRAMEW	=	-I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit

## git pull && gcc -Wall -Wextra -Werror -I./inc libft/libft.a -I./libft/includes src/*c -I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit

## Directories

INC_D	= 	-I inc
SRC_D	=	src
OBJ_D	= 	obj

## Colors

R		=	\x1b[31m
G		=	\x1b[32m
Y		=	\x1b[33m
NC		=	\x1b[0m

## Files

LIB		=	libft/libft.a

OBJ		=	$(addprefix $(OBJ_D)/, $(SRC: .c=.o))

SRC		=	src/clr.c\
			src/fdf.c\
			src/init.c\
			src/key.c\
			src/map.c\
			src/print.c

## Utils


## Rules

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${Y}create $(NAME)${NC}"
	$(CC) -o $(NAME) $(FRAMEW) $(OBJ)
	@echo "${G}$(NAME) created${NC}"

$(OBJ_D)/%.o: ./src/%.c
	@mkdir -p $(OBJ_D)
	@echo "${G}[OK]${NC}	${Y}Compiling:${NC}" $<
	$(CC) -c $< -o $@

e:
	$(CC) -o $(NAME) $(INC) $(LIB) $(SRC) $(FRAMEW)

clean: 
	@rm -rf $(OBJ_D)
	@echo "${R}objects deleted${NC}"

fclean : clean
	@rm -f $(NAME)
	@echo "${Y}$(NAME) ${R}deleted${NC}"

re: fclean all
