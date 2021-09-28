############################################################
### Library name

NAME		= libft.a

############################################################
### Variables used by implicit rules

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs

############################################################
### Includes

INCLUDES	= -I./includes

############################################################
### Sources

##### Directries

SRCDIR		= ./srcs/
LIBDIR		= $(SRCDIR)lib/
GNLDIR		= $(SRCDIR)get_next_line/
PRIDIR		= $(SRCDIR)ft_printf/

##### Source files

SRCS		= $(LIBDIR)ft_atoi.c        $(LIBDIR)ft_bzero.c        $(LIBDIR)ft_calloc.c \
			  $(LIBDIR)ft_isalnum.c     $(LIBDIR)ft_isalpha.c      $(LIBDIR)ft_isascii.c \
			  $(LIBDIR)ft_isdigit.c     $(LIBDIR)ft_isprint.c      $(LIBDIR)ft_isspace.c \
			  $(LIBDIR)ft_islower.c     $(LIBDIR)ft_isupper.c      $(LIBDIR)ft_itoa.c \
			  $(LIBDIR)ft_lstadd_back.c $(LIBDIR)ft_lstadd_front.c $(LIBDIR)ft_lstclear.c \
			  $(LIBDIR)ft_lstdelone.c   $(LIBDIR)ft_lstiter.c      $(LIBDIR)ft_lstlast.c \
			  $(LIBDIR)ft_lstmap.c      $(LIBDIR)ft_lstnew.c       $(LIBDIR)ft_lstsize.c \
			  $(LIBDIR)ft_memchr.c      $(LIBDIR)ft_memcmp.c       $(LIBDIR)ft_memcpy.c \
			  $(LIBDIR)ft_memmove.c     $(LIBDIR)ft_memset.c       $(LIBDIR)ft_numlen_base.c \
			  $(LIBDIR)ft_numlen.c      $(LIBDIR)ft_putchar_fd.c   $(LIBDIR)ft_putendl_fd.c \
			  $(LIBDIR)ft_putnbr_base.c $(LIBDIR)ft_putnbr_fd.c    $(LIBDIR)ft_putstr_fd.c \
			  $(LIBDIR)ft_split.c       $(LIBDIR)ft_strchr.c       $(LIBDIR)ft_strdup.c \
			  $(LIBDIR)ft_striteri.c    $(LIBDIR)ft_strjoin.c      $(LIBDIR)ft_strlcat.c \
			  $(LIBDIR)ft_strlcpy.c     $(LIBDIR)ft_strlen.c       $(LIBDIR)ft_strmapi.c \
			  $(LIBDIR)ft_strncmp.c     $(LIBDIR)ft_strndup.c      $(LIBDIR)ft_strnstr.c \
			  $(LIBDIR)ft_strrchr.c     $(LIBDIR)ft_strstr.c       $(LIBDIR)ft_strtrim.c \
			  $(LIBDIR)ft_substr.c      $(LIBDIR)ft_tolower.c      $(LIBDIR)ft_toupper.c \
			  $(LIBDIR)ft_uitoa.c \
			  $(GNLDIR)get_next_line.c  $(GNLDIR)get_next_line_utils.c \
			  $(PRIDIR)ft_printf.c      $(PRIDIR)char.c            $(PRIDIR)str.c \
			  $(PRIDIR)int.c            $(PRIDIR)uint.c            $(PRIDIR)hex.c \
			  $(PRIDIR)ptr.c

##### Object files

OBJS		= $(SRCS:%.c=%.o)

############################################################
### PHONY

.PHONY: all clean fclean re bonus

############################################################
### Rules

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

############################################################
