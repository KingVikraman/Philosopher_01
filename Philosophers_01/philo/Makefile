# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvikrama <rvikrama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 18:42:29 by rvikrama          #+#    #+#              #
#    Updated: 2025/04/04 21:11:46 by rvikrama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Generics 
.PHONY: all clean fclean re

# Compilers.

CC 				= cc
CFLAGS 			= $(COMP)  -I$(INC_DIR) #$(DEBUGS) $(THREAD_DEBUG) 
COMP			= -Wall -Werror -Wextra
DEBUGS			= -g3
THREAD_DEBUG	= -fsanitize=thread
MEMORY_DEBUG	= -fsanitize=memory
ADDRESS_DEBUG	= -fsanitize=address
RM				= rm -rf
THREAD_FLAG	    = -pthread


NAME 		= philo


INC_DIR		= includes/
OBJS_DIR	= bin/
SRCS_DIR	= Sources/


SRCS_FILES	=	Sources/error.c	\
				Sources/init.c	\
				Sources/main.c	\
				Sources/parsing.c\
				Sources/routines.c\

OBJS_FILES	=	$(patsubst %.c, $(OBJS_DIR)%.o ,$(SRCS_FILES))
#patsubst → A Makefile function that does pattern substitution.

all: $(NAME)

$(NAME): $(OBJS_FILES)
		$(CC) $(CFLAGS) $(OBJS_FILES) -o $(NAME)

$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)$(SRCS_DIR)

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean $(OBJS_DIR) all



