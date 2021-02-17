upo_bst: upo_bst_main.o upo_bst.o
	gcc -o upo_bst upo_bst_main.o upo_bst.o
	$(RM) *.o
upo_bst_main.o: upo_bst_main.c upo_bst.h
	gcc -c upo_bst_main.c
upo_bst.o: upo_bst.c upo_bst.h
	gcc -c upo_bst.c