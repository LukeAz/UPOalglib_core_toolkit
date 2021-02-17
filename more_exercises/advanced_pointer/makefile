advanced_pointer: main.o advanced_pointer.o
	gcc -o advanced_pointer main.o advanced_pointer.o
	$(RM) *.o
main.o: main.c advanced_pointer.h
	gcc -c main.c
advanced_pointer.o: advanced_pointer.c advanced_pointer.h
	gcc -c advanced_pointer.c