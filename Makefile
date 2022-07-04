SOLVER=solver
CHECKER=checker
ARG_MAX=$(shell getconf ARG_MAX)
CFLAGS=-DARG_MAX=$(ARG_MAX) -Wall -Werror -Wextra #-g
DEPS=Makefile

all: $(SOLVER) $(CHECKER)

%.o: %.c $(DEPS)
	cc $(CFLAGS) -c $< -o $@

stack.o: stack.c stack.h

common_push.o: common.h common_push.c stack.o
	
common_swap.o: common.h common_swap.c stack.o

common_rotate.o: common.h common_rotate.c stack.o

common_reverse_rotate.o: common.h common_reverse_rotate.c stack.o

common.o: common.h stack.o common_push.o common_swap.o common_rotate.o common_rotate.o common_reverse_rotate.o


$(SOLVER): stack.o common.o
	cc $(CFLAGS) solver.c stack.o -o $(SOLVER)

$(CHECKER): stack.o common.o
	cc $(CFLAGS) checker.c stack.o -o $(CHECKER)

clean:
	rm -rf stack.o common.o common_push.o common_swap.o common_rotate.o common_reverse_rotate.o

fclean:	clean
	rm -rf $(SOLVER) $(CHECKER)

re:	fclean all
