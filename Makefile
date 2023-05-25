# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seocha <seocha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 17:12:00 by seocha            #+#    #+#              #
#    Updated: 2023/05/25 17:16:17 by seocha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minishell

LIBFT_LIBDIR = ./libft
LIBFLAG = -lft -L$(LIBFT_LIBDIR)

SRCS_DIR = ./srcs/

SRCS = 

NEW_SRCS = $(addprefix $(SRCS_DIR), $(SRCS))

OBJS = $(NEW_SRCS:.c=.o)

HEADER = ./includes/minishell.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	make -C ./libft
	$(CC) $(CFLAGS)$(LIBFLAG) $(OBJS) -o $(NAME) -I $(HEADER)
	touch make_mandatory

clean:
	make -C ./libft clean
	rm -f $(OBJS)
	rm -f make_mandatory

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re bonus make_mandatory
