# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouljih <nbouljih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 16:54:18 by nbouljih          #+#    #+#              #
#    Updated: 2023/01/23 00:34:41 by nbouljih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = CC
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

GREEN		=	\e[92;5;118m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

SRC =	death_check.c fill_info.c init.c \
		main.c start.c utils.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(philo.h)
	@ $(CC) $(CFLAGS) $^ -o $(NAME)
	@printf "$(GREEN) - Philosoher is ready.\n$(RESET)"

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@ $(RM) $(OBJ) 
	@printf "$(CURSIVE)$(GRAY)	- Removing .o files ... $(RESET)\n"
	@printf "$(GREEN)    - .o files removed.$(RESET)\n"
fclean: clean
	@ $(RM) $(NAME) 
	@printf "$(CURSIVE)$(GRAY)	- Removing $(NAME)... $(RESET)\n"
	@printf "$(GREEN)    - Executable removed.$(RESET)\n"
re: fclean all

.PHONY: all clean fclean re