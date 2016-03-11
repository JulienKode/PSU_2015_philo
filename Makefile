##
## Makefile for  in /home/karst_j/PSU_2015_philo
##
## Made by Julien Karst
## Login   <karst_j@epitech.net>
##
## Started on  Tue Mar  1 09:05:28 2016 Julien Karst
## Last update Fri Mar 11 09:45:42 2016 Julien Karst
##

$(info ************  PSU_2015_philo ************)

NAME	= philo

CC		= gcc

CFLAGS	= -I./includes  -g -Ofast -Wall -Wextra

SRC	= 	sources/main.c		\
		sources/philo.c 	\
		sources/list.c 		\
		sources/sem.c 		\
		sources/action.c	\
		sources/state.c

OBJ	= $(SRC:.c=.o)

LDFLAGS	= -lpthread -L./lib -lriceferee -L./lib -lmy

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)  $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
