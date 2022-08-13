CFLAGS=-Wall -Werror -Wextra -Iinclude
DEPS=Makefile\
	include/list.h\
	include/common.h\
	include/stack.h\
	include/solver.h
COMMON_SRCS=src/common/instructions/rotate.c\
	src/common/instructions/push.c\
	src/common/instructions/dump.c\
	src/common/instructions/reverse_rotate.c\
	src/common/instructions/swap.c\
	src/common/list.c\
	src/common/stack.c\
	src/common/parser.c
CHECKER_SRCS=src/checker/main.c
SOLVER_SRCS=src/solver/strategies/push_rotate.c\
	src/solver/abstrations/push_at.c\
	src/solver/main.c
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
