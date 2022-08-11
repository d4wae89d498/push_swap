all:
	cc *.c
clean:
	rm -rf *.dSYM
fclean:	clean
	rm -rf a.out
