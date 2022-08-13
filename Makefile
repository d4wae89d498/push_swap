CFLAGS=-Wall -Werror -Wextra -I.
DEPS=Makefile\
	list.h\
	common.h\
	stack.h\
	solver.h
COMMON_SRCS=instructions/rotate.c\
	instructions/push.c\
	instructions/dump.c\
	instructions/reverse_rotate.c\
	instructions/swap.c\
	list.c\
	stack.c\
	parser.c
CHECKER_SRCS=checker.c
SOLVER_SRCS=strategies/push_rotate.c\
	abstrations/push_at.c\
	solver.c
COMMON_OBJS=$(COMMON_SRCS:.c=.o)
CHECKER_OBJS=$(CHECKER_SRCS:.c=.o)
SOLVER_OBJS=$(SOLVER_SRCS:.c=.o)
all: solver checker
%.o: %.c $(DEPS)
	cc $(CFLAGS) -c $< -o $@
solver:	$(COMMON_OBJS) $(SOLVER_SRCS)
	cc $(CFLAGS) $(COMMON_OBJS) $(SOLVER_SRCS) -o $@
checker: $(COMMON_OBJS) $(CHECKER_OBJS)
	cc $(CFLAGS) $(COMMON_OBJS) $(CHECKER_OBJS) -o $@
clean:
	rm -rf $(COMMON_OBJS) $(SOLVER_OBJS) $(CHECKER_OBJS)
fclean:	clean
	rm -f solver checker
re:	fclean all
