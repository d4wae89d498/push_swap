SRCS=common1.c common2.c common3.c common4.c stack.c
OBJS=$(SRCS:.c=.o)
CFLAGS=-Wall -Werror -Wextra
DEPS=Makefile common.h solver.h stack.h 
all: solver checker
%.o: %.c $(DEPS)
	cc $(CFLAGS) -c $< -o $@
solver:	$(OBJS)
	cc $(CFLAGS) solver.c $(OBJS) -o solver
checker: $(OBJS)
	cc $(CFLAGS) checker.c $(OBJS) -o checker
clean:
	rm -rf $(OBJS)
fclean:	clean
	rm -rf solver checker
re:	fclean all
