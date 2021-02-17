upo_sort: main.o upo_sort.o
	gcc -o upo_sort main.o upo_sort.o
	$(RM) *.o
main.o: main.c upo_sort.h
	gcc -c main.c
upo_sort.o: upo_sort.c upo_sort.h
	gcc -c upo_sort.c