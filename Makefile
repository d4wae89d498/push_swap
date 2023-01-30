CFLAGS=-Wall -Werror -Wextra -I. -DLOG=0#  -g
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
	stack_utils.c\
	parser.c
CHECKER_SRCS=checker.c
SOLVER_SRCS=\
	strategies/split_swap.c\
	strategies/split_swap_utils.c\
	strategies/radix.c\
	strategies/bool_tree.c\
	strategies/bool_tree_output.c\
	strategies/bool_tree_utils.c\
	\
	abstractions/cmp.c\
	abstractions/insertion_sort.c\
	abstractions/set_index.c\
	\
	solver.c
COMMON_OBJS=$(COMMON_SRCS:.c=.o)
SOLVER_OBJS=$(SOLVER_SRCS:.c=.o)
SOLVER=push_swap
all: $(SOLVER) $(CHECKER)
%.o: %.c $(DEPS)
	cc $(CFLAGS) -c $< -o $@
$(SOLVER): $(COMMON_OBJS) $(SOLVER_SRCS)
	cc $(CFLAGS) $(COMMON_OBJS) $(SOLVER_SRCS) -o $@
test:
	./Arktest_Push_Swap/arktest.sh
clean:
	rm -rf $(COMMON_OBJS) $(SOLVER_OBJS) $(CHECKER_OBJS)
fclean:	clean
	rm -f $(SOLVER)
re:	fclean all
