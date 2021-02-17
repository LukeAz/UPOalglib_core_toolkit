## UPOalglib_core_toolkit
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup and run](#setup-and-run)

## General info
This project was developed in 2015 by Marco Guazzone and includes exercises to be completed for the lab portion of the course.
It includes algorithms in C regarding stack, data sorting, binary search trees, and hash tables.

## Technologies
Project includes:
* Stack exercises
* Postfix eval with stack
* Sorting exercises
* Sorting compare and test
* Binary search trees
* Hash tables
* More exercises
	
## Setup and run
To run this project, install it locally:

```
$ git clone https://github.com/LukeAz/UPOalglib_core_toolkit.git
$ cd UPOalglib_core_toolkit
```

To compile and execute:
* Stack exercises
```
$ make clean bin
$ make clean test
$ ./test/test_stack
$ valgrind --tool=memcheck --leak-check=full ./test/test_stack
```

* Postfix eval with stack
```
$ make clean apps
$ ./apps/postfix_eval -f data/postfix.txt
$ valgrind --tool=memcheck --leak-check=full ./apps/postfix_eval -f data/postfix.txt
```

* Sorting exercises
```
$ make clean bin
$ make clean test
$ ./test/test_sort
$ valgrind --tool=memcheck --leak-check=full ./test/test_sort
```

* Sorting compare and test
```
$ make clean apps
$ ./apps/sort_compare -h
$ ./apps/sort_compare -a insertion -a merge -a quick -a stdc -n 10000 -r 3 -s 5489
$ ./apps/sort_playlist_multi -i data/playlist_multi.txt -s year -s artist -s album
$ ./apps/sort_playlist_multi -i data/playlist_multi.txt -s artist -s year -s album
$ ./apps/sort_playlist_multi -i data/playlist_multi.txt -s artist -s album -s year
```

* Binary search trees
```
$ make clean bin
$ make clean test
$ ./test/test_bst
$ valgrind --tool=memcheck --leak-check=full ./test/test_bst
$ ./test/test_bst_more
$ valgrind --tool=memcheck --leak-check=full ./test/test_bst_more
```

* Hash tables
```
$ make clean bin
$ make clean test
$ ./test/test_hashtable_sepchain
$ valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_sepchain
$ ./test/test_hashtable_linprob
$ valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_linprob
$ ./test/test_hashtable_sepchain_more
$ valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_sepchain_more
$ ./test/test_hashtable_linprob_more
$ valgrind --tool=memcheck --leak-check=full ./test/test_hashtable_linprob_more
```

* More exercises
```
$ cd more_exercises
$ ls
```

* Advanced Pointer (more exercises)
```
$ cd more_exercises
$ cd advanced_pointer
$ make
$ ./advanced_pointer
```

* Upo queue (more exercises)
```
$ cd more_exercises
$ cd upo_queue_t
$ make
$ ./upo_queue
```
