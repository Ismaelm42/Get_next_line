# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 12:09:39 by imoro-sa          #+#    #+#              #
#    Updated: 2023/01/23 11:27:47 by imoro-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c	get_next_line_utils.c	main.c

OBJT = $(SRC:.c=.o)

CCFLAGS = cc -Wall -Werror -Wextra 

BFLAGS = -D BUFFER_SIZE=42

AR = ar rcs

RM = rm -f

COLOUR_END = \033[0m
COLOUR = \033[0;96m

all: $(NAME)

$(NAME): $(OBJT)
	@$(CCFLAGS)$(BFLAG)$(SRC)
	@$(AR) $(NAME) $(OBJT)
	@echo "$(COLOUR)get_next_line.a compiled!$(COLOUR_END)"

clean:
	@$(RM) $(OBJT)
	@echo "$(COLOUR)*.o cleaned$(COLOUR_END)"

fclean:
	@make clean
	@$(RM) $(NAME)
	@echo "$(COLOUR)*.o and *.a cleaned$(COLOUR_END)"

re:
	@make fclean all clean
	@echo "$(COLOUR)all rebuilt and .o cleaned!$(COLOUR_END)"

.PHONY : all clean fclean re
