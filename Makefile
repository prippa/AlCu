# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prippa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:20:39 by prippa            #+#    #+#              #
#    Updated: 2018/01/15 14:29:46 by prippa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	alum1

FLAGS		= 	-Wall -Werror -Wextra

CC			=	gcc

DIR_LIB		=	./libft/
LIBFT		=	$(DIR_LIB)libft.a
DIR_LIB_INC	=	$(DIR_LIB)includes/
DIR_ALU_INC	=	./includes/
DIR_ALU		=	./source/
DIR_OBJ		= 	./obj/

HEAD_ALU	=	alum1.h

C_ALU		=	main.c al_stack_push_pop.c al_stack_revers.c\
				al_parser.c al_free.c al_init.c\
				al_print.c al_the_game.c al_valid.c\
				al_ai_logic.c


OBJ_ALU 	= 	$(C_ALU:.c=.o)
OBJ			= 	$(addprefix $(DIR_OBJ), $(OBJ_ALU))
INC 		= 	$(addprefix -I, $(DIR_ALU_INC) $(DIR_LIB_INC))
INC_ALU 	= 	$(addprefix $(DIR_ALU_INC), $(HEAD_ALU))

all: lib obj $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

lib:
	@make -C $(DIR_LIB)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "Compiling" [ $(NAME) ]

$(DIR_OBJ)%.o: $(DIR_ALU)%.c $(INC_ALU)
	@$(CC) $(FLAGS) $(INC) -c -o $@ $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files alum1 ]"
	@make -C $(DIR_LIB) clean

fclean:
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files alum1 ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]
	@make -C $(DIR_LIB) fclean

re: fclean all

.PHONY: all clean fclean re 
