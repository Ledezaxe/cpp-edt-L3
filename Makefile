##
## Makefile for  in /home/ledezaxe/cpp
## 
## Made by ledezaxe
## Login   <quentin.rouanet@etudiant.univ-lr.fr>
## 
## Started on  Thu Nov  3 13:48:21 2016 Quentin Rouanet
## Last update Wed Nov  9 18:12:39 2016 Rouanet Quentin
##

NAME	= edt

SRCS	= main.cpp \
	  Horaire.cpp \
	  Dicipline.cpp \
	  Student.cpp

OBJ	= $(SRCS:.cpp=.o)

CC	= g++

RM	= rm -f

ECHO	= @echo -e

CPPFLAGS	+= -W -Wall -Wextra
CPPFLAGS	+= -Werror
CPPFLAGS	+= -std=c++11 ## le bon flag pour le bon cpp 11

all	: $(NAME)

$(NAME)	: $(OBJ)
	  $(CC) -o $(NAME) $(OBJ)
	  $(ECHO) '\033[0;32m> Compiled\033[0m'

clean	:
	  $(RM) $(OBJ)
	  $(RM) *~
	  $(RM) \#*#
	  $(ECHO) '\033[0;31m> Directory cleaned\033[0m'

fclean	: clean
	  $(RM) $(NAME)
	  $(ECHO) '\033[0;31m> Remove executable\033[0m'

re	: fclean all

.PHONY	: all clean fclean re

