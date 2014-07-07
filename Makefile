##
## Makefile for test in /home/tang_j/malloc
##
## Made by Jean Luc TANG
## Login   <tang_j@epitech.net>
##
## Started on  Mon Jan 27 16:22:36 2014 Jean Luc TANG
## Last update Thu Feb 13 14:27:04 2014 ilyas zelloufi
##

CC	= gcc

RM	= rm -f

LIB	= libmy_malloc.so

NAME	= libmy_malloc_$(HOSTTYPE).so

CFLAGS  += -Wall -Werror -Wextra
CFLAGS  += -fPIC

LDFLAGS += -shared -Wl,-soname,$(NAME)

SRCS	= malloc.c \
	  free.c \
	  realloc.c \
	  show_alloc_mem.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)
	ln -s $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(LIB) $(NAME)

re: fclean all

.PHONY: all clean fclean re
