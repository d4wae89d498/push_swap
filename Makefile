SOLVER=solver
CHECKER=checker
CFLAGS=-Wall -Werror -Wextra #-g
DEPS=Makefile

all: $(SOLVER) $(CHECKER)

stack.o: stack.c stack.h $(DEPS)
	cc $(CFLAGS) -c stack.c -o stack.o

$(SOLVER): stack.o
	cc $(CFLAGS) solver.c stack.o -o $(SOLVER)

$(CHECKER): stack.o
	cc $(CFLAGS) checker.c stack.o -o $(SOLVER)

clean:
	rm stack.o

fclean:	clean
	rm $(SOLVER) $(CHECKER)

re:	fclean all
