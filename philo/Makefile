NAME		= philo
CC		= gcc
WFLAG		= -Wall -Werror -Wextra
DFLAG		= -g
CFLAG		= $(WFLAG) $(DFLAG) -c
LFLAG		=
HEADER		= philo.h
SRCS		= arg_digi.c \
		  arg_pars.c \
		  arg_rang.c \
		  arg_seen.c \
		  ft_isdigit.c \
		  t_moni_init.c \
		  philo.c

OBJS		= $(SRCS:.c=.o)
DEPE		= $(SRCS:.c=.d)

$(info source files $(SRCS))
$(info object files $(OBJS))

all: $(NAME)
-include $(DEPE)

%.d:%.c
	@set -e; rm -f $@; \
	$(CC) -I. -MM $< > $@.$$$$ ; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f @.$$$$

$(NAME): Makefile $(OBJS)
	$(CC) $(LFLAG) -O $@

%.o:%.c
	$(CC) $(CFLAG) $< -o $@ -I. 


