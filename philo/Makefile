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
		  ft_isdigit.c \
		  ft_strlen.c \
		  ft_atol.c \
		  t_moni_init.c \
		  err_abort.c \
		  my_mutex_lock.c \
		  my_mutex_unlock.c \
		  forks_create.c \
		  philo.c
		  #arg_seen.c \

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
	$(CC) $(LFLAG) $(OBJS) -o $@

%.o:%.c
	$(CC) $(CFLAG) $< -o $@ -I. 

clean:
	@echo "========= Removing $(NAME)'s objects ============"
	rm -f *.o
	rm -f *.d
	rm -f *.d.*

fclean: clean
	@echo "========= Removing  $(NAME) ============"
	rm $(NAME)

re: fclean all
	@echo "========= Rebuilding $(NAME) ============"

.PHONY: clean fclean re all $(NAME)
