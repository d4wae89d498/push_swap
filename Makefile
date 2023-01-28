CFLAGS=-Wall -Werror -Wextra -I. -DLOG=1 # -g
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
	strategies/split_swap.c\
	strategies/quick_sort.c\
	strategies/bool_tree.c\
	strategies/radix.c\
	\
	abstractions/cmp.c\
	abstractions/sort_tree.c\
	abstractions/sort_five.c\
	abstractions/push_at.c\
	abstractions/swap_at.c\
	abstractions/score_sort.c\
	abstractions/insertion_sort.c\
	abstractions/order_sort.c\
	abstractions/bubble_sort.c\
	\
	abstractions/pyramid.c\
	solver.c
COMMON_OBJS=$(COMMON_SRCS:.c=.o)
CHECKER_OBJS=$(CHECKER_SRCS:.c=.o)
SOLVER_OBJS=$(SOLVER_SRCS:.c=.o)
SOLVER=push_swap
CHECKER=checker
all: $(SOLVER) $(CHECKER)
%.o: %.c $(DEPS)
	cc $(CFLAGS) -c $< -o $@
$(SOLVER): $(COMMON_OBJS) $(SOLVER_SRCS)
	cc $(CFLAGS) $(COMMON_OBJS) $(SOLVER_SRCS) -o $@
$(CHECKER): $(COMMON_OBJS) $(CHECKER_OBJS)
	cc $(CFLAGS) $(COMMON_OBJS) $(CHECKER_OBJS) -o $@
test:
	./Arktest_Push_Swap/arktest.sh
clean:
	rm -rf $(COMMON_OBJS) $(SOLVER_OBJS) $(CHECKER_OBJS)
fclean:	clean
	rm -f $(SOLVER) $(CHECKER)
re:	fclean all
