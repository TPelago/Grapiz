#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpelago <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/28 12:50:46 by tpelago           #+#    #+#              #
#    Updated: 2016/04/01 16:27:46 by tpelago          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	= 	grapiz

CC		= 	gcc

CFLAGS  =	-Wall -Wextra -Werror

LIBDIR 	=	/nfs/2013/t/tpelago/lib

LIBDIR2 =   /nfs/2013/t/tpelago/include

LIBDIR3 =	./includes/

SRCS 	=	srcs/sdl.c \
			srcs/colours.c \
			srcs/directions.c \
			srcs/grapiz.c \
			srcs/play.c \
			srcs/coord.c \
			srcs/sprites.c \
			srcs/ft_strequ.c \

OBJ 	=	$(SRCS:.c=.o)

LIBINC	=	-L$(LIBDIR) 

LIBINC2 =   -I$(LIBDIR2) -I$(LIBDIR3)

LIBINC3 = -lSDL2

all:		$(NAME)

$(NAME):	$(OBJ)
			@echo "test"
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBINC) $(LIBINC2) $(LIBINC3)
			@echo "\033[32m[build $(NAME)] --- created\033[0m"

%.o:		%.c
			@echo "\033[36m[ofile] \033[0m" | tr -d '\n'
			$(CC) $(CFLAGS) $(LIBINC2) -o $@ -c $<

clean:		
			@echo "\033[31m[clean $(NAME)] \033[0m" | tr -d '\n'
			rm -rf $(OBJ)

fclean:		clean
			@echo "\033[31m[fclean $(NAME)] \033[0m" | tr -d '\n'
			rm -rf $(NAME)

re:			fclean all
