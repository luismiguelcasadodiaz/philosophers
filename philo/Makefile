NAME		= philo
CC			= gcc
WFLAG		= -Wall -Werror -Wextra
DFLAG		= -g -fsanitize=thread
DFLAG		= -g -fsanitize=address
#DFLAG		= 
CFLAG		= $(WFLAG) $(DFLAG) -c
LFLAG		= -fsanitize=thread -lpthread
LFLAG		= -fsanitize=address 
#LFLAG		= 
HEADER		= philo.h
SRCS		= arg_digi.c \
		  arg_pars.c \
		  arg_rang.c \
		  ft_isdigit.c \
		  ft_strlen.c \
		  ft_atol.c \
		  ft_itoa.c \
		  ft_ltoa.c \
		  my_long.c \
		  my_now_ms.c \
		  t_moni_init.c \
		  my_mutex_lock.c \
		  my_mutex_unlock.c \
		  my_thread_create.c \
		  my_thread_detach.c \
		  my_thread_join.c \
		  forks_create.c \
		  forks_free.c \
		  threads_create.c \
		  threads_free.c \
		  philo_creation.c \
		  philo_thread.c \
		  philo_msg.c \
		  philo.c
		  #arg_seen.c \

OBJS		= $(SRCS:.c=.o)
DEPE		= $(SRCS:.c=.d)

$(info source files $(SRCS))
$(info object files $(OBJS))

all: $(NAME)
	bash -c "sudo sysctl vm.mmap_rnd_bits=28"
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
