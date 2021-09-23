############################################################
### Library name

NAME		= pipex

############################################################
### Variables used by implicit rules

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

############################################################
### Includes

INCLUDES	= -I./includes

############################################################
### Sources
##### Directories

SRCDIR		= ./srcs/

##### Source files

SRCS		= $(SRCDIR)pipex.c \
			  $(SRCDIR)exec.c \
			  $(SRCDIR)error.c \
			  $(SRCDIR)utils.c

##### Object files

OBJS		= $(SRCS:.c=.o)

############################################################
### Library

LIBFTPATH	= ./libft/
LIBFTMAKE	= $(MAKE) -C $(LIBFTPATH)
LIBFT		= -L$(LIBFTPATH) -lft

############################################################

.PHONY: all clean fclean re bonus

############################################################
### Rules

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(LIBFTMAKE)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(LIBFTMAKE) clean
	$(RM) $(OBJS)

fclean: clean
	$(LIBFTMAKE) fclean
	$(RM) $(NAME)

re: fclean all

############################################################
