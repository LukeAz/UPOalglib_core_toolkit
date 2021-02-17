upo_queue: upo_main.o upo_queue.o
	gcc -o upo_queue upo_main.o upo_queue.o
	$(RM) *.o
upo_main.o: upo_main.c upo_queue.h
	gcc -c upo_main.c
upo_queue.o: upo_queue.c upo_queue.h
	gcc -c upo_queue.c