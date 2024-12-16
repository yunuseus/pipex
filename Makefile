
PROG = pipex


SRCS = needed_func.c pipex.c 
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = #-Wall -Wextra -Werror
RM = rm -f

$(PROG): $(OBJS)
		@make -C libft
		@$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(PROG)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(PROG)

clean:
	@make clean -C libft
	$(RM) $(OBJS)
	

fclean: clean
	$(RM) $(PROG)
	make fclean -C libft

re:
	fclean all


.PHONY: all clean fclean re