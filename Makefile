SRCS=stack.c list.c parser.c\
common_instructions/dump.c\
common_instructions/reverse_rotate.c\
common_instructions/push.c\
common_instructions/rotate.c
OBJS=$(SRCS:.c=.o)
CFLAGS=-Wall -Werror -Wextra -I.
DEPS=Makefile common.h solver.h stack.h list.h
all: solver checker
%.o: %.c $(DEPS)
	cc $(CFLAGS) -c $< -o $@
solver:	$(OBJS) solver.c
	cc $(CFLAGS) solver.c $(OBJS) -o solver
checker: $(OBJS) checker.c
	cc $(CFLAGS) checker.c $(OBJS) -o checker
clean:
	rm -rf $(OBJS)
fclean:	clean
	rm -rf solver checker
re:	fclean all
